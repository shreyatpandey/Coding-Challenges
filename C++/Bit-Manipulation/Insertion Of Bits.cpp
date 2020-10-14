//Source:- CTCI
/* You are given two 32-bit numbers, N and M, and two bit positions,i and j. Write a method to insert M into N
such that M starts at bit j and ends at bit i. You can assume that the bits j through i have enough space to fit all of M.
Example:-
Input: N = 100000000000 , M = 10011, i = 2 and j =6
Output: N = 10001001100
*/
int updateBits ( int n,int m,int i,int j)
{
  /* Create a mask to clear bits i through j in n. */
  int allOnes = ~0;
  
  //1s before position j, then 0s. left = 11100000
  int left = allOnes<<(j+1) ;
  
  //1's after position i. right = 00000011
  int right = ((1<<i)-1);
  
  //All 1s, except for 0s between i and j. mask = 11100011
  int mask = left | right;
  
  /* Clear bits j through i then put m in there */
  int n_cleared = n & mask; //Clear bits j through i
  int m_shifted = m<<i; //Move m into correct position

  return n_cleared | m_shifted; //OR them

}
