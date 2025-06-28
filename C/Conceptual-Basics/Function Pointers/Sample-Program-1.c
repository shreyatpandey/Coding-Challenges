#include <stdio.h>
#include<stdlib.h>
#include<string.h>

void foo(void)
{
    printf("foo\n");
}
void bar(void)
{
    printf("bar\n");
}
typedef void (*funcs)(void) ; //this is function signature
funcs func[] ={ foo,bar}; //array of pointers

int main()
{
    size_t n = sizeof(func)/sizeof(func[0]);
    int i;
    for(i=0;i<n;++i)
    {
        func[i]();
    }
    return 0;
}
