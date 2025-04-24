# Minimum Removals to Satisfy Threshold

Given an unsorted array of positive integers (with possible duplicates), an integer `k`, and a `threshold` integer, find the minimum number of elements to be removed such that the sum of any `k` elements in the array does not exceed the threshold.

## Problem Statement

- **Input:**
  - An unsorted array of positive integers (may contain duplicates)
  - An integer `k`
  - An integer `threshold`
- **Output:**
  - The minimum number of elements to remove from the array so that the sum of any `k` elements in the remaining array does not exceed `threshold`.

## Example

**Input:**
```
arr = [2, 3, 5, 8, 1]
k = 3
threshold = 10
```
**Output:**
```
2
```
**Explanation:**
Remove 8 and 5. The remaining array is [2, 3, 1]. The sum of any 3 elements is 6, which is ≤ 10.

## Approach

1. **Sort** the array in descending order.
2. While the sum of the largest `k` elements is greater than `threshold`, remove the largest element.
3. Repeat until the sum of the largest `k` elements is ≤ `threshold` or the array has fewer than `k` elements (in which case, it's impossible).
4. Return the number of elements removed.

## Pseudocode

```
sort array in descending order
removals = 0
while len(array) >= k and sum(array[0:k]) > threshold:
    remove array[0]
    removals += 1
if len(array) < k:
    return -1  # Not possible
return removals
```

## Complexity
- Sorting: O(n log n)
- Each removal: O(1)
- In the worst case, up to n removals, but usually much fewer.

## Notes
- If it is not possible to satisfy the condition (i.e., fewer than `k` elements remain), return `-1` or an appropriate error value.
