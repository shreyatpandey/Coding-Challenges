/*
Given a non-empty array of integers, 
every element appears three times except for one, which appears exactly once. Find that single one.
Example 1:

Input: [2,2,3,2]
Output: 3
Arrays are not sorted
*/
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
