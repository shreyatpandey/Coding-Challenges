'''
Given an integer array nums, find the 
subarray with the largest sum, and return its sum.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
'''
'''
Kadane's Algorithm
Tc:- O(n)
Sc:- O(1)
'''
class Solution:
    def maxSubArray(self, nums):
        # Initialize our variables using the first element.
        current_subarray = max_subarray = nums[0]
        
        # Start with the 2nd element since we already used the first one.
        for num in nums[1:]:
            # If current_subarray is negative, throw it away. Otherwise, keep adding to it.
            current_subarray = max(num, current_subarray + num)
            max_subarray = max(max_subarray, current_subarray)
        
        return max_subarray

if __name__ == '__main__':
    print("Test Case")
    nums = [-2,1,-3,4,-1,2,1,-5,4]
    s = Solution()
    print(s.maxSubArray(nums))
    
