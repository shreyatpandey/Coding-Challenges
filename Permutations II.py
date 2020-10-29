'''
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
'''
'''
No-Recursion
'''

class Solution(object):
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        permutations = [[]]
        for num in nums:
            next = []
            for permutation in permutations:
                for i in range(len(permutation) + 1):
                    candidate = permutation[:i] + [num] + permutation[i:]
                    if candidate not in next:
                        next.append(candidate)
                
            permutations = next 
            
        return permutations
