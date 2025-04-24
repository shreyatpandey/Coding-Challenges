# Amazon Warehouse Dock Bay Scheduling

You are managing operations at a large Amazon warehouse.  
Loaded trucks arrive at the warehouse sequentially and must be unloaded within a specific timeframe to ensure timely delivery.  
Your task is to determine the **minimum number of dock bays** needed to unload all trucks within the given timeframe.

## Problem Statement

Given:
- An array `truckCargoSize` of length `n`, where each element represents the amount of time (in minutes) that a dock bay will take to unload the cargo from the *i-th* truck.
- An integer `maxTurnaroundTime`, representing the total allowed time to unload all trucks.

**Goal:**  
Find the smallest number of dock bays `d` that will enable you to unload all trucks within `maxTurnaroundTime` minutes.

### Notes

- As soon as a dock bay becomes available after unloading a truck, it can immediately start processing the next truck.
- It is guaranteed that unloading all trucks is possible with some number of dock bays.
- Only the start times of unloading need to be considered in order, not the finish times.

---

## Example

```
n = 5
truckCargoSize = [3, 4, 3, 2, 3]
maxTurnaroundTime = 8
```

**Attempting with two dock bays (d = 2):**

- The first two trucks are assigned to the two dock bays.
- As dock bays become available, they process the next trucks in order.
- All trucks are unloaded in 9 minutes, which exceeds the maxTurnaroundTime of 8 minutes.

**Attempting with three dock bays (d = 3):**

- The first three trucks are assigned to the three dock bays.
- As dock bays become available, they process the next trucks in order.
- All trucks are unloaded in 6 minutes, which is within the maxTurnaroundTime of 8 minutes.

**Hence, the minimum number of dock bays required is 3.**

---

## Function Description

Implement the function `getMinimumDockBays` as described below:

### Parameters

- `int truckCargoSize[n]`: the time in minutes for the dock bay to unload cargo from the *i-th* truck.
- `long maxTurnaroundTime`: the maximum allowed total unloading time.

### Returns

- `int`: the smallest number of dock bays `d`, to unload all the cargo within `maxTurnaroundTime` minutes.

---

## Constraints

- `1 ≤ n ≤ 5 × 10^4`
- `1 ≤ maxTurnaroundTime ≤ 10^15`
- `1 ≤ truckCargoSize[i] ≤ min(maxTurnaroundTime, 10^9)`

---