#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 


char* encode(char* src) 
{ 
    
    char count[MAX_LEN]; 
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

//Approach-2 :
//TC:- O(N^2)
char* RunLengthEncoding(const char* Input)
{
    static char Output [ 256 ]; //static is imp , else compiler would complain only address is returned
    size_t CharFreq = 0;
    for(int i=0;i<strlen(Input);i++)
    {
        int j = i;
        size_t count = 0;
        while(Input[i] == Input[j])
        {
            count += 1;
            j += 1;
        }
        Output[CharFreq++] = Input[i] ;
        if ( count > 9)
        {
            while( count > 9)
            {
                int quotient = count/10;
                Output[CharFreq++] = quotient + (int)'0';
                count = count%10;
            }
            Output[CharFreq++] = count+(int)'0';
        }
        else
        {
            Output[CharFreq++] = count + (int)'0';
        }
        
        i = j-1;
    }
    return Output;
}

int main()
{
    const char * Input = "aaaaaaaaaabb" ;
    char* ResultString = RunLengthEncoding(Input);
    return 0;
}

