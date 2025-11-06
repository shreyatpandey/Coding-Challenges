#include "single_hw_timer.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Timer node structure for linked list
 * Each node represents a pending software timer
 */
typedef struct TimerNode {
    uint64_t expiry_time;           // Absolute expiry time in ticks
    callback_fn_t callback;         // Callback function to invoke
    struct TimerNode* next;         // Next node in linked list
} TimerNode;

// Global state
static TimerNode* timer_list_head = NULL;  // Head of sorted timer list
static uint64_t current_ticks = 0;         // Current system ticks (incremented by HW timer)
static uint32_t hw_tick_period_ms = 1;     // Hardware timer period in milliseconds
static uint64_t next_hw_timer_expiry = 0;  // When the HW timer should fire next

/**
 * Insert a timer node into the sorted list (sorted by expiry_time)
 * 
 * @param node Timer node to insert
 */
static void insert_timer_sorted(TimerNode* node) {
    if (!node) return;

    // Empty list - insert as head
    if (timer_list_head == NULL) {
        timer_list_head = node;
        node->next = NULL;
        return;
    }

    // Insert before head if this expires earlier
    if (node->expiry_time < timer_list_head->expiry_time) {
        node->next = timer_list_head;
        timer_list_head = node;
        return;
    }

    // Find insertion point in sorted list
    TimerNode* current = timer_list_head;
    while (current->next != NULL && current->next->expiry_time <= node->expiry_time) {
        current = current->next;
    }

    // Insert after current
    node->next = current->next;
    current->next = node;
}

/**
 * Remove and return the first timer from the list
 * 
 * @return Pointer to the removed timer node, or NULL if list is empty
 */
static TimerNode* remove_first_timer(void) {
    if (timer_list_head == NULL) {
        return NULL;
    }

    TimerNode* node = timer_list_head;
    timer_list_head = timer_list_head->next;
    node->next = NULL;
    return node;
}

/**
 * Program the hardware timer to fire at a specific time
 * 
 * In a real embedded system, this would configure the hardware timer registers.
 * For this implementation, we just store when it should fire.
 * 
 * @param ticks_from_now Number of ticks from now when the timer should fire
 */
static void program_hw_timer(uint64_t ticks_from_now) {
    next_hw_timer_expiry = current_ticks + ticks_from_now;
    
    // In real hardware, you would write to timer registers here
    // For example:
    // TIMER_LOAD_REG = ticks_from_now * hw_tick_period_ms;
    // TIMER_CONTROL_REG |= TIMER_ENABLE_BIT;
    
    #ifdef DEBUG
    printf("[HW Timer] Programmed to fire in %llu ticks (at tick %llu)\n", 
           ticks_from_now, next_hw_timer_expiry);
    #endif
}

/**
 * Stop the hardware timer
 */
static void stop_hw_timer(void) {
    next_hw_timer_expiry = UINT64_MAX;
    
    // In real hardware, you would disable the timer here
    // For example:
    // TIMER_CONTROL_REG &= ~TIMER_ENABLE_BIT;
    
    #ifdef DEBUG
    printf("[HW Timer] Stopped\n");
    #endif
}

void timer_system_init(uint32_t hw_timer_tick_ms) {
    timer_list_head = NULL;
    current_ticks = 0;
    hw_tick_period_ms = (hw_timer_tick_ms > 0) ? hw_timer_tick_ms : 1;
    next_hw_timer_expiry = UINT64_MAX;
    
    #ifdef DEBUG
    printf("[Timer System] Initialized with HW tick period: %u ms\n", hw_tick_period_ms);
    #endif
}

int requestCallback(uint64_t interval_ms, void (*callbackFn)(void)) {
    if (callbackFn == NULL) {
        fprintf(stderr, "[Error] Callback function cannot be NULL\n");
        return -1;
    }

    if (interval_ms == 0) {
        fprintf(stderr, "[Error] Timer interval must be greater than 0\n");
        return -1;
    }

    // Allocate new timer node
    TimerNode* new_timer = (TimerNode*)malloc(sizeof(TimerNode));
    if (new_timer == NULL) {
        fprintf(stderr, "[Error] Failed to allocate memory for timer\n");
        return -1;
    }

    // Calculate expiry time in ticks
    uint64_t interval_ticks = interval_ms / hw_tick_period_ms;
    if (interval_ticks == 0) {
        interval_ticks = 1; // At least 1 tick
    }

    new_timer->expiry_time = current_ticks + interval_ticks;
    new_timer->callback = callbackFn;
    new_timer->next = NULL;

    #ifdef DEBUG
    printf("[Request] Timer requested: interval=%llu ms (%llu ticks), expiry=%llu\n",
           interval_ms, interval_ticks, new_timer->expiry_time);
    #endif

    // Insert into sorted list
    insert_timer_sorted(new_timer);

    // If this is now the earliest timer, reprogram hardware timer
    if (timer_list_head == new_timer) {
        uint64_t ticks_until_expiry = new_timer->expiry_time - current_ticks;
        if (ticks_until_expiry == 0) {
            ticks_until_expiry = 1; // Fire on next tick
        }
        program_hw_timer(ticks_until_expiry);
    }

    return 0;
}

void HwTimerExpire(void) {
    // Increment system tick counter
    current_ticks++;

    #ifdef DEBUG
    printf("\n[HW Timer ISR] Fired at tick %llu\n", current_ticks);
    #endif

    // Process all expired timers
    while (timer_list_head != NULL && timer_list_head->expiry_time <= current_ticks) {
        // Remove expired timer from list
        TimerNode* expired = remove_first_timer();

        #ifdef DEBUG
        printf("[Timer Expired] Tick %llu - Invoking callback\n", current_ticks);
        #endif

        // Invoke the callback
        if (expired->callback != NULL) {
            expired->callback();
        }

        // Free the timer node
        free(expired);
    }

    // Program hardware timer for next expiration (if any timers remain)
    if (timer_list_head != NULL) {
        uint64_t ticks_until_next = timer_list_head->expiry_time - current_ticks;
        
        // Handle case where expiry is in the past or now (shouldn't happen, but defensive)
        if (ticks_until_next == 0) {
            ticks_until_next = 1;
        }
        
        program_hw_timer(ticks_until_next);
    } else {
        // No more timers - stop hardware timer
        stop_hw_timer();
        
        #ifdef DEBUG
        printf("[Timer List] Empty - HW timer stopped\n");
        #endif
    }
}

void timer_system_cleanup(void) {
    // Free all pending timers
    while (timer_list_head != NULL) {
        TimerNode* node = remove_first_timer();
        free(node);
    }

    current_ticks = 0;
    next_hw_timer_expiry = UINT64_MAX;

    #ifdef DEBUG
    printf("[Timer System] Cleaned up\n");
    #endif
}

int get_active_timer_count(void) {
    int count = 0;
    TimerNode* current = timer_list_head;
    
    while (current != NULL) {
        count++;
        current = current->next;
    }
    
    return count;
}

/**
 * Debug function to print all active timers
 */
#ifdef DEBUG
void print_timer_list(void) {
    printf("\n[Timer List] Current tick: %llu\n", current_ticks);
    
    if (timer_list_head == NULL) {
        printf("  (empty)\n");
        return;
    }

    TimerNode* current = timer_list_head;
    int index = 0;
    
    while (current != NULL) {
        printf("  [%d] Expiry: %llu (in %lld ticks)\n", 
               index++, 
               current->expiry_time,
               (int64_t)(current->expiry_time - current_ticks));
        current = current->next;
    }
}
#endif
