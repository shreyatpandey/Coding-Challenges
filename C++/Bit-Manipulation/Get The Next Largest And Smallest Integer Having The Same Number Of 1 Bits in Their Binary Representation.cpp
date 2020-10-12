//CTCI
class Solution
{
  public:
    int NextLargest(int Input)
    {
      int Value = Input;
      int NumberOfZeros = 0;
      int NumberOfOnes = 0;
      while ( (Value & 1)==0 && ( Value != 0))
      {
        NumberOfZeros += 1;
        Value >>= 1;
      }
      while( (Value&1)==1)
      {
        NumberOfOnes += 1;
        Value >>= 1;
      }
      /*Error case for Integer Overflow */
      if ( NumberOfZeros + NumberOfOnes == 31 || NumberOfZeros + NumberOfOnes == 0)
      {
        return -1;
      }
      int p = NumberOfOnes + NumberOfZeros; //position of rightmost non-trailing zero
      Input |= ( 1<<p); // Flip rightmost non-trailing zero
      Input &= ~((1<<p) - 1 ); //Clear all the bits to the right of p
      Input |= (1<<(NumberOfOnes-1))-1; //Insert (NumberOfOnes-1) ones on the right
      return Input;
      
     }
    int PrevSmallest ( int Input)
    {
            int temp = Input;
            int c0 = 0;
            int c1 = 0;
            while ( temp & 1 == 1)
            {
                c1 += 1;
                temp >>= 1;
            }
            if ( temp == 0 ) return -1;
            while (((temp&1) == 0) && ( temp != 0))
            {
                c0 += 1;
                temp >>= 1;
            }
            int p = c0 + c1; //position of rightmost non-trailing one
            Input &= ((~0)<<(p+1)); //clears from bit p onwards
            std::cout<<"Input:"<Input<<std::endl;
            int mask = (1<<(c1+1))-1; // Sequence of (c1+1) ones
            std::cout<<"mask:"<<mask<<std::endl;
            Input |= mask<<(c0-1);
            return Input;
    }
      
  };
    
