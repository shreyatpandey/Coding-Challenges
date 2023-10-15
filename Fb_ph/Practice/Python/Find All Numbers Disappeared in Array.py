'''
Complexity:-
Tc:- O(n)
Sc:- O(1)
'''
class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        for i in range(len(nums)):
            newIndex = abs(nums[i])-1
            if nums[newIndex] > 0:
                nums[newIndex] *= -1
        Result = []
        for i in range(1,len(nums)+1):
            if nums[i-1] > 0:
                Result.append(i)
        return Result
