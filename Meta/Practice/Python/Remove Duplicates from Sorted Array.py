'''
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. 
The relative order of the elements should be kept the same. 
Then return the number of unique elements in nums.
'''

'''
Input:-
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
'''

'''
Constraints:
1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100
nums is sorted in non-decreasing order.
'''

'''
Complexity:-
TC :- O(N)
SC:- O(1)
'''
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        original_length = 1
        if len(nums) == 0:
            return 0
        for i in range(1,len(nums)):
            if nums[i] != nums[i-1]:
                nums[original_length] = nums[i]
                original_length += 1
        return original_length
        
