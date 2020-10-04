//Source :- CTCI
class Solution
{
  private:
    int sign(int input);
    int flip(int bit);
  public:
    int MaxOfTwoNumber ( int a, int b)
    {
          int c = a - b;
          int sa = sign(a); // if a>=0 , then 1 else 0
          int sb = sign(b); // if b>=0 , then 1 else 0
          int sc = sign(c); // depends on whether or not a-b overflow
          
          //If a and b have different signs, then k = sign(a)
          int use_sign_of_a = sa^sb ;
          
          //If a and b have the same sign, then k = sign(a-b)
          int use_sign_of_c = flip(sa^sb);
          
          int k = use_sign_of_a*sa + use_sign_of_c*sc ;
          
          int q = flip(k); //opposite of k
          
          return a*k + b*q;
    
    }
};
int Soluton::sign(int input)
{
  return flip ((input>>31)&0x1);
}
int Solution::flip(int bit)
{
 return 1^bit;
}
