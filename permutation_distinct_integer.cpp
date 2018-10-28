#include<bits/stdc++.h>
using namespace std;

class Solution
{
   public:
	vector<vector<int>>permute(vector<int>&nums)
	{
	  vector<vector<int>>hold_result;
	  if(nums.size() == 1)
	  {
	    hold_result.emplace_back(nums);
	    return hold_result;
	  }
	  dfs_permute(nums,nums.size(),0,hold_result);
	  return hold_result;
	}
    private:
	void dfs_permute(vector<int>&nums,int size_nums,int position,vector<vector<int>>&hold_result)
	{
		if(position == size_nums)
	 	{
		  hold_result.emplace_back(nums);
		  return;
		}
	     for(int i=position;i<size_nums;i++)
	     {
		swap(nums[i],nums[position]);
	        dfs_permute(nums,size_nums,position+1,hold_result);
	    }
	  return;
	}
   };

int main()
{
  Solution s;
  vector<int>input = {1,2,3};
  vector<vector<int>>final_result = s.permute(input);
  cout<<"[";
  for(int i=0;i<final_result.size();i++)
  {
    cout<<"[";
    for(int j =0;j<final_result[i].size();j++)
    {
	cout<<final_result[i][j];
        if(j !=final_result[i].size()-1)
	{
         cout<<",";
	}
    }
   cout<<"]";
   if( i!= final_result.size() - 1)
    { 
      cout<<",";
    }
   }
 cout<<"]"<<endl;
 return 0;
}
      

