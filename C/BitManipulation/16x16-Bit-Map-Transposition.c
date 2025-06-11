#include <stdio.h>
#include<stdint.h>
#include<math.h>


int main()
{
    uint16_t InputArray[16] ={0xaaab,0xabab,0xabcd,0x5555,
                              0x6666,0x7777,0x8888,0xbbbb,
                              0xcccc,0xdcba,0x1234,0xcdab,
                              0x5214,0x6789,0xdddd,0x7654};
    uint16_t Array2D[16][16] ;
    uint32_t k = 0;
    
    //Input array
    printf("-------|InputArray-Display|-------\n");
    for(int i=0;i<16;i++)
    {
        printf("%u ", InputArray[i]);
    }
    printf("\n");
    //store in 2-D bit array
    for(int i=0;i<16;i++)
    {
       for(int j=0;j<16;j++)
        {
            if(InputArray[i] & (0x8000>>j))
            {  
                Array2D[i][j] = 1;
            }
            else
            {   
                Array2D[i][j] = 0;
            }
        }
    }
    printf("-------|2DArray|-------\n");
    for(int i=0;i<16;i++)
    {
        for(int j=0;j<16;j++)
        {
            printf("%u",Array2D[i][j]);
        }
        printf("\n");
    }
    
    //Transpose this 2DArray;
    for(int i=0;i<16;i++)
    {
        for(int j=0;j<i;j++)
        {
            uint16_t temp = Array2D[i][j];
            Array2D[i][j] = Array2D[j][i];
            Array2D[j][i] = temp ;
        }
    }
    //Print Transpose Matrix
    printf("-------|Transpose-Matrix|-------\n");
    for(int i=0;i<16;i++)
    {
        for(int j=0;j<16;j++)
        {
            printf("%u",Array2D[i][j]);
        }
        printf("\n");
    }
    //convert into 1D array
    uint16_t SingleArray[16*16];
    for(int i=0;i<16;i++)
    {
        for(int j=0;j<16;j++)
        {
            SingleArray[k] = Array2D[i][j] ;
            k++;
        }
    }
    printf("\n");
    //convert into decimal
    int n = 0;
    for(int i=0;i<(16*16);i += 16)
    {
        uint16_t number = 0;
        int m = i;
        for(int j=15;j>=0;j--)
        {
            number += (SingleArray[m++]*((uint16_t)1<<j)) ;
        }
        InputArray[n++] = number;
        printf("number:%u\n",number);
    }
    //Print InputArray
    //Transpose 1d Array
    printf("-------|Transpose 1D Array|-------\n");
    for(int i=0;i<16;i++)
    {
        printf("%u ",InputArray[i]);
    }
    printf("\n");

    return 0;
}
