/*
CTCI
You have an integer and you can flip exactly one bit from a 0 to a 1. Write code to find the length of the longest sequence of 1s you could create.
Input:- 1775 ( or: 11011101111)
Output:- 8
*/
class Solution
{
  public:
    int flipBit(int a)
    {
      int currentlength = 0;
      int previouslength = 0;
      int maxlength = 1;
      while ( a!= 0)
      {
        if ( (a&1)==1) //current bit is 1
        {
          currentlength += 1;
        }
        else if ((a&1)==0) // current bit is 0
        {
          /* Update to 0 ( if next bit is 0) or currentlength ( if next bit is 1) */
          previouslength = (a&2) == 0?0:currentlength;
          currentlength = 0;
        }
        maxlength = max(previouslength+currentlength+1,maxlength);
        a >>=1;
      }
    return maxlength;
    }

};
