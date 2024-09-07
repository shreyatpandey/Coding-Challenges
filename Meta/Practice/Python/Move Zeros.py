'''
Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 
Constraints:
1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1

Follow up: Could you minimize the total number of operations done?
'''

'''
Approach:-1
TC:- O(n)
SC:- O(1)
total number of writes in still n times

'''
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        noOfNonZeros = 0
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[noOfNonZeros] = nums[i]
                noOfNonZeros += 1
        for i in range(noOfNonZeros,len(nums)):
            nums[i] = 0

'''
Approach:- 2
TC:- O(n)
SC:- O(1)
This method involves Swapping.
Issues with this approach:-
 1.Swap is not counted as single operation.
 2. Say for [0,1,1,1,1]
 3. Swapping would involve writing 2*n times
 4. For all non-zeros elements
'''
class Solution:
  def moveZeroes(self, nums: List[int]) -> None:
      """
      Do not return anything, modify nums in-place instead.
      """
      
      noOfNonZeros = 0
      for i in range(len(nums)):
          if nums[i] != 0:
              nums[noOfNonZeros] = nums[i]
              noOfNonZeros += 1
      for i in range(noOfNonZeros,len(nums)):
          nums[i] = 0
