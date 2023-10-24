'''
here is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) 
such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, 
or false if it is not in nums.

You must decrease the overall operation steps as much as possible.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
'''
'''
Constraints:

1 <= nums.length <= 5000
-10^4 <= nums[i] <= 10^4
nums is guaranteed to be rotated at some pivot.
-10^4 <= target <= 10^4
'''
'''
In rotated sorted array,
Difficult problem why?
how do we know, if we are in the right half or left half
'''
'''
Approach:- Binary Search
Complexity
Tc:- O(log(n))
Sc:- O(1)
'''
class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        left, right = 0, len(nums)-1
        while left<= right:
            mid = left + (right-left)//2
            if nums[mid] == target:
                return True
            if nums[left] < nums[mid]: #left position
                if nums[left]<= target < nums[mid]:
                    right = mid-1
                else:
                    left = mid + 1
            
            elif nums[left]>nums[mid]: # right position
                if nums[mid]< target <= nums[right]: # why not equality why because we have already checked the equality previously
                    left = mid + 1
                else:
                    right = mid - 1
            else:
                left += 1
        
        return False

