# Amazon Drone Capacity

## Problem Description

In Amazon's distribution network, there are several drones with varying capacities, ranging from 1 to 10^9. Each j^th drone has a carrying capacity of j. The company needs to dispatch 'n' packages, where the weight of the i^th package is given by `pack[i]`.

During peak delivery times, only two drones are available to transport the packages, and they must alternate in their duties. This means that if Drone 1 handles the i^th package, Drone 2 must handle the (i+1)^th package, and so on.

However, there may be challenges if the drones cannot handle certain package weights (i.e., some packages may be too heavy for a drone). To address this, Amazon can replace certain packages with others of a different weight to ensure that all packages are successfully delivered.

Given the ability to choose any two drones, your task is to determine the minimum number of replacements needed to ensure that all the packages can be successfully delivered.

---

## Example

**Input:**
```
n = 4
pack = [3, 1, 3, 2]
```

With the provided package weights `[3, 1, 3, 2]`, the two drones won't be able to alternate in handling the packages. To resolve this, the fourth package, which weighs 2, can be replaced with a package of weight 1. This results in the adjusted weights:

```
pack = [3, 1, 3, 1]
```
Now, two drones with carrying capacities of 3 and 1 can handle the packages alternatively. Therefore, only one replacement is needed.

**Output:**
```
1
```

---

## Function Description

Complete the function `findMinReplacements` in the editor below.

```
findMinReplacements(pack: List[int]) -> int
```

- `pack`: an array representing the weights of packages
- **Returns:** the minimum number of replacements needed

---

## Constraints
- 2 ≤ n ≤ 2 × 10^5
- n is even
- 1 ≤ pack[i] ≤ 10^9
