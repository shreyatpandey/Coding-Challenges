#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    if (sizeof(void *) == 4)
    { printf("32\n"); }
    if (sizeof(void*) == 8)
    { printf ("64\n"); }
    return 0;
}
