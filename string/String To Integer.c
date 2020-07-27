/* itoa */
#define MAX 25600
void ReverseInteger ( char InputStr[],int length)
{
  for(int i=0;i<length/2;i++)
  {
    char temp = InputStr[i];
    Input[i] = InputStr[length-i-1];
    Input[length-i-1] = temp;
  }

}

int main()
{
  int InputVal = 35567 ;
  int LengthString = 0;
  char IntegerToChar [MAX];
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
  IntegerToChar[LengthString] = '\0' ;
  ReverseInteger(IntegerToChar,LengthString);
 
 return 0;
}

