#include<bits/stdc++.h>
using namespace std;

class Solution
{
 
   public:
   vector<int>twosum(vector<int>&nums,int target)
    {
      unordered_map<int,int> hash;
      int length = nums.size();
      for(int i=0;i<length;i++)
       {
         if(hash.count(target-nums[i]))
         {
             return {hash[target-nums[i]],i};
          }
        hash[nums[i]]=i;
      }
    }
 };
int main()
{
   vector<int>v;
   v.push_back(2);
   v.push_back(7);
   v.push_back(11);
   v.push_back(15);
  Solution s;
  vector<int>result;
  result=s.twosum(v,13);
  vector<int>::iterator it;
  for(it=result.begin();it!=result.end();++it)
   {
     cout<<(*it)<<endl;
   }
  return 0;
}
