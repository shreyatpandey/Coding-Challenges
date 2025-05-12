# Array Addressing

## Question 1: Array Address Arithmetic

```cpp
#include <stdio.h>
int main()
{
    int arr[5] = {1,2,3,4};
    printf("%p\n",arr);
    printf("%p\n",(arr+1));
    return 0;
}
```

**Output:**
```
0x7fff44cb4240
0x7fff44cb4244
```

**Explanation:**  
When we increment an array pointer by 1 (arr+1), the address increases by the size of the datatype. 
In this case, since `arr` is an integer array and the size of int is 4 bytes, the address increases by 4 bytes.

**Key Point:** Address would always be = Original Address + sizeof(datatype)

## Question 2: Array Pointer Dereferencing

```cpp
#include <stdio.h>
int main()
{
    int arr[4] = {1,2,3,4};
    printf("%x\n",*(arr)+1);  // 2 
    printf("%x\n",*(arr+1));  // 2
    printf("%x\n",*(arr+3));  // 4
    printf("%x\n",*(arr+4));  // 0
    return 0;
}
```

**Output:**
```
2
2
4
0
```

**Explanation:**
- `*(arr)+1`: First dereferences arr (gets 1), then adds 1, resulting in 2
- `*(arr+1)`: Moves pointer one position ahead, then dereferences to get 2
- `*(arr+3)`: Moves pointer three positions ahead, then dereferences to get 4
- `*(arr+4)`: Accesses memory beyond array bounds, returns 0 (undefined behavior)

## Question 3: Array of Pointers

```cpp
#include<stdio.h>
int main()
{
    char *B[8];   // array of pointers
    double *D[5]; // array of pointers
    int **R[9];   // array of pointers, size would be 8 bytes itself
    printf("%d\n",sizeof(B));
    printf("%d\n",sizeof(D));
    return 0;
}
```

**Output:**
```
64
40
```

**Explanation:**  
- Size of a pointer is 8 bytes on a 64-bit system
- `char *B[8]`: Array of 8 pointers = 8 × 8 = 64 bytes
- `double *D[5]`: Array of 5 pointers = 5 × 8 = 40 bytes

## Array Addressing Formulas

### 1. One-dimensional Array
To find address of the i-th element:
```
Address = startingAddress + L × i
```
where:
- L = size of datatype in bytes
- i = index

### 2. Two-dimensional Array
For array declaration `T D[R][C]`, address of element D[i][j]:
```
Address = baseAddress + L × (C × i + j)
```
where:
- L = size of datatype T in bytes
- C = number of columns
- i = row index
- j = column index