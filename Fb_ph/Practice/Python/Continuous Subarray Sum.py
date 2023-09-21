'''
Given an integer array nums and an integer k, 
return true if nums has a continuous subarray of size at least two whose elements sum up to a multiple of k, 
or false otherwise.

An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.

 

Example 1:

Input: nums = [23,2,4,6,7], k = 6
Output: true
Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.
'''
'''
Approach:- Using HashMap / Dictionary
TC:- O(n)
SC:- O(n)
'''
class Solution:
    def checkSubarraySum(self, nums, k):
        if len(nums) < 2:
            return False

        # 0: -1 is for edge case that current sum mod k == 0
        # for when the current running sum is cleanly divisible by k
        # e.g: nums = [4, 2], k = 3
        sums = {0: -1}  # 0
        cumulative_sum = 0
        for idx, num in enumerate(nums):
            cumulative_sum += num
            remainder = cumulative_sum % k

            # if current_sum mod k is in dict and index idx - sums[remainder] > 1, we got the Subarray!
            # we use 2 not 1 because the element at sums[remainder] is not in the subarray we are talking about
            if remainder in sums and idx - sums[remainder] >= 2:
                return True

            # if current sum mod k not in dict, store it so as to ensure the further values stay
            if remainder not in sums:
                sums[remainder] = idx

# space can be easily improved to O(k) be only storing k elements in sums
