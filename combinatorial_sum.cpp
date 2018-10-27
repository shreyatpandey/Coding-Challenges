#include<bits/stdc++.h>
using namespace std;

class Solution
{
  public:
	vector<vector<int>>combinationSum(vector<int>&candidates,int target)
	{
	 vector<vector<int>>hold_result;
	 vector<int>each_step;
	 sort(candidates.begin(),candidates.end());
	 dfs(candidates,0,0,candidates.size(),target,each_step,hold_result);
	 return hold_result;
        }
  private:
	void dfs(vector<int>&input,int start_value,int present_step,int size,int target,vector<int>&each_step,vector<vector<int>>&hold_result)
	{
           if(present_step == target)
	  {
	   hold_result.push_back(each_step);
	   return ;
	   }
	
          for(int i=start_value;i<size;i++)
	{
	  if(present_step + input[i] > target)
	  {
	    return;
	  }
	  
	    each_step.emplace_back(input[i]);
	    dfs(input,i,present_step+input[i],size,target,each_step,hold_result);
	    each_step.pop_back();
	}
	return;
 }
};

int main()
{
  Solution s;
  vector<vector<int>>hold_result;
  vector<int>input = {2,3,6,7};
  hold_result = s.combinationSum(input,7);
  vector<int>::iterator it;
  cout<<"[";
  for(int i=0;i<hold_result.size();i++)
  {
    cout<<"[";
    for(int j=0;j<hold_result[i].size();j++)
     {
      cout<<hold_result[i][j];
     if( j != hold_result[i].size()-1 )
        cout<<",";
      }
   cout<<"]";
   if(i != hold_result.size()-1)
    cout<<",";
  }
 cout<<"]"<<endl;
 return 0;

}

	  
