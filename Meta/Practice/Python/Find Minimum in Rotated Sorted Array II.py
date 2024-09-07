'''
Suppose an array of length n sorted in ascending order is rotated between 1 and n times.
For example, the array nums = [0,1,4,4,5,6,7] might become:

[4,5,6,7,0,1,4] if it was rotated 4 times.
[0,1,4,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums that may contain duplicates, return the minimum element of this array.

You must decrease the overall operation steps as much as possible.

 

Example 1:

Input: nums = [1,3,5]
Output: 1
'''
'''
Constraints:

n == nums.length
1 <= n <= 5000
-5000 <= nums[i] <= 5000
nums is sorted and rotated between 1 and n times.
'''
'''
Complexity
TC:- O(log(n))
Sc :- O(1)
'''
class Solution:
    def findMin(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1
        while (left < right):
            mid = left + (right - left) // 2
            if (nums[mid] < nums[right]):
                right = mid
            elif (nums[mid] > nums[right]):
                left = mid + 1
            else: 
                right -= 1
        return nums[left]
