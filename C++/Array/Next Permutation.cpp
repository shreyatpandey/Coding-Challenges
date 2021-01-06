/*

Input: nums = [1,2,3]
Output: [1,3,2]

Input: nums = [1,1,5]
Output: [1,5,1]
*/
/*
Taken from leetcode solution
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
         if (nums.empty()) return;
        
        // in reverse order, find the first number which is in increasing trend (we call it violated number here)
        int i;
        for (i = nums.size()-2; i >= 0; --i)
        {
            if (nums[i] < nums[i+1]) break;
        }
        
        // reverse all the numbers after violated number
        reverse(nums.begin()+i+1, nums.end());
        // if violated number not found, because we have reversed the whole array, then we are done!
        if (i == -1) return;
        // else binary search find the first number larger than the violated number
        auto itr = upper_bound(nums.begin()+i+1, nums.end(), nums[i]);
        // swap them, done!
        swap(nums[i], *itr);
    }
};
