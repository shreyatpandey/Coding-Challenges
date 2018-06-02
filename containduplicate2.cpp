#include<bits/stdc++.h>
using namespace std;

/* O(n^2) solution */
class Solution
{
  public:
   bool containsNearbyDuplicate(vector<int>&nums,int k)
   {
    size_t flag = 0;
     for(size_t i=0;i<nums.size();i++)
     {
       for(size_t j=i+1;j<nums.size();j++)
       {
	  if((abs(j-i)<=k) && nums[i]==nums[j])
         {
            flag = 1;
            break;
         }
     
        }

      }
     if ( flag==0) 
     return false;
    else;
    return true;
   }
};


/* O(n) solution using hash-map */
class Solution2
{
  public:
  bool containsNearbyDuplicate(vector<int>&nums,int k)
   {
      size_t flag = 0;
      unordered_map<int,int> hash;
      for(size_t i=0;i<nums.size();i++)
      {
        if( (hash.find(nums[i])) != hash.end())
         {
              if(abs(i-hash[nums[i]])<=k)
                {
                    flag=1;
                    break;
                 }
          }
        hash[nums[i]] = i;
      }
     if(flag == 0)
     return false;
     else
     return true;
 }
};


int main()
{
  Solution s;
  Solution2 s2;
  vector<int>input;
  input.push_back(1);
  input.push_back(2);
  input.push_back(3);
  input.push_back(1);
  cout<<"Contains_duplicate_Number_slowsolution:"<<boolalpha<<s.containsNearbyDuplicate(input,3)<<endl;  
  cout<<"Contains_duplicate_Number_hashmapsolution:"<<boolalpha<<s2.containsNearbyDuplicate(input,3)<<endl;
   
  return 0;

}
