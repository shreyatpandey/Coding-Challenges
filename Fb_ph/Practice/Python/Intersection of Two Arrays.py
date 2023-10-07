'''
Given two integer arrays nums1 and nums2, return an array of their intersection. \
Each element in the result must be unique and you may return the result in any order.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
'''
'''
TC:- O(n)
SC:- O(n)
'''
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        set1 = set(nums1)
        set2 = set(nums2)
        Result = []
        for num in set2:
            if num in set1 and num in set2:
                Result.append(num)
        return Result
