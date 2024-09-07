'''
Given a binary array nums, return the maximum number of consecutive 1's in the array.

Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
Example 2:

Input: nums = [1,0,1,1,0,1]
Output: 2
'''
'''
Approach - 1:
TC:- O(n)
SC:- O(1)
'''
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        count = 0
        maxOnes = 0
        l = 0
        while l <len(nums):
            if nums[l] == 1:
                count += 1
            else:      
                maxOnes = max(maxOnes,count)
                count = 0
            l += 1
        return max(maxOnes,count)
 
 
'''
Approach-2:- My Solution
TC:- O(n)
SC:- O(1)
'''
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        count = 0
        maxOnes = 0
        l = 0
        while l <len(nums):
            while l < len(nums) and nums[l] != 0:
                count += 1
                l += 1
            maxOnes = max(maxOnes,count)
            count = 0
            l += 1
        return maxOnes
