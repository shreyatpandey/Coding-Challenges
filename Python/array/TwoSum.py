'''
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
No question of sorting as indices is required

Input = [3,3] , target = 6
Output:- [0,1]
'''
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        #return indices or two numbers
        
        for index,value in enumerate(nums):
            if target - value in hashMap:
                return {index,hashMap[target-value]}
            hashMap[value] = index
        


 
