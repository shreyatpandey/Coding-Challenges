/*
Question:- Return Indices of the two number and not the number
[3,3] Target:- 6
Ans:- [0,1]
Will still work

Clarifying question :- Do we need to return the number or only the indices?

Constraints-Memorize:-
You may assume that each input would have exactly one solution, and you may not use the same element twice
Only one valid answer exists.
*/

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
