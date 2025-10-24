# Timer Framework Documentation

## Overview

This is a simplistic timer framework implementation written in C for QNX systems (though portable to other Unix-like systems). The framework provides a tick-based timer system that can manage multiple timers with callback functionality. It simulates hardware timer interrupts using Unix signals and process timers.

## Author
Created by amallory@qnx.com

## Architecture

### Core Components

1. **Timer Pool Management**: Fixed-size pre-allocated timer pool
2. **Linked List Management**: Active and free timer queues using BSD-style TAILQ macros
3. **Clock Simulation**: Signal-based timer tick simulation
4. **Callback System**: User-defined callback functions for timer expiration

## Data Structures

### Enumerations

#### `timer_callback_retval`
Defines return values for timer callback functions:
```c
enum timer_callback_retval {
    CB_RETURN_NORMAL = 0,        // Continue normal operation
    CB_RETURN_FREE_TIMER,        // Free the timer after callback
    CB_RETURN_INVALID,           // Invalid return value
};
```

#### `timer_type`
Defines timer types for setting fire times:
```c
enum timer_type {
    TT_RELATIVE = 0,             // Fire time relative to current tick
    TT_ABSOLUTE,                 // Fire time as absolute tick count
    TT_INVALID,                  // Invalid timer type
};
```

### Core Data Structure

#### `timer_node`
The fundamental timer structure containing:
```c
struct timer_node {
    TAILQ_ENTRY(timer_node) entries;    // Linked list pointers
    uint64_t fire;                      // Absolute fire time (in ticks)
    int (*cb)(void* user_data);         // Callback function pointer
    void *user_data;                    // User data passed to callback
};
```

### Global Variables

- `tick_cnt`: 64-bit master tick counter, incremented on each clock tick
- `active_timers`: TAILQ list of armed timers, sorted by fire time
- `free_timers`: TAILQ list of available timer nodes
- `timer_memory`: Pre-allocated memory block for all timer nodes

## Constants

- `NUM_TIMERS`: Maximum number of concurrent timers (10)
- `MAX_RANDOM_TIME_MS`: Maximum random timer duration for demo (20000ms)

## Function Reference

### Timer Management Functions

#### `init_timers()`
**Purpose**: Initialize the timer subsystem
**Operation**:
1. Initialize active and free timer queues
2. Allocate memory for `NUM_TIMERS` timer nodes
3. Add all allocated timers to the free list
**Error Handling**: Exits program if memory allocation fails

#### `alloc_timer()`
**Purpose**: Allocate a timer from the free pool

**Returns**: Pointer to available timer node or NULL if pool is empty

**Operation**: Removes first timer from free list and returns it

#### `free_timer(struct timer_node *timer)`
**Purpose**: Return a timer to the free pool
**Operation**: Inserts timer at head of free list

#### `set_timer(struct timer_node* timer, enum timer_type tt, uint64_t fire, int (*cb)(void*), void* user_data)`
**Purpose**: Configure timer attributes
**Parameters**:
- `timer`: Timer node to configure
- `tt`: Timer type (relative/absolute)
- `fire`: Fire time (relative offset or absolute tick count)
- `cb`: Callback function pointer
- `user_data`: Data to pass to callback
**Returns**: 0 on success, -1 on invalid timer type
**Operation**: 
- For relative timers: adds current tick count to fire time
- For absolute timers: uses fire time as-is
- Sets callback and user data

#### `arm_timer(struct timer_node* timer)`
**Purpose**: Add timer to active queue in sorted order
**Operation**: Inserts timer in active list sorted by fire time (earliest first)
**Algorithm**: Linear search to find correct insertion point

#### `disarm_timer(struct timer_node* timer)`
**Purpose**: Remove timer from active queue
**Operation**: Removes specified timer from active list

### Clock System Functions

#### `init_ticker(unsigned ms)`
**Purpose**: Initialize the simulated clock tick system
**Parameters**: `ms` - tick interval in milliseconds
**Returns**: Result of `setitimer()` call
**Operation**:
1. Sets up interval timer using `ITIMER_REAL`
2. Registers `clock_tick()` as SIGALRM signal handler
3. Timer generates SIGALRM every `ms` milliseconds

