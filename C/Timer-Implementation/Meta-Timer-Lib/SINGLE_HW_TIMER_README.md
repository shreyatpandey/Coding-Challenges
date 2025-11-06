# Single Hardware Timer Implementation

## Overview

This is an implementation of a software timer system that uses a **single hardware timer** to manage multiple software timers. The system does not rely on `clock_gettime()` or similar system calls to get the current time.

## Problem Statement

Implement a timer system with a single hardware timer that supports:
1. `requestCallback(uint64_t interval_ms, void (*callbackFn)())` - Request a callback after a specified interval
2. `HwTimerExpire()` - Hardware timer interrupt handler

**Constraints:**
- Only one hardware timer available
- No access to `clock_monotonic` or similar system time functions
- Must support multiple software timers

## Design

### Key Components

1. **Timer Node Structure**: Linked list node representing each software timer
   - Expiry time (in ticks)
   - Callback function pointer
   - Next pointer

2. **Sorted Timer List**: Timers are maintained in a sorted linked list ordered by expiry time
   - Head of list always contains the earliest expiring timer
   - Enables efficient O(1) access to next timer to fire

3. **Tick Counter**: Global counter incremented on each hardware timer interrupt
   - Provides relative time tracking
   - No dependency on system time

4. **Hardware Timer Management**: 
   - Programmed to fire at the next earliest timer expiry
   - Reprogrammed after each expiration
   - Stopped when no timers are pending

### Algorithm Flow

#### requestCallback():
1. Validate input parameters
2. Allocate new timer node
3. Calculate expiry time: `current_ticks + (interval_ms / hw_tick_period_ms)`
4. Insert timer into sorted list
5. If this is the earliest timer, reprogram hardware timer

#### HwTimerExpire():
1. Increment system tick counter
2. Process all expired timers (expiry_time ≤ current_ticks):
   - Remove from list
   - Invoke callback
   - Free timer node
3. If more timers exist:
   - Program hardware timer for next expiration
4. Else:
   - Stop hardware timer

### Time Complexity

- **requestCallback()**: O(n) where n is the number of active timers (insertion sort)
- **HwTimerExpire()**: O(k) where k is the number of expired timers at this tick

### Space Complexity

- O(n) where n is the number of active timers

## Files

- `single_hw_timer.h` - Header file with API definitions
- `single_hw_timer.c` - Implementation of the timer system
- `single_hw_timer_example.c` - Comprehensive test suite with multiple test cases
- `Makefile` - Build configuration

## Building

### Build Release Version
```bash
make
```

### Build Debug Version (with verbose output)
```bash
make debug
```

### Clean Build Artifacts
```bash
make clean
```

### Rebuild Everything
```bash
make rebuild
```

## Running

### Run Release Version
```bash
make run
# or
./single_hw_timer_test
```

### Run Debug Version
```bash
make run-debug
# or
./single_hw_timer_test_debug
```

## API Reference

### Initialization
```c
void timer_system_init(uint32_t hw_timer_tick_ms);
```
Initialize the timer system with the hardware timer period.

**Parameters:**
- `hw_timer_tick_ms`: Hardware timer tick period in milliseconds

### Request Callback
```c
int requestCallback(uint64_t interval_ms, void (*callbackFn)(void));
```
Request a callback to be invoked after the specified interval.

**Parameters:**
- `interval_ms`: Time interval in milliseconds
- `callbackFn`: Function pointer to invoke when timer expires

**Returns:**
- `0` on success
- `-1` on failure (NULL callback or zero interval)

### Hardware Timer Handler
```c
void HwTimerExpire(void);
```
Hardware timer interrupt handler. Should be called from the HW timer ISR.

### Cleanup
```c
void timer_system_cleanup(void);
```
Cleanup the timer system and free all resources.

### Utility
```c
int get_active_timer_count(void);
```
Get the number of currently active (pending) timers.

## Test Cases

The example file includes 5 comprehensive test cases:

1. **Simple Timer Requests**: Tests basic timer functionality with different intervals
2. **Same Expiry Time**: Tests multiple timers expiring at the same time
3. **Dynamic Requests**: Tests timers requested at different times during execution
4. **Edge Cases**: Tests error handling (NULL callback, zero interval, very short intervals)
5. **Multiple Timers**: Tests system with many timers with varying intervals

## Example Usage

```c
#include "single_hw_timer.h"

void my_callback(void) {
    printf("Timer expired!\n");
}

int main(void) {
    // Initialize with 10ms hardware timer period
    timer_system_init(10);
    
    // Request callbacks
    requestCallback(100, my_callback);  // Fire after 100ms
    requestCallback(50, my_callback);   // Fire after 50ms
    
    // In your hardware timer ISR, call:
    // HwTimerExpire();
    
    // Cleanup when done
    timer_system_cleanup();
    
    return 0;
}
```

## Implementation Details

### Hardware Timer Programming

In a real embedded system, `program_hw_timer()` would write to hardware registers:

```c
static void program_hw_timer(uint64_t ticks_from_now) {
    // Example for ARM Cortex-M (pseudo-code)
    TIMER_LOAD_REG = ticks_from_now * hw_tick_period_ms;
    TIMER_CONTROL_REG |= TIMER_ENABLE_BIT;
    TIMER_INT_ENABLE_REG |= TIMER_INT_ENABLE_BIT;
}
```

### Interrupt Service Routine

In a real system, `HwTimerExpire()` would be registered as an ISR:

```c
void TIM2_IRQHandler(void) {
    // Clear interrupt flag
    TIMER_INT_CLEAR_REG = TIMER_INT_CLEAR_BIT;
    
    // Call our handler
    HwTimerExpire();
}
```

## Advantages

1. **Efficient**: Only one hardware timer needed for multiple software timers
2. **No System Dependencies**: No reliance on OS time functions
3. **Deterministic**: Predictable behavior suitable for embedded systems
4. **Low Overhead**: Minimal interrupt processing time

## Limitations

1. **Resolution**: Limited by hardware timer tick period
2. **One-Shot Only**: Current implementation only supports one-shot timers (can be extended for periodic)
3. **Callback Context**: Callbacks execute in interrupt context (keep them short!)

## Potential Enhancements

1. Add support for periodic timers
2. Implement timer cancellation (by returning a timer handle)
3. Add priority levels for callbacks
4. Implement timer pooling to avoid dynamic allocation
5. Add statistics/monitoring (timer drift, callback execution time, etc.)

## License

This is a sample implementation for educational purposes.

## Author

Implementation for embedded systems timer management.
