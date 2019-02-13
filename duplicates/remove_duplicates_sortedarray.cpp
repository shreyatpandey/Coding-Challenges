#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	   int removeduplicates_1(vector<int>& nums) /*Minimum memory complexity*/
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
	int removeduplicates_2(vector<int>& nums)
	{
		vector<int>return_list;
		vector<int>::iterator it;
    		for(int i=0;i<nums.size();i++)
    		{
        		it = find(return_list.begin(),return_list.end(),nums[i]);
        		if(!(it != return_list.end()))
        		{
            			return_list.emplace_back(nums[i]);
        		}
    		}
    	return return_list.size();	
	
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
	  int answer = s.removeduplicates_1(v);
	  int answer_1 = s.removeduplicates_2(v);
	  cout<<"Length_1:"<<answer<<endl;
	  cout<<"Length_2:"<<answer_1<<endl;
	  return 0;


}
