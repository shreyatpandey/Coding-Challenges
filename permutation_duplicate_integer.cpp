#include<bits/stdc++.h>
using namespace std;

class Solution
{
 public:
   vector<vector<int>> permuteUnique(vector<int>&nums)
   {
	vector<vector<int>>hold_result;
	vector<int>each_step;
 	vector<bool>trace_hold(nums.size());
 	sort(nums.begin(),nums.end());
	if(nums.size() == 1)
	{
	  hold_result.push_back(nums);
	  return hold_result;
	}
	dfs_permute_unique(nums,nums.size(),trace_hold,each_step,hold_result);
	return hold_result;
  }
private:
  void dfs_permute_unique(vector<int>&nums,int size,vector<bool>&trace_hold,vector<int>&each_step,vector<vector<int>>&hold_result)
  {
    if( each_step.size() == size)
    {
         hold_result.push_back(each_step);
	return;
    }
  for(int i=0;i<size;i++)
  {
     if(i>0  && !trace_hold[i-1] && nums[i] == nums[i-1])  
     {
       continue;
     }
    if(trace_hold[i] == false)
    {
      trace_hold[i] = true;
      each_step.push_back(nums[i]);
      dfs_permute_unique(nums,size,trace_hold,each_step,hold_result);
      each_step.pop_back();
     trace_hold[i] = false;
   }
 }
return;
}
};

int main()
{
  Solution s;
  vector<int>input = {1,1,2};
  vector<vector<int>>hold_result = s.permuteUnique(input);
  cout<<"[";
  for(int i=0;i<hold_result.size();i++)
  {
    cout<<"[";
     for(int j=0;j<hold_result[i].size();j++)
	{
  	   cout<<hold_result[i][j];
	   if( j != hold_result[i].size() - 1)
		cout<<",";
	  }
	cout<<"]";
	if(i != hold_result.size() - 1)
	cout<<",";
  }
 cout<<"]"<<endl;
  return 0;
}
