#include<stdio.h>
#define MAX 25600

void ReverseHexaDecimal ( char InputStr[],int length)
{
  for(int i=0;i<length/2;i++)
  {
    char temp = InputStr[i];
    InputStr[i] = InputStr[length-i-1];
    InputStr[length-i-1] = temp;
  }

}

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
ReverseHexaDecimal ( HexaDecimal, HexaDecimalLength );
printf("HexaDecimal:%s\n",HexaDecimal);
return 0;
}
