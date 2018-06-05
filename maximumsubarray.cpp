#include<bits/stdc++.h>
using namespace std;

class Solution
{
   public:
     int max_subarray(vector<int>&nums)
    {
       int max_local_value = 0;
       int max_value = INT_MIN;
       for(size_t i=0;i<nums.size();i++)
      {
          max_local_value = max(nums[i], nums[i]+max_local_value);
          max_value = max(max_local_value, max_value);
      }
     return max_value;
   }
};

int main()
{
      Solution s;
      vector<int>input;
      input.push_back(-2);
      input.push_back(1);
      input.push_back(-3);
      input.push_back(4);
      input.push_back(-1);
      input.push_back(2);
      input.push_back(1);
      input.push_back(-5);
      input.push_back(4);
  
      cout<<"Maxmimum_Subarray_value:"<<s.max_subarray(input)<<endl;
      return 0;
} 
