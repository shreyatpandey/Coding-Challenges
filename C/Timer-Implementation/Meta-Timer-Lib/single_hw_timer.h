#ifndef SINGLE_HW_TIMER_H
#define SINGLE_HW_TIMER_H

#include <stdint.h>

/**
 * Single Hardware Timer Implementation
 * 
 * This implementation manages multiple software timers using a single hardware timer.
 * The system does not have access to clock_gettime() or similar functions.
 * 
 * Key Design Principles:
 * - Uses relative time tracking based on hardware timer ticks
 * - Maintains a sorted list of timers by expiration time
 * - Hardware timer is programmed to fire at the next earliest expiration
 * - Supports one-shot callbacks
 */

// Callback function type
typedef void (*callback_fn_t)(void);

/**
 * Request a callback to be called after the specified interval
 * 
 * @param interval_ms Time interval in milliseconds after which callback should be invoked
 * @param callbackFn Function pointer to be called when timer expires
 * 
 * @return 0 on success, -1 on failure
 */
int requestCallback(uint64_t interval_ms, void (*callbackFn)(void));

/**
 * Hardware Timer Interrupt Handler
 * 
 * This function should be called from the hardware timer interrupt.
 * It processes expired timers and reprograms the hardware timer for the next expiration.
 * 
 * Note: In a real embedded system, this would be registered as an ISR (Interrupt Service Routine)
 */
void HwTimerExpire(void);

/**
 * Initialize the timer system
 * 
 * @param hw_timer_tick_ms The hardware timer tick period in milliseconds
 *                         (how often HwTimerExpire will be called)
 */
void timer_system_init(uint32_t hw_timer_tick_ms);

/**
 * Shutdown the timer system and cleanup resources
 */
void timer_system_cleanup(void);

/**
 * Get the number of active timers (for debugging/monitoring)
 * 
 * @return Number of pending timers
 */
int get_active_timer_count(void);

#endif // SINGLE_HW_TIMER_H
