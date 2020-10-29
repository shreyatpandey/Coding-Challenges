'''
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.
Example 1:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
'''
'''
Hash-Map Solution
Time Complexity:- O(n)
'''

class Solution(object):
    def findMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        map = {0:-1}
        maxlength = 0
        count = 0
        for i in range(len(nums)):
            if nums[i] == 1:
                count += 1
            else:
                count -= 1
            if count in map:
                maxlength = max(maxlength,i-map[count])
            else:
                map[count] = i
        
        return maxlength
