#ifndef TIMER_H
#define TIMER_H

#include <stdbool.h>
#include <stdint.h>

// Timer callback function type
typedef void (*timer_callback_t)(void* user_data);

// Timer handle type (opaque pointer)
typedef struct Timer* timer_handle_t;

// Timer modes
typedef enum {
    TIMER_MODE_ONESHOT,  // Timer triggers once
    TIMER_MODE_PERIODIC  // Timer triggers periodically
} timer_mode_t;

// Initialize the timer library
void timer_init(void);

// Create a new timer
// interval_ms: interval in milliseconds
// mode: TIMER_MODE_ONESHOT or TIMER_MODE_PERIODIC
// callback: function to call when timer expires
// user_data: pointer to pass to callback function
// Returns: handle to the timer, or NULL if creation failed
timer_handle_t timer_create(uint32_t interval_ms, 
                          timer_mode_t mode,
                          timer_callback_t callback,
                          void* user_data);

// Start a timer
// Returns true if successful, false otherwise
bool timer_start(timer_handle_t timer);

// Stop a timer
// Returns true if successful, false otherwise
bool timer_stop(timer_handle_t timer);

// Delete a timer and free its resources
// Returns true if successful, false otherwise
bool timer_delete(timer_handle_t timer);

// Process timer events
// This function should be called periodically from the main loop
void timer_process(void);

// Cleanup timer library
void timer_cleanup(void);

#endif // TIMER_H