#### `clock_tick(int signo)`
**Purpose**: Signal handler for timer ticks (simulates hardware interrupt)
**Operation**:
1. Increment global tick counter
2. Process all expired timers:
   - Check if active timers list is not empty
   - While first timer's fire time ≤ current tick count:
     - Remove timer from active list
     - Execute timer's callback function
     - If callback returns `CB_RETURN_FREE_TIMER`, return timer to free pool

### Utility Functions

#### `print_list(struct timer_list *list)` (DEBUG only)
**Purpose**: Debug function to print timer fire times in a list
**Operation**: Iterates through list and prints each timer's fire time

### Demo Functions

#### `tcb(void *data)`
**Purpose**: Example timer callback function
**Operation**: Prints timer fire time and returns `CB_RETURN_FREE_TIMER`

## Program Flow

### Initialization Phase
1. `init_timers()`: Set up timer subsystem
2. `init_ticker(1)`: Start 1ms tick clock
3. Seed random number generator (implicitly)

### Timer Creation Phase
1. Loop `NUM_TIMERS` times:
   - Allocate timer from free pool
   - Set random fire time (1-20000ms)
   - Configure timer with callback
   - Arm timer (add to active queue)

### Runtime Phase
1. Main thread sleeps indefinitely
2. Every 1ms, `SIGALRM` triggers `clock_tick()`
3. `clock_tick()` processes expired timers
4. Expired timers execute callbacks and get freed

## Key Design Decisions

### Memory Management
- **Pre-allocation**: All timer memory allocated upfront to avoid runtime allocation failures
- **Fixed Pool**: Limits concurrent timers but provides predictable behavior
- **No Dynamic Allocation**: Suitable for embedded/real-time systems

### Timer Queue Management
- **Sorted Insertion**: Active timers maintained in fire-time order
- **O(n) Insertion**: Linear search for insertion point (acceptable for small timer counts)
- **O(1) Expiration**: Always check first timer in queue

### Clock Simulation
- **Signal-Based**: Uses Unix signals to simulate hardware interrupts
- **Real-Time Approximation**: `ITIMER_REAL` provides wall-clock timing
- **1ms Resolution**: Chosen tick rate balances accuracy and overhead

## Limitations and Considerations

### Current Limitations
1. **Fixed Timer Pool**: Cannot exceed `NUM_TIMERS` concurrent timers
2. **Linear Insertion**: O(n) complexity for timer insertion
3. **Signal-Based Timing**: Not true real-time, subject to OS scheduling
4. **No Timer Cancellation**: No API to cancel armed timers
5. **No Timer Modification**: Cannot change fire time of armed timers

### Potential Improvements
1. **Heap-Based Priority Queue**: O(log n) insertion/removal
2. **Timer Wheel**: O(1) operations for certain timer patterns
3. **Dynamic Pool**: Grow timer pool as needed
4. **Timer ID System**: Allow timer lookup and cancellation
5. **High-Resolution Timers**: Use `timer_create()` for better precision

## Error Handling

### Fatal Errors
- Memory allocation failure in `init_timers()`
- Timer pool exhaustion in main loop
- Invalid timer type in `set_timer()`

### Error Recovery
- Most errors cause program termination (suitable for demo)
- Production code would need more robust error handling

## Thread Safety

**Current State**: Not thread-safe
- Global variables accessed without synchronization
- Signal handler modifies shared state
- Timer lists not protected by mutexes

**Production Considerations**: Would need:
- Mutex protection for timer lists
- Atomic operations for tick counter
- Signal masking during critical sections

## Usage Example

```c
// 1. Initialize system
init_timers();
init_ticker(1);  // 1ms ticks

// 2. Create and arm a timer
struct timer_node *timer = alloc_timer();
set_timer(timer, TT_RELATIVE, 5000, my_callback, my_data);
arm_timer(timer);

// 3. Timer will fire after 5000 ticks (5 seconds)
```

## Testing and Validation

The current implementation includes a basic test in `main()` that:
1. Creates 10 random timers
2. Verifies timer allocation
3. Confirms timer arming
4. Lets timers expire naturally

For production use, additional testing would be needed for:
- Timer accuracy and precision
- Pool exhaustion scenarios
- Signal delivery reliability
- Memory leak detection
