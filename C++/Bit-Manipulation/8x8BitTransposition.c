#include <stdio.h>
#include<stdint.h>
#include<math.h>

//8x8 bit transposition
int main()
{
    uint32_t InputArray[16] ={0xab,0xba,0xcd,0x55,
                              0x66,0x77,0x88,0xbb,
                              };
    uint32_t Array2D[8][8] ;
    uint32_t k = 0;
    
    //Input array
    printf("-------|InputArray-Display|-------\n");
    for(int i=0;i<8;i++)
    {
        printf("%u ", InputArray[i]);
    }
    printf("\n");
    //store in 2-D bit array
    for(int i=0;i<8;i++)
    {
       for(int j=0;j<8;j++)
        {
            if(InputArray[i] & (0x80>>j))
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
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            printf("%u",Array2D[i][j]);
        }
        printf("\n");
    }
    //Transpose this 2DArray;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<i;j++)
        {
            uint32_t temp = Array2D[i][j];
            Array2D[i][j] = Array2D[j][i];
            Array2D[j][i] = temp ;
        }
    }
    //Print Transpose Matrix
    printf("-------|Transpose-Matrix|-------\n");
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            printf("%u",Array2D[i][j]);
        }
        printf("\n");
    }
    //convert into 1D array
    uint32_t SingleArray[8*8];
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            SingleArray[k] = Array2D[i][j] ;
            k++;
        }
    }
    printf("\n");
    //convert into decimal
    int n = 0;
    for(int i=0;i<(8*8);i += 8)
    {
        int number = 0;
        int m = i;
        for(int j=8;j>=0;j--)
        {
            number += (SingleArray[m++]*pow(2,j)) ;
        }
        InputArray[n++] = number;
        printf("number:%u\n",number);
    }
    //Print InputArray
    //Transpose 1d Array
    printf("-------|Transpose 1D Array|-------\n");
    for(int i=0;i<8;i++)
    {
        printf("%u ",InputArray[i]);
    }
    printf("\n");
   
    return 0;
}
