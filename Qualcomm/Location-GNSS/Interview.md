# Interview Questions - Location GNSS

## Interviewer: Jeevan Varghese

### Q1. What is void pointer?

### Q2. Can you perform pointer arithmetic on void pointer?

### Q3. What is dangling pointer?

### Q4. What is an advantage of defining pointer to Null?

### Q5. Are pointers and array same?

### Q6. Pointer and Array Comparison

```c
int arr[10] = {0}
int *ptr = arr;
int *ptr1 = &arr;
```

**Question:** Are ptr and ptr1 same?

**Size of the two datatype:**
```c
int arr[10]; //sizeof(arr) = 40
int *ptr;    //sizeof(ptr) = 4 
```

**Output of this program:**
```c
#define Square(n) n*n
int n = 5;
printf("%d\n %d\n",Square(n++),n);
```

**Follow-up:** What are the stages of compilation in C program?

**Error in this program:**
```c
char *input = "Jeevan"; // part of read only text segment
input[2] = 'f' ; // error 

char Input[] = "Jev";
Input[1] = 'f' ; // this is possible
```

### Q7. Program to find the number of set bits in an integer?

### Q8. Program to perform circular shift of an integer?

### Q9. Program to define 2D array in C?

### Q10. Define a function pointer in C?

---

## Interviewer: Ankur Sharma

### Q1. Program to reverse words in a sentence?

**Key Points:**
- Lot of edge cases
- First gave `const char*input`, found that out, I had done in-place
- I asked if the string is null-terminated
- **Main thing:** don't assume anything
- Asked for size of string
- **More follow-up:**
  - Number of spaces between words, I had assumed only a space between words
  - Whether the words contain any numbers in it or not

### Q2. Deadly Problem

**Problem Statement:**
I have a stream of bytes coming in a string.
At a particular address there is a struct present, I would need to extract num from it.

```c
struct Node
{
  int num;
};
```

Say this struct is present after a tag = `0x65`

**Example:**
```
0x00 0x01 ...0x65...0x78
```
Bytes end in `0x78`
