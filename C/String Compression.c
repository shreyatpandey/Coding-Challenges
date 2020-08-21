#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 


char* encode(char* src) 
{ 
    
    char count[MAX_RLEN]; 
    int len = strlen(src); 
    char* dest = (char*)malloc(sizeof(char) * (len * 2 + 1)); 
  
    int i, j = 0, k; 
    int anchor = 0;
    int write = 0;
    /* traverse the input string one by one */
    for (i = 0; i < len; i++) 
    { 
         anchor++;
        if (i + 1 >=strlen(src) || src[i+1] != src[i])
        {
            dest[write++] = src[i];
            if(anchor <= 9)
            {
                dest[write++] = anchor + '0';
            }
            else if(anchor > 9)
            {
                while(anchor > 9)
                    {
                       dest[write++] = anchor/10 + '0';
                       anchor = anchor % 10;
                    }
                    dest[write++] = anchor + '0'; 
            }
       
       anchor = 0;
    }
    }
    dest[write] = '\0';
    return dest; 
} 
  
/*driver program to test above function */
int main() 
{ 
    char str[] = "a"; 
    char* res = encode(str); 
    printf("%s", res); 
    getchar(); 
} 
