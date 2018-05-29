#include<bits/stdc++.h>
using namespace std;

/* Naive approach*/
class Solution
{
  public:
   int hammingweight(uint32_t n)
  {
     vector<int>result;
   int new_number = n;
   int i=0,count = 0;
   if (n==0)
   return 0;

   else
   {
      while(new_number)
     {
       int remainder = new_number%2;
       new_number = new_number/2;
       result.push_back(remainder);
       i++;
      }
    }
   for(i=0;i<result.size();i++)
   {
     if(result[i] == 1)
      count+=1;
    }
  return count;
}
}; 

/*Brian Kernigham's algorithm*/
class Solution2
{
  public:
   int hammingweight(uint32_t n)
   {
      int count=0;
      if (n==0)
      return 0;
    
      while(n)
      {
           n = n&(n-1); /* Bitwise And*/
           count+=1 ;
       }
     return count;
    }
};    


int main()
{
   Solution s;
   Solution2 s2;
  size_t result_naive = s.hammingweight(11);
  size_t result_bkalgo = s2.hammingweight(11);
  cout<<"Naive Approach:"<<result_naive<<endl;
  cout<<"Brian Kernigham's Algorithm:"<<result_bkalgo<<endl;
  return 0;
}        
