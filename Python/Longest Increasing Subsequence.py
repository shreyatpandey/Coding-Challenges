'''
Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
'''
class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        numslength = len(nums)
        if numslength == 0:
            return 0
        dp = [0]*numslength
        dp[0] = 1
        maximumans = 1
        for i in range(1,numslength):
            maxvalue = 0
            for j in range(0,i):
                if nums[i] > nums[j] :
                    maxvalue = max(maxvalue,dp[j])
            dp[i] = maxvalue + 1;
            maximumans = max(maximumans,dp[i])
        
        return maximumans
        
