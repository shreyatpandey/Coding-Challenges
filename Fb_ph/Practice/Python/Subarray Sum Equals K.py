'''
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2

Examnple 2:
Input: nums = [0,0,0,0,0,0,0,0] k= 0

'''
'''
TC:- O(n) where n is the length of the array
SC:- O(n) for hash Map
'''
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        frequency = {}
        Answer = 0;
        Sum = 0;
        for i in range(len(nums)):
            Sum += nums[i];
            if Sum == k :
                Answer += 1;
            if Sum-k in frequency:
                Answer += frequency[Sum-k];
            frequency[Sum] = frequency.get(Sum,0) + 1
        
        return Answer
    
