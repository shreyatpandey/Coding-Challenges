#include <bits/stdc++.h>
using namespace std;


#define EightBit 0x80
#define SixteenBit 0x8000

int main()
{
    uint8_t hexaVal = 0xab;
    /* 8 bit integer array*/
    uint8_t bitArray[8] ;
    for(int i=0;i<8;i++)
    {
        if(hexaVal & (EightBit>>i))
        {
            bitArray[i] = 1;
        }
        else
        {
            bitArray[i] = 0;
        }
    }
    /*print 8-Bit Array*/
    printf("8-Bit Array\n");
    for(int i=0;i<8;i++)
    {
        printf("%u",bitArray[i]);
    }
    printf("\n");
    /*16-Bit Val */
    uint16_t hexaVal2 = 0xaacc;
    /*16-bit integer array*/
    uint16_t hexaBitArray[16] ;
    for(int i=0;i<16;i++)
    {
        if(hexaVal2 & (SixteenBit>>i))
        {
            hexaBitArray[i] = 1;
        }
        else
        {
            hexaBitArray[i] = 0;
        }
    }
    printf("16-Bit array\n");
    /* print 16-Bit array*/
    for(int k = 0;k<16;k++)
    {
        printf("%u",hexaBitArray[k]);
    }
    
    return 0;
}
