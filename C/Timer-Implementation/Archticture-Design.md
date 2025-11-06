# Timer Architecture Design Patterns

## Overview

This document outlines three common architectural patterns for implementing timer systems in embedded systems, showing the relationship between hardware (HW) timers and software (SW) timers.

---

## 1. Single HW Timer + Single SW Timer

**Description:**  
The simplest architecture where one hardware timer manages exactly one software timer.

**Characteristics:**
- ✓ Minimal memory footprint
- ✓ Simple implementation - just one struct
- ✓ No data structure overhead (no list/array needed)
- ✗ Limited functionality - only one timer can be active at a time
- ✗ New timer request overwrites previous timer

**Use Case:**  
Simple applications requiring only one timer at a time (e.g., watchdog timer, single timeout).

**Data Structure:**
```c
struct {
    uint64_t expiry_time;
    callback_fn_t callback;
} single_timer;
```

---

## 2. Single HW Timer + Multiple SW Timers ✓

**Description:**  
One hardware timer multiplexed to manage multiple software timers. This is the **most common** embedded systems approach.

**Characteristics:**
- ✓ Efficient hardware resource usage
- ✓ Supports multiple concurrent timers
- ✓ Hardware timer programmed for next earliest expiration
- ⚠ Requires array/linked list to track all SW timers
- ⚠ Slightly more complex interrupt handling

**Use Case:**  
Most embedded applications where multiple timeouts/delays are needed but hardware timers are limited (e.g., RTOS tick timer, multiple protocol timeouts, periodic tasks).

**Data Structure:**
```c
typedef struct TimerNode {
    uint64_t expiry_time;
    callback_fn_t callback;
    struct TimerNode* next;
} TimerNode;

// Sorted linked list
TimerNode* timer_list;
```

**Algorithm:**
1. Maintain sorted list of SW timers by expiry time
2. Program HW timer to fire at next earliest expiry
3. On HW timer interrupt:
   - Process all expired SW timers
   - Reprogram HW timer for next expiry

---

## 3. Multiple HW Timers + Multiple SW Timers

**Description:**  
Multiple hardware timers available, with options for direct mapping or multiplexing.

**Characteristics:**
- ✓ Can dedicate HW timers to critical timing functions
- ✓ Flexibility in resource allocation
- ✓ Can reduce interrupt latency for high-priority timers
- ⚠ More complex configuration and management
- ⚠ May still need multiplexing if SW timers >> HW timers

**Use Case:**  
Advanced embedded systems with multiple hardware timer peripherals (e.g., motor control system using dedicated PWM timers + general-purpose timers for other tasks).

**Implementation Options:**

### Option A: 1:1 Mapping (Direct)
```
HW Timer 1 ──> SW Timer 1 (high priority)
HW Timer 2 ──> SW Timer 2 (medium priority)
HW Timer 3 ──> SW Timer 3 (low priority)
```

### Option B: Multiplexed Groups
```
HW Timer 1 ──> [SW Timer 1, SW Timer 2, SW Timer 3]  (critical)
HW Timer 2 ──> [SW Timer 4, SW Timer 5, SW Timer 6]  (normal)
```

---

## Comparison Table

| Architecture | HW Timers | SW Timers | Data Structure | Complexity | Memory | Common Use |
|--------------|-----------|-----------|----------------|------------|--------|------------|
| Single/Single | 1 | 1 | Simple struct | Low | Minimal | Watchdog |
| **Single/Multiple** | **1** | **Many** | **List/Array** | **Medium** | **Moderate** | **Most Apps** |
| Multiple/Multiple | Many | Many | Multiple lists | High | Higher | Advanced Systems |

---

## Recommended Pattern

For most embedded applications: **Single HW Timer + Multiple SW Timers** (Pattern #2)

**Reasons:**
1. Hardware timers are typically a scarce resource
2. Provides good balance of functionality vs. complexity
3. Standard approach used in most RTOSes
4. Well-understood and proven architecture

---

## Implementation Considerations

### For Pattern #2 (Single HW + Multiple SW)

**Key Design Decisions:**

1. **Data Structure Choice:**
   - Linked List: O(n) insertion, O(1) removal, dynamic size
   - Array: O(n) insertion, O(1) access, fixed size
   - Heap/Priority Queue: O(log n) insertion, O(log n) removal

2. **Timer Resolution:**
   - HW timer tick period determines minimum resolution
   - Trade-off: faster ticks = higher overhead

3. **Interrupt Safety:**
   - Callbacks execute in interrupt context
   - Keep callbacks short or use deferred processing

4. **Memory Management:**
   - Static allocation (timer pool) vs. dynamic allocation
   - Static = deterministic, Dynamic = flexible

---

## Conclusion

The choice of timer architecture depends on:
- Available hardware resources
- Application requirements (number of timers, resolution, priority)
- Memory constraints
- Real-time requirements

The **Single HW Timer + Multiple SW Timers** pattern offers the best trade-off for most embedded systems.
