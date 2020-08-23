#include<bits/stdc++.h>
using namespace std;

/* Naive approach which does not use any bitwise operator but not so efficient*/
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
      int totalhammingdistance(vector<int>&nums)
      {
         sort(nums.begin(),nums.end());
         size_t count = 0;
         for(size_t i=0;i<nums.size();i++)
          {  
            
               for(size_t j=i+1;j<nums.size();j++)
               {
                 vector<int>num1 = bits(nums[i]);
                 vector<int>num2 = bits(nums[j]);
                 hamming_insert_zero_bits( num2.size() - num1.size(), num1);
                  reverse(num1.begin(),num1.end());
                 reverse(num2.begin(),num2.end());
                 for(size_t k = 0;k<num2.size();k++)
                  {
                    if(!(num1[k] == num2[k]))
                     {
                       count+=1;
                      }
                   }  
               
            }
     
      }       
   return count;
 }
};

int main()
{
    Solution s;
    vector<int>input;
    input.push_back(4);
    input.push_back(14);
    input.push_back(2);
    cout<<"Total_hamming_distance:"<<s.totalhammingdistance(input)<<endl;
    
    return 0;

}
               
            
