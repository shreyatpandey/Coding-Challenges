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

'''
Complexity:-
Tc:- O(n*log(n))
Sc:- O(1)
'''
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1 = sorted(nums1)
        nums2 = sorted(nums2)
        p1 = 0
        p2 = 0
        
        r = set()
        while p1 < len(nums1) and p2 < len(nums2):
            val1 = nums1[p1]
            val2 = nums2[p2]
            if val1 == val2:
                r.add(val1)
                p1 += 1
            elif val1 < val2:
                p1 +=1
            elif val1 > val2:
                p2 += 1
                
        return r
