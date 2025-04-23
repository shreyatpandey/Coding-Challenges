# Problem Description

A virus has an attacking rule defined by `attackOrder`, which is a permutation array of length `n`.  
In the *i-th* second of the attack, the virus attacks the character at position `attackOrder[i]` in the password, replacing it with the malicious character `'*'`.  
That is, after the *i-th* second:  
`password[attackOrder[i]] = '*'`

## Function to Implement

### `findMinimumTime`

#### Parameters

1. **string password**: The initial password.
2. **int attackOrder[n]**: A permutation array of integers `[1, 2, ..., n]`, representing the attack order of the virus (1-indexed).
3. **int m**: The recoverability parameter.

#### Irrecoverability Condition

The password is said to become **irrecoverable** when the number of substrings of the password containing at least one malicious character `'*'` becomes **greater than or equal to** `m`.

#### Return

- **int**: The minimum time (number of attacks) after which the password becomes irrecoverable.

---

## Sample Input/Output

### Sample 1

**Input:**
```
password = "abc"
attackOrder = [1, 2, 3]
m = 1
```
**Output:**  
```
1
```

### Sample 2

**Input:**
```
password = "bcdb"
attackOrder = [2, 4, 1, 3]
m = 10
```
**Output:**  
```
4
```