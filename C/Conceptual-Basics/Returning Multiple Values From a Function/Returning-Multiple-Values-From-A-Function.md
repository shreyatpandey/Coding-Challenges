# Returning Multiple Values From A Function

## Question
If I have a function that produces a result `int` and a result `string`, how do I return them both from a function?

As far as I can tell I can only return one thing, as determined by the type preceding the function name.

## Answer

### 1. Return a struct which contains all the types you need

```c
struct Tuple {
    int a;
    string b;
};

struct Tuple getPair() {
    Tuple r = { 1, getString() };
    return r;
}

void foo() {
    struct Tuple t = getPair();
}
```

### 2. Use pointers to pass out values

```c
void getPair(int* a, string* b) {
    // Check that these are not pointing to NULL
    assert(a);
    assert(b);
    *a = 1;
    *b = getString();
}

void foo() {
    int a, b;
    getPair(&a, &b);
}
```
