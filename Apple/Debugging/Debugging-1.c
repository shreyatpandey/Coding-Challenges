#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void show_val_1(unsigned int num)
{
    printf("Number: %08x\n",num);
}
void show_val_2(signed int num)
{
    printf("Number: %08x", num);
}


int main()
{
    short num = -1;
    show_val_1(num);
    show_val_2(num);
    return 0;
}
