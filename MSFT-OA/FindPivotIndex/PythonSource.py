'''
TC:- O(N^2)
TLE
'''
class Solution(object):
    def pivotIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        leftSum = 0
        for i in range(0,len(nums)):
            leftSum += nums[i]
            rightSum = 0
            for j in range(i+1,len(nums)):
                rightSum += nums[j]
            if leftSum -nums[i] == rightSum :
                return i
        return -1
      
  '''
TC:- O(N)
'''
class Solution1(object):
    def pivotIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        TotalSum = sum(nums)
        leftSum = 0
        for i in range(0,len(nums)):
            leftSum += nums[i]
            if leftSum - nums[i] == TotalSum - leftSum  :
                return i
        return -1
