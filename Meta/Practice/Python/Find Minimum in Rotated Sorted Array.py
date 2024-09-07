'''
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. 
For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 
1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.

 

Example 1:

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
'''
'''
Constraints:

n == nums.length
1 <= n <= 5000
-5000 <= nums[i] <= 5000
All the integers of nums are unique.
nums is sorted and rotated between 1 and n times.
'''
'''
Not a traditional array.
If entire array is 'n' times, 
Way-1
Find the pivot where the element is not in increasing order,
Inflection point
Way-2
find middlevalue, 
Are we going to search on the left or on the right?
Since we have rotated the array, we have two sorted portion of the array.
One on the left sorted portion and one on the right sorted array
Right would likely would be lower in value
If the current middle value is greater than or equal to all the value to the leftmostvalue

[3,4,5,1,2]
middValue = 5
nums[m]>= nums[l]
 True , 5>=3
 search right,
 left = mid+1
 else:
     search left
'''
'''
Complexity
Tc:- O(log(n))
Sc:- O(1)
'''
class Solution:
    def findMin(self, nums: List[int]) -> int:
        result = nums[0] # arbitrary value
        l,r = 0, len(nums)-1
        while l<=r :
            if nums[l] < nums[r] :
                result = min(result,nums[l])
                break
            m = (l+r)//2
            result = min(result,nums[m])
            if nums[m] >= nums[l]:
                l = m + 1
            else:
                r = m-1
        return result
