#include "timer.h"
#include <stdio.h>
#include <unistd.h>

// Callback function for periodic timer
void periodic_callback(void* user_data) {
    int* counter = (int*)user_data;
    printf("Periodic timer fired! Counter: %d\n", (*counter)++);
}

// Callback function for one-shot timer
void oneshot_callback(void* user_data) {
    printf("One-shot timer fired! Message: %s\n", (const char*)user_data);
}

int main() {
    // Initialize timer library
    timer_init();

    // Create counters for periodic timer
    int counter = 0;

    // Create a periodic timer that fires every 1000ms (1 second)
    timer_handle_t periodic_timer = timer_create(1000, 
                                               TIMER_MODE_PERIODIC,
                                               periodic_callback,
                                               &counter);

    // Create a one-shot timer that fires after 5000ms (5 seconds)
    const char* message = "Hello from one-shot timer!";
    timer_handle_t oneshot_timer = timer_create(5000,
                                              TIMER_MODE_ONESHOT,
                                              oneshot_callback,
                                              (void*)message);

    if (!periodic_timer || !oneshot_timer) {
        printf("Failed to create timers!\n");
        return 1;
    }

    // Start both timers
    timer_start(periodic_timer);
    timer_start(oneshot_timer);

    printf("Timers started. Running for 10 seconds...\n");

    // Main loop - process timers for 10 seconds
    for (int i = 0; i < 10; i++) {
        timer_process();  // Process timer events
        usleep(100000);   // Sleep for 100ms
    }

    // Clean up
    timer_delete(periodic_timer);
    timer_delete(oneshot_timer);
    timer_cleanup();

    return 0;
}
