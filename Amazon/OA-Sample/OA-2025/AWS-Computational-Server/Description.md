# AWS Computational Server Selection

## Problem Description

Amazon Web Services (AWS) provides highly scalable solutions for applications hosted on their servers. A company that uses AWS is planning to scale up its application horizontally. It needs to buy a certain number of servers from the given set of `n` servers provided by AWS. To ensure that adjacent servers have similar load handling capacity, they want the computational power of two adjacent servers to have a difference of 1 or less.

Given the computational power of all the `n` servers as an array of integers `powers`, find the maximum number of servers that the client can buy such that the selected set of servers can be rearranged in a way that the absolute difference between the computational power of two adjacent servers is less than or equal to 1. The client wants to create a circular network, so the first and last servers in the sequence are also considered adjacent.

More formally, a sequence `candidate[]` of length `m` is classified as a candidate for selection by the client if it can be rearranged in a way such that:
- `abs(candidate[i] - candidate[i+1]) <= 1` for `0 <= i < m-1`, and
- `abs(candidate[m-1] - candidate[0]) <= 1`.

Find the maximum number of servers the client can buy from the `n` available servers.

**Note:**
A subsequence is a sequence that can be derived from the given sequence by deleting zero or more elements without changing the order of the remaining elements.

---

## Example

**Input:**
```
powers = [4, 3, 5, 1, 2, 2, 1]
```

Some of the possible candidates are as follows:
- Subsequence `[1, 2, 2, 1]` as `abs(1-2) = 1`, `abs(2-2) = 0`, `abs(2-1) = 1`, `abs(1-1) = 0`
- Subsequence `[3, 1, 2, 2]` as it can be rearranged to `[1, 2, 3, 2]` and now `abs(1-2) = 1`, `abs(2-3) = 1`, `abs(3-2) = 1`, and `abs(2-1) = 1`

Some of the candidates which do not meet the client's criteria are as follows:
- Subsequence `[3, 1, 2]`, as no possible rearrangement will satisfy the above-mentioned conditions
- Subsequence `[4, 3, 5]`, as no possible rearrangement will satisfy the above-mentioned conditions

The maximum number of servers that the client can buy is **5**.

---

## Function Description

Complete the function `getMaxServers` as described below:

```
getMaxServers(powers: List[int]) -> int
```

- `powers`: an array representing the computational capacity of all the `n` servers
- **Returns:** the maximum number of servers the client can buy

---

## Constraints
- 1 ≤ n ≤ 10^5