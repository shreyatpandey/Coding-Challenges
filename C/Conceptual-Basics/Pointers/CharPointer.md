# Character Pointer Examples in C/C++

## Example 1: String Assignment to Malloc'd Pointer

```c
#include<stdio.h>
#include<stdlib.h>
int main()
{
    char *ptr;
    ptr = (char *)malloc(sizeof(char)*11);
    ptr = "sanfoundry";
    printf("%s\n",*ptr);
    return 0;
}
```

**Output:**
```
Segmentation fault
```

**Explanation:**  
This code fails because:
1. First, we allocate memory using `malloc`
2. Then, we assign a string literal to `ptr`, which overwrites the malloc'd address
3. The `printf` statement is incorrect - `*ptr` dereferences to a char, but `%s` expects a char*
4. The correct printf would be `printf("%s\n", ptr)` to print the string

## Example 2: Uninitialized Pointer with memcpy

```c
int main()
{
    char *ptr;
    memcpy(ptr,"sanfoundry",11);
    printf("%s\n",ptr);
    return 0;
}
```

**Output:**
```
Segmentation fault
```

**Explanation:**  
The code crashes because:
1. `ptr` is uninitialized - it points to a random memory location
2. Attempting to `memcpy` to an uninitialized pointer is undefined behavior
3. We should first allocate memory using `malloc` before using `memcpy`

## Example 3: ASCII Value of First Character

```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>                              

int main()
{
    char *ptr;
    ptr = (char*)malloc(sizeof(char)*11);
    strcpy(ptr,"sanfoundry");
    printf("%d\n",*ptr);
    return 0;
}
```

**Output:**
```
115
```

**Explanation:**  
This code works correctly because:
1. Memory is properly allocated using `malloc`
2. `strcpy` is used to copy the string
3. `*ptr` dereferences to get the first character 's'
4. Printing with `%d` shows the ASCII value of 's' which is 115

## Example 4: Memory Address Comparison

```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>                              

int main()
{
    char *ptr;
    printf("%p\n",ptr);
    ptr = (char *)malloc(sizeof(char));
    printf("%p\n",ptr);
    return 0;
}
```

**Output:**
```
[Some random address]
[Different heap address]
```

**Explanation:**  
This demonstrates that:
1. Initially, `ptr` contains a random address (uninitialized)
2. After `malloc`, `ptr` contains a valid heap memory address
3. The two addresses are different as expected

## Example 5: String Pointer Manipulation

```c
#include <stdio.h>
#include<stdlib.h>

int main()
{
    char Input[6] = "Hello";
    char *ptr = Input;
    char* next = ptr+1;
    printf("%s\n", next);       // Prints from second character to end
    printf("%c\n", (*next)++);  // Prints and increments second character
    printf("%c\n",*(ptr+1));    // Prints the incremented second character
    printf("%s\n",(ptr+1));     // Prints from second character to end
    return 0;
}
```

**Output:**
```
ello
e
f
fllo
```

**Explanation:**  
This example shows pointer arithmetic and string manipulation:
1. `next` points to the second character ('e')
2. First print shows the string from 'e' onwards: "ello"
3. Second print shows 'e' and increments it to 'f'
4. Third print shows the incremented character 'f'
5. Fourth print shows the string from the incremented second character: "fllo"