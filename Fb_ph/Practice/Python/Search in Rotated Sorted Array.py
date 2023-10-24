'''
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) 
such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, 
or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
'''
'''
Constraints:

1 <= nums.length <= 5000
-10^4 <= nums[i] <= 10^4
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-10^4 <= target <= 10^4
'''
'''
Complexity
Tc:- O(log(n))
Sc:- O(1)
'''
class Solution(object):
    def search(self, A, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        startIndex = 0
        endIndex = len(A)-1
        while startIndex <= endIndex:
            midVal = startIndex + (endIndex - startIndex)//2
            if A[midVal] == target:
                    return midVal
            if A[midVal]>=A[startIndex]:
                if A[midVal]>target and A[startIndex]<=target:
                    endIndex = midVal - 1
                else:
                    startIndex = midVal + 1
            else:
                if A[midVal]<target and A[endIndex]>=target:
                    startIndex = midVal + 1
                else:
                    endIndex = midVal - 1
        
        return -1
