#include<stdio.h>
#define Max 25600

int main()
{
  char HexaDecimal[MAX];
  int InputVal = 125;
  int HexaDecimalLength = 0;
  while(InputVal)
  {
    int remainder = InputVal % 16;
    InputVal /= 16;
    if ( remainder > 9)
    {
      HexaDecimal[HexaDecimalLength++] = remainder + 55 ; //(int)'a' - 10
    }
    else
    {
      HexaDecimal[HexaDecimalLength++] =  remainder + 48 ; //(int)'48'
    }
  
  }
HexaDecimal[HexaDecimalLength] = '\0';
printf("HexaDecimal:%s\n",HexaDecimal);
return 0;
}
