/*
Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.
*/
/*
Example 1:

Input: [2,2,3,2]
Output: 3

Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99
*/
//No extra-space
//Leetcode Solution
class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int seenonce = 0;
       int seentwice = 0;
     for(int nums:nums)
     {
         seenonce = ~(seentwice)&(seenonce^nums);
         seentwice = ~(seenonce)&(seentwice^nums);
     }
        return seenonce;
    }
};
