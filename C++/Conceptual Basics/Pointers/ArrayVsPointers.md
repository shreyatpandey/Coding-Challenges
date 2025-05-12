# Arrays vs Pointers in C++

Arrays and pointers are not the same, despite some similarities in their usage. Let's explore this through examples.

## Example 1: Type Identification

This example demonstrates how arrays and pointers are treated in function parameters:

```cpp
#include <iostream>
#include <typeinfo>

void takes_pointer(int* pointer) {
    if (typeid(pointer) == typeid(int[])) std::cout << 'a';
    if (typeid(pointer) == typeid(int*)) std::cout << 'p';
}

void takes_array(int array[]) {
    if (typeid(array) == typeid(int[])) std::cout << 'a';
    if (typeid(array) == typeid(int*)) std::cout << 'p';
}

int main() {
    int* pointer = nullptr;
    int array[1];

    takes_pointer(array);
    takes_array(pointer);

    std::cout << (typeid(int*) == typeid(int[]));
}
```

**Output:**
```
pp0
```

**Explanation:**
1. Arrays can decay into pointers when passed to functions
2. According to the C++ standard (§[conv.array]):
   > "An lvalue or rvalue of type 'array of N T' or 'array of unknown bound of T' can be converted to a prvalue of type 'pointer to T'"
3. When `array` is passed to `takes_pointer()`, it decays into a pointer
4. Both functions see their parameters as pointers, hence both print 'p'
5. The final 0 shows that `int*` and `int[]` are different types

## Example 2: Size Differences

This example shows how array sizes are handled differently with pointers, arrays, and references:

```cpp
#include <iostream>
using namespace std;

size_t get_size_1(int* arr)
{
    return sizeof arr;
}

size_t get_size_2(int arr[])
{
    return sizeof arr;
}

size_t get_size_3(int (&arr)[10])
{
    return sizeof arr;
}

int main()
{
    int array[10];
    //Assume sizeof(int*) != sizeof(int[10])
    cout<<"get_size_1:"<<get_size_1(array)<<endl;
    cout<<"get_size_2:"<<get_size_2(array)<<endl;
    cout<<"get_size_3:"<<get_size_3(array)<<endl;
    cout << (sizeof(array) == get_size_1(array));
    cout << (sizeof(array) == get_size_2(array));
    cout << (sizeof(array) == get_size_3(array));
}
```

**Output:**
```
get_size_1:8
get_size_2:8
get_size_3:40
001
```

**Explanation:**
1. `get_size_1` and `get_size_2` return the size of a pointer (8 bytes on 64-bit systems)
2. `get_size_3` returns the actual size of the array (40 bytes = 10 ints × 4 bytes)
3. Only the reference parameter preserves the array's type and size information

## Common Issues with Arrays and Pointers

### Issue 1: Array Assignment
```cpp
int a = 0;
int arr[] = {1,2,3};
arr = &a; // Error: Array type "int [3]" is not assignable
```
The array name `arr` is a pointer constant - its address can be accessed, but it cannot be reassigned.

### Issue 2: Pointer Type Mismatch
```cpp
int *pt;
int arr[] = {1,2,3};
pt = &arr; // Error: Incompatible pointer types - can't assign "int (*)[3]" to "int*"
```
The type of `&arr` is a pointer to an array (`int (*)[3]`), which is different from a pointer to an int (`int*`).

## Key Takeaways

1. Arrays can decay into pointers when passed to functions, but they are fundamentally different types
2. Array names are constant pointers and cannot be reassigned
3. Using references to arrays (`int (&arr)[N]`) preserves array size information
4. The size of a pointer is fixed (typically 8 bytes on 64-bit systems), while array size depends on the number of elements

For more detailed information, check out this [reference](https://rstudio-pubs-static.s3.amazonaws.com/495651_5a3108e73fb1412aa341b6d476abc28e.html).