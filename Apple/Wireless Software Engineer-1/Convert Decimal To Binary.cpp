#include<bits/stdc++.h>
using namespace std;

int main()
{
    uint8_t eightBitArray[8];
    uint8_t Val = 10;
    /*8-Bit Integer*/
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
    
    return 0;
}
