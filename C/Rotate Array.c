#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void rotateArray(int* Input, int lengthOfArray, int k)
{
    int *rotateArray = (int*)malloc(lengthOfArray*sizeof(Input));
    int i;
    for(i=0;i<lengthOfArray;i++)
    {
        rotateArray[(i+k)%lengthOfArray] = Input[i];
    }
    for(i=0;i<lengthOfArray;i++)
    {
        Input[i] = rotateArray[i];
    }
}
int main()
{
    int Input[] = {1,2,3,4,5,6,7};
    int k = 3;
    int lengthOfArray = sizeof(Input)/sizeof(Input[0]);
    rotateArray(Input,lengthOfArray,k);
    int i;
    for(i=0;i<lengthOfArray;i++)
    {
        printf("%d",Input[i]);
        printf(" ");
    }
    return 0;
}
