/*
Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. 
Find the two elements that appear only once. You can return the answer in any order.
*/
/*
Example 1:

Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.
*/
//No Extra Space
//Leetcode Solution
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
    // difference between two numbers (x and y) which were seen only once
    int bitmask = 0;
    for (int num : nums) bitmask ^= num;

    // rightmost 1-bit diff between x and y
    int diff = bitmask & (-bitmask);

    int x = 0;
    // bitmask which will contain only x
    for (int num : nums) if ((num & diff) != 0) x ^= num;

    return {x, bitmask^x};
        
    }
};
