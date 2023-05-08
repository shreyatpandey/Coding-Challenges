#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<stdint.h>
#include<stdbool.h>


void op_bit_set(unsigned char *data, int i)
{
    printf("i/8:%d\n",i/8);
    printf("data[i/8]:%x\n", data[i/8]);
    data[i/8] |= 0x80 >> (i%8); 
}

void op_bit_unset(unsigned char *data, int i)
{
     data[i/8] &= ~(0x80 >> (i%8)); 
}

void printElement(unsigned char* Input)
{
    unsigned char temp = Input[0];
    for(int i=0;i<8;i++)
    {
        if(temp & (0x80>>i))
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    printf("\n");
}

int main()
{
   unsigned char bitArray[1] = {0xab};
   //couting starts from left which is 0
   printElement(bitArray);
   op_bit_set(bitArray,3);
   printElement(bitArray);
   printf("%x\n", bitArray[0]);
   return 0;
}
