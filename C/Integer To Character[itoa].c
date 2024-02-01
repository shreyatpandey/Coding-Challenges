/* itoa */

#include<stdio.h>
#include<stdbool.h>
#define MAX 25600

void ReverseInteger ( char InputStr[],int length)
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
  int InputVal = -12;
  int LengthString = 0;
  char IntegerToChar [MAX];
  bool isNegative = false;
  if (InputVal < 0) 
  {
        isNegative = true;
        InputVal = -InputVal;
  }
  if(InputVal == 0)
  {
      IntegerToChar[LengthString++]='0';
      IntegerToChar[LengthString] = '\0' ;
  }
  else
  {
      while(InputVal)
      {
        int remainder = InputVal % 10;
        InputVal /= 10;
        if ( remainder > 9 )
        {
          IntegerToChar[LengthString++] = remainder + 55; //(int)'a' - 10
        }
        else
        {
          IntegerToChar[LengthString++] = remainder + 48; //(int)'0' - 48
        }
      }
      if(isNegative)
      {
          IntegerToChar[LengthString++] = '-';
      }
      IntegerToChar[LengthString] ='\0';
      ReverseInteger(IntegerToChar,LengthString);
  }
  printf("IntegerToChar:%s\n",IntegerToChar);
  return 0;
}
