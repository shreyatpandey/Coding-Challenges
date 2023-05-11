#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdbool.h>
#include<stdlib.h>

#define MAXBUFLEN 256

char* stringCompression(char *input)
{
    const int strlength = strlen(input);
    //static char output[MAXBUFLEN]; // if you use this, then multiple call cannot be made,to this function 
    char* output = (char*)malloc(sizeof(char)*(strlength+1));
    int i,j = 0;
    int index = 0;
    for(i;i<strlength;i++)
    {
        int freqCount = 0;
        while(input[i] == input[j])
        {
            freqCount += 1;
            j += 1;
        }
        output[index++] = input[i];
        if(freqCount>9)
        {
            while(freqCount>9)
            {
                int quotient = freqCount/10;
                output[index++] = quotient + 48;
                freqCount %= 10;
            }
            output[index++] = freqCount + 48;
        }
        else
        {
            output[index++] = freqCount + 48;
        }
        i = j-1;
    }
    output[index] = '\0';
    return output;
}

int main()
{
   char Input[MAXBUFLEN] = "aaabbbcc";
   char* Result = stringCompression(Input);
   printf("%s\n",Result);
   free(Result);
   char Input1[MAXBUFLEN] = "aabbbcc";
   char* Result2 = stringCompression(Input1);
   printf("%s\n", Result2);
   free(Result2);
   char Input3[MAXBUFLEN] = "aaaaaaaaaaa";
   char* Result3 = stringCompression(Input3);
   printf("%s\n", Result3);
   free(Result3);
   return 0;
}
