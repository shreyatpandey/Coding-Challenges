#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
   int no=38;
   int m=no;
   int sum=0;
   int remainder=0;
   while(no!=0 || sum>9) {
    if(no==0) {
      no = sum;
      sum =0;
    }
   remainder = no%10;
   sum+=remainder;
   no=no/10;
   
}
  printf("The required final digit is:%d\n",sum);
  return 0;
}
