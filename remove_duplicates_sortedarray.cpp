#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	   int removeDuplicates(vector<int>& nums)
	   {
	     int index_store_number=0;
	     int i,z;
	     
	     BEGIN:for(i=0;i<nums.size();++i)
	      {
	          for(z=0;z<nums.size();++z)
	           {
	               if(i==z)
	                { 
                      continue;
	                  }
	                 if(nums[i]==nums[z])
	                 {
	                   nums.erase(nums.begin() + z);
	                   goto BEGIN;

	                 }

	           }

	      }
	     return (nums.size());

	   }
};

int main()
{
	  vector<int> v;
	   v.push_back(1);
	  v.push_back(2);
	  v.push_back(2);
	  v.push_back(4);
	  v.push_back(4);

	  Solution s;
	  int answer = s.removeDuplicates(v);  //this is how you pass vector as a function
	  cout<<"Length:"<<answer<<endl;
	  return 0;


}
