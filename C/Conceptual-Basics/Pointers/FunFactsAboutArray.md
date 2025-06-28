# Fun Facts About Arrays

## Array Pointers - Key Concepts

1. **Array to Pointer Relationship**
   - `&arr` is a pointer to the array
   - It points to the same memory address as `arr` (which decays to a pointer to its first element)
   - However, they have different types - `&arr` has the size of the entire array, while `arr` has the size of just one element

2. **Array Boundaries**
   - `&arr + 1` points to the address after the end of the array
   - `*(&arr + 1)` when dereferenced gives the address after the end of the last element
   - Both point to the same address but with different types

3. **Array Length Calculation**
   - Without using `sizeof()`, we can calculate array length: `*(&arr + 1) - arr`
   - Due to array indexing and pointer arithmetic equivalence:
     ```c
     (&arr)[1] - arr == 1[&arr] - arr
     ```

## Traversing Arrays Without sizeof()

### Method 1: Using Index
```c
for (int i = 0; i < 1[&arr] - arr; i++) 
    printf("%d\n", arr[i]); 
```

### Method 2: Using Pointer
```c
for (int *p = arr; p < 1[&arr]; p++) 
    printf("%d\n", *p); 
```

## Example 1: Array Address Traversal

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[5] = {1,2,3,4,5};
    printf("Array-Address:%p\n",arr);
    for(int *p = arr;*p<1[&arr]-arr;p++)
    {
        printf("%p ",p);
        printf("%d\n",*p);
    }
    return 0;
}
```

**Output:**
```
Array-Address:0x7ffe313acbd0
0x7ffe313acbd0 1
0x7ffe313acbd4 2
0x7ffe313acbd8 3
0x7ffe313acbdc 4
```

## Example 2: Array Reference and Pointer

```c
#include <stdio.h>
int main(void)
{
    int ref[] = {8, 4, 0, 2};
    int *ptr;
    int index;
    for (index = 0, ptr = ref; index < 4; index++, ptr++)
    {
        printf("%d %d\n", ref[index], *ptr); //same output: 8 8, 4 4, 0 0, 2 2
        printf("Address of each:%p\n",(void *)&ptr);
    }
    return 0;
}
```

**Output:**
```
8 8                                                                                                                     
Address of each:0x7ffeb9798bc8                                                                                          
4 4                                                                                                                     
Address of each:0x7ffeb9798bc8                                                                                          
0 0                                                                                                                     
Address of each:0x7ffeb9798bc8                                                                                          
2 2                                                                                                                     
Address of each:0x7ffeb9798bc8 
```

## Important Note on Array Pointer Declaration

There is no difference between these two declarations of pointer to array:

```c
// Method 1
int *ptr;
int arr[5] = {0};
ptr = arr;

// Method 2
int *ptr;
int arr[5] = {0};
ptr = &arr;
```

Both methods point to the first element address of the array. This is because when used in this context, both `arr` and `&arr` evaluate to the address of the first element of the array.