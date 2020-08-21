#include<bits/stdc++.h>
using namespace std;

class Solution
{
  public:
   int majorityelement(vector<int>&nums)
    {
      
      unordered_map<int,int>hash;
      for(size_t i=0;i<nums.size();i++)
      {
         if(nums.size()/2 < ++hash[nums[i]])
          return nums[i];

     }
 }
  };

int main()
{
  Solution s;
  vector<int>input;
  input.emplace_back(2);
  input.emplace_back(2);
  input.emplace_back(2);
  input.emplace_back(1);
  input.emplace_back(1);
  input.emplace_back(1);
  input.emplace_back(2);
  input.emplace_back(2);
  cout<<"Majority_element:"<<s.majorityelement(input)<<endl;

  return 0;
}

