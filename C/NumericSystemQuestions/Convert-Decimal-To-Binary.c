//This would work for hexadcimal values as well
#include<stdio.h>
#include<stdint.h>

// First method shift 1
// This method is used to convert decimal to binary using bitwise operations
// It uses the right shift operator to check each bit of the number
// and stores the result in an array of 8 bits.
void method_shift1(uint8_t Val, uint8_t *eightBitArray)
{
    for(int i=7;i>=0;i--)
    {
        if((Val>>i)&1)
         eightBitArray[i] = 1;
         
         else 
            eightBitArray[i] = 0;
    }
    for(int i=7;i>=0;i--)
    {
        printf("%u",eightBitArray[i]);
    }
}

// Second method shift 1
// This method is similar to the first one but uses the left shift operator
// It checks if the bit at position i is set in the value and stores the result
// in an array of 8 bits.
void method_shift2(uint8_t Val, uint8_t *eightBitArray)
{
    for(int i=7;i>=0;i--) 
    {
        if((1<<i)&Val)
         eightBitArray[i] = 1;
         
         else 
            eightBitArray[i] = 0;
    }
    for(int i=7;i>=0;i--)
    {
        printf("%u",eightBitArray[i]);
    }
}

int main()
{
    uint8_t eightBitArray[8];
    uint8_t Val = 10;
    printf("Method 1: Using Right Shift\n");
    method_shift1(Val, eightBitArray);
    printf("\nMethod 2: Using Left Shift\n");
    method_shift2(Val, eightBitArray);
    printf("\n");
    return 0;
}
// This code converts a decimal number to its binary representation using two methods.