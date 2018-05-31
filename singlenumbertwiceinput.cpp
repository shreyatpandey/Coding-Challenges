#include<bits/stdc++.h>
using namespace std;

class Solution
{
   public:
   int singleNumber(vector<int>&nums)
    {
       int store_result = 0;
       for(size_t i=0;i<nums.size();i++)
       {
            store_result = store_result^nums[i];
            cout<<"Store_result:"<<store_result<<endl;
            return store_result;
       }      

     }

};


int main()
{
  Solution s;
  vector<int>input;
  input.push_back(4);
  input.push_back(1);
  input.push_back(2);
  input.push_back(1);
  input.push_back(2);
  cout<<"Singel_Number:"<<s.singleNumber(input)<<endl;
  
 return 0;
}
