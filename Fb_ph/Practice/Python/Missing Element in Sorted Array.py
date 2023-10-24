'''
Given an integer array nums which is sorted in ascending order and all of its elements are unique and given also an integer k, 
return the kth missing number starting from the leftmost number of the array.
Example 1:

Input: nums = [4,7,9,10], k = 1
Output: 5
Explanation: The first missing number is 5.
'''
'''
Constraints:

1 <= nums.length <= 5 * 10^4
1 <= nums[i] <= 10^7
nums is sorted in ascending order, and all the elements are unique.
1 <= k <= 10^8
'''

'''
Binary search
calculate number_range = nums[-1] - nums[0] + 1
The count of missing numbers, missing = number_range - len(nums)
if k > missing, the wanted missing number is not inside the number list. result = nums[-1] + k - missing.

We can apply Binary search to solve this problem.
if missing number is not inside nums[left:mid+1], search in nums[mid+1:right+1] and update k -= missing.
Otherwise search in nums[left:mid-1].
Use the 'last' variable to track the starting of the region with missing number.
Time: O(logn)
Space: O(1)
'''
class Solution:
    def missingElement(self, nums: List[int], k: int) -> int:
        len_n = len(nums)
        missing = nums[-1] - nums[0] + 1 - len_n
        if k > missing:
            return nums[-1] + k - missing
        
        # Now the first missing number must be inside nums.
        last, left, right = 0, 0, len_n-1
        while left <= right:
            mid = left + (right - left) // 2
            missing = nums[mid] - nums[last] + 1 - (mid-last+1)
            if k > missing:
                last = mid
                k -= missing
                left = mid + 1
            else:
                right = mid - 1
        return nums[last] + k

'''
Approach-2
Tc:- O(log(n))
Sc:- O(1)
'''
class Solution:
    def missingElement(self, nums: List[int], k: int) -> int:
        leftIndex,rightIndex = 0, len(nums)
        while leftIndex < rightIndex:
            midVal = leftIndex + (rightIndex - leftIndex)//2
            difference = (nums[midVal]-midVal) - nums[0]
            if difference < k:
                leftIndex = midVal + 1
            else:
                rightIndex = midVal
        return rightIndex + nums[0] + k -1
