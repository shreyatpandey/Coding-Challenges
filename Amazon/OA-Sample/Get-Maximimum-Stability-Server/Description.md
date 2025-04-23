# AWS Maximum Stability Server

AWS provides a range of servers to meet the deployment needs of its clients.  
A client wants to choose a set of servers to deploy their application.  
Each server is associated with an **availability factor** and a **reliability factor**.

The client defines the **stability** of a set of servers as:

> the minimum availability amongst the servers multiplied by the sum of reliabilities of all the servers.

Given two arrays of integers, `availability` and `reliability`,  
where `availability[i]` and `reliability[i]` represent the availability and reliability factors of the *i-th* server,  
find the **maximum possible stability** of any subset of servers.

Since the answer can be large, report the answer modulo $10^9 + 7$.

---

## Example

Consider the set of servers where  
`reliability = [1, 2, 2]`  
`availability = [1, 1, 3]`

The possible subsets of servers are:

| Indices   | Stability Calculation                | Stability |
|-----------|-------------------------------------|-----------|
| [0]       | only 0th server: 1 * 1              | 1         |
| [1]       | only 1st server: 1 * 2              | 2         |
| [2]       | only 2nd server: 3 * 2              | 6         |
| [0, 1]    | min(1, 1) * (1 + 2) = 1 * 3         | 3         |
| [0, 2]    | min(1, 3) * (1 + 2) = 1 * 3         | 3         |
| [1, 2]    | min(1, 3) * (2 + 2) = 1 * 4         | 4         |
| [0,1,2]   | min(1, 1, 3) * (1 + 2 + 2) = 1 * 5  | 5         |

So the answer is the maximum stability for the set of index `{2}`,  
answer = $6 \mod 10^9+7 = 6$.

---

## Function Description

Complete the function `getMaxStability` in the editor below.

### `getMaxStability` has the following parameters:

- `int reliability[n]`: server reliability values
- `int availability[n]`: server availability values

### Returns

- `int`: the maximum stability among all possible non-empty subsets, modulo $10^9+7$

---

## Constraints

- $1 \leq n \leq 10^5$
- $1 \leq reliability[i],\ availability[i] \leq 10^6$
- It is guaranteed that lengths of `reliability` and `availability` are the same.