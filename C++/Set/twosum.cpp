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
  vector<int>twosum_2(vector<int>&nums,int target)
  {
	unordered_map<int,int>hash_map;
	vector<int>return_1;
	for(int i=0;i<nums.size();i++)
	{
		hash_map.emplace(i,nums[i]);
	}

	for(int j=0;j<nums.size();j++)
	{
		int result = target - nums[j];
		if(hash_map.find(result) != hash_map.end())
		{		
		return_1.push_back(hash_map[nums[j]]);
		return_1.push_back(j);
		return return_1;
		}
	}
   return return_1;
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

/* Approach - 2*/
lass Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int index1 = 0, index2 = 0;
        auto process_and_lookup = ( [ m = unordered_map<int,int>(),
                                    i = 0,
                                    target,
                                    &index1,&index2 ] ( const auto item) mutable {
            auto iter = m.find(target-item) ;
            if (iter == cend(m))
            {
                m[item] = i++;
                return false;
            }
            index1 = iter->second;
            index2 = i ;
            return true;
        }) ;
        
        auto iter = find_if(cbegin(nums),cend(nums),process_and_lookup);
        if( iter != cend(nums))
        {
            return {index1,index2};
        
        }
                                   
        return {index1,index2};                              
        
    }
};
