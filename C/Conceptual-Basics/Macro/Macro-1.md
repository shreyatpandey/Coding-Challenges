# Macro Examples

## Example 1: Square Macro with Increment Operator (Asked in Qualcomm)

```cpp
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Square(n) n*n

int main()
{
    int n = 5;
    printf("%d\n %d\n",Square(n++),n);
    return 0;
}
```

**Output:** 
```
30
7
```

**Explanation:**  
MACROs are textual replacement. When `Square(n++)` is processed, it expands to `n++ * n++`. 
The expression becomes `5 * 6 = 30` because the first `n++` evaluates to 5 and increments n to 6, 
then the second `n++` evaluates to 6 and increments n to 7.

## Example 2: Token-Pasting Operator

```cpp
#include<stdio.h> 
#define f(g,g2) g##g2 
int main() 
{ 
   int var12 = 100; 
   printf("%d", f(var,12)); 
   return 0; 
}
```

**Output:** `100`

**Explanation:**  
The operator `##` is called "Token-Pasting" or "Merge" Operator. It merges two tokens into one token.
After preprocessing, `f(var,12)` becomes `var12`, making the code equivalent to:

```cpp
int main() 
{ 
   int var12 = 100; 
   printf("%d", var12); 
   return 0; 
}
```

## Example 3: Square Macro with Division

```cpp
#include <stdio.h>
#define square(x) x*x
int main()
{
  int x;
  x = 36/square(6);
  printf("%d", x);
  return 0;
}
```

**Explanation:**  
The preprocessor replaces `square(6)` with `6*6`, making the expression `x = 36/6*6`.
Due to operator precedence, this evaluates as `(36/6)*6 = 6*6 = 36`.

To fix this issue, the macro should be defined with proper parentheses:
```cpp
#define square(x) ((x)*(x))
```

## Example 4: Square Macro with Expression

```cpp
#include<stdio.h>
#define SQR(x) (x*x)
int main()
{
    int a;
    int b=4;
    a=SQR(b+2);
    printf("%dn",a);
    return 0;
}
```

**Explanation:**  
When `SQR(b+2)` is expanded to `(b+2*b+2)`, it becomes `(4+2*4+2) = 14`.
This happens because the macro expands without proper parentheses, leading to unintended operator precedence.

## Example 5: Stringizing Operator

```cpp
#include <stdio.h>
#define get(s) #s
 
int main()
{
    char str[] = get(GeeksQuiz);
    printf("%s", str);
    return 0;
}
```

**Output:** `GeeksQuiz`

**Explanation:**  
The preprocessing operator `#` is called the "Stringizing" operator. It converts a macro parameter into a string constant.
When `get(GeeksQuiz)` is processed, it becomes `"GeeksQuiz"`.