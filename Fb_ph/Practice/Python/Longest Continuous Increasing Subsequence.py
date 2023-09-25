'''
Given an unsorted array of integers nums, return the length of the longest continuous increasing subsequence (i.e. subarray). 
The subsequence must be strictly increasing.
A continuous increasing subsequence is defined by two indices l and r (l < r) 
such that it is [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] and for each l <= i < r, nums[i] < nums[i + 1].
'''
'''
Constraints:
1 <= nums.length <= 10^4
-10^9 <= nums[i] <= 10^9
'''
'''
Approach:- Two Pointer
TC:- O(n) where n is the length of nums
SC:- O(1) as we are using constant space
'''
class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        if not nums:
            return 0

        cur_len = 1
        max_len = 1

        for i in range(1,len(nums)):
            if nums[i] > nums[i-1]:
                cur_len += 1
            else:
                max_len = max(max_len,cur_len)
                cur_len = 1

        return max(max_len,cur_len)
