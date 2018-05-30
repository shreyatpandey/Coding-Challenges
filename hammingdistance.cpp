#include<bits/stdc++.h>
using namespace std;

/* Naive approach which does not use any bitwise operator */
vector<int>bits(int n)
{
   size_t new_number = n;
   size_t remainder=0;
   vector<int>result;
   while(new_number)
  {
    remainder = new_number%2;
    result.push_back(remainder);
    new_number = new_number/2;
    }

  return result;
}
void hamming_insert_zero_bits(int difference, vector<int>&nums)
{
   for(size_t i =0;i<difference;i++)
    {
       nums.push_back(0);
     }
  }

class Solution
{
   public:
   int hammingDistance(int x,int y)
   {
     vector<int>number1;
     vector<int>number2;
     number1 = bits(x);
     number2 = bits(y);
     size_t length1 = number1.size();
     size_t length2 = number2.size();
     int count=0;
     if(length1>length2)
    {
        int diff = length1-length2;
        hamming_insert_zero_bits(diff,number2);
        reverse(number1.begin(),number1.end());
        reverse(number2.begin(),number2.end());
        for(size_t i=0;i<number1.size();i++)
       {
        if(number1[i] != number2[i])
         {
           count+=1;
         }
        }
     }
    else
   {
       int diff = length2-length1;
        hamming_insert_zero_bits(diff,number1);
        reverse(number1.begin(),number1.end());
        reverse(number2.begin(),number2.end());
        for(size_t i=0;i<number1.size();i++)
       {
        if(number1[i] != number2[i])
         {
           count+=1;
         }
       }
    }

     return count;
 }

};

int main()
{
   Solution s;
   cout<<"Hamming_Distance:"<<s.hammingDistance(1,4)<<endl;
   return 0;
}
