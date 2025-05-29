#include "timer.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Timer structure
struct Timer {
    uint32_t interval_ms;        // Timer interval in milliseconds
    timer_mode_t mode;           // Timer mode (one-shot or periodic)
    timer_callback_t callback;   // Callback function
    void* user_data;            // User data to pass to callback
    bool active;                // Whether timer is currently running
    uint64_t next_expiry;       // Next expiry time in milliseconds
    struct Timer* next;         // Next timer in linked list
};

// Global variables
static struct Timer* timer_list = NULL;  // List of all timers
static uint64_t current_time_ms = 0;     // Current time in milliseconds

// Get current time in milliseconds
static uint64_t get_current_time_ms(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (uint64_t)(ts.tv_sec * 1000 + ts.tv_nsec / 1000000);
}

void timer_init(void) {
    timer_list = NULL;
    current_time_ms = get_current_time_ms();
}

timer_handle_t timer_create(uint32_t interval_ms, 
                          timer_mode_t mode,
                          timer_callback_t callback,
                          void* user_data) {
    if (!callback || interval_ms == 0) {
        return NULL;
    }

    struct Timer* timer = (struct Timer*)malloc(sizeof(struct Timer));
    if (!timer) {
        return NULL;
    }

    timer->interval_ms = interval_ms;
    timer->mode = mode;
    timer->callback = callback;
    timer->user_data = user_data;
    timer->active = false;
    timer->next_expiry = 0;
    timer->next = NULL;

    // Add to list
    timer->next = timer_list;
    timer_list = timer;

    return timer;
}

bool timer_start(timer_handle_t timer) {
    if (!timer) {
        return false;
    }

    timer->active = true;
    timer->next_expiry = get_current_time_ms() + timer->interval_ms;
    return true;
}

bool timer_stop(timer_handle_t timer) {
    if (!timer) {
        return false;
    }

    timer->active = false;
    return true;
}

bool timer_delete(timer_handle_t timer) {
    if (!timer) {
        return false;
    }

    // Find and remove from list
    struct Timer** pp = &timer_list;
    while (*pp && *pp != timer) {
        pp = &((*pp)->next);
    }

    if (*pp) {
        *pp = timer->next;
        free(timer);
        return true;
    }

    return false;
}

void timer_process(void) {
    current_time_ms = get_current_time_ms();
    struct Timer* timer = timer_list;

    while (timer) {
        if (timer->active && current_time_ms >= timer->next_expiry) {
            // Timer expired, call callback
            timer->callback(timer->user_data);

            if (timer->mode == TIMER_MODE_PERIODIC) {
                // Schedule next expiry for periodic timer
                timer->next_expiry = current_time_ms + timer->interval_ms;
            } else {
                // Stop one-shot timer
                timer->active = false;
            }
        }
        timer = timer->next;
    }
}

void timer_cleanup(void) {
    // Free all timers
    while (timer_list) {
        struct Timer* next = timer_list->next;
        free(timer_list);
        timer_list = next;
    }
}
