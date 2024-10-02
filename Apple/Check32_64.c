#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    if (sizeof(void *) == 4)
    {
      #ifdef DEBUG
        printf("32\n");
      #endif 
    }
    if (sizeof(void*) == 8)
    { 
        #ifdef DEBUG
          printf ("64\n"); 
        #endif
     }
    return 0;
}
/* 
  To enable Macro
  gcc Check32_64.c -DDEBUG -o test
*/