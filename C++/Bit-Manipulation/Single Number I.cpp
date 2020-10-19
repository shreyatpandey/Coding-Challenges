/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
*/
/*
Example 1:

Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
      if ( !nums.size())
          return 0;
    int firstelement = 0;
    for(int i=0;i<nums.size();i++)
    {
        firstelement ^= nums[i];
    }
        return firstelement;
    }
};
