# Optimizing Box Weights

An Amazon Fulfillment Associate Box has a set of items that need to be packed into two boxes.  
Given an integer array of the item weights (`arr`) to be packed, divide the item weights into two subsets, **A** and **B**, for packing into the associated boxes, while respecting the following conditions:

1. The intersection of A and B is null (A ∩ B = ∅).
2. The union of A and B is equal to the original array (A ∪ B = arr).
3. The number of elements in subset A is minimal.
4. The sum of A's weights is greater than the sum of B's weights.

**Return** the subset in increasing order where the sum of A's weights is greater than the sum of B's weights.  
If more than one subset A exists, return the one with the maximal total weight.

---

## Example

```
n = 5
arr = [3, 7, 5, 6, 2]
```

The 2 subsets in `arr` that satisfy the conditions for A are `[5, 7]` and `[6, 7]`:

- Both have minimal size (2).
- `Sum([5, 7]) = 12 > Sum([2, 3, 6]) = 11`
- `Sum([6, 7]) = 13 > Sum([2, 3, 5]) = 10`

The intersection of A and B is null and their union is equal to `arr`.

---

## Function Signature

You are to implement a function with the following signature:

```python
def minimalHeaviestSetA(arr: List[int]) -> List[int]:
    # implementation
```