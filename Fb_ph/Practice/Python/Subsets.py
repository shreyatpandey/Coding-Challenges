'''
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
'''
'''
Constraints:-
1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
'''
'''
Complexity:-
TC:- O(N*2^N) to generate all possible susbsets
SC:- O(N) where N is the number of recursion stack we have to maintain
'''

class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        self.backtracking(res,0,[],nums)
        return res
    def backtracking(self,res,start,subset,nums):
        res.append(list(subset))
        for i in range(start,len(nums)):
            subset.append(nums[i])
            self.backtracking(res,i+1,subset,nums)
            subset.pop()
