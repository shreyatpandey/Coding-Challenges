'''
A peak element is an element that is strictly greater than its neighbors.

Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞.

You must write an algorithm that runs in O(log n) time.

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
'''
'''
Hint:-
-2**31 <= nums[i] <= 2**31 - 1
nums[i] != nums[i+1] for all valid i
'''
'''
Approach:- Binary Search 
TC:- O(log2(N))
SC:- O(1)
'''

class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        left , right = 0, len(nums)-1
        while left < right:
            mid = (left + right) // 2
            if nums[mid] > nums[mid+1]:
                right = mid
            else:
                left = mid + 1
        return left
