'''
Given an integer array nums, 
return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:

Input: nums = [1,2,3,1]
Output: true

Example 2:
Input: nums = [1,2,3,4]
Output: false
'''
'''
Constraints:
1 <= nums.length <= 10^5
-109 <= nums[i] <= 10^9
'''
'''
Complexity:-
TC:- O(n)
SC:- O(n) for the extra hash set
'''
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        return True if len(nums)>len(set(nums)) else False
