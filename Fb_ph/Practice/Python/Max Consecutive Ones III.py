'''
Question:-
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

'''
'''
Approach:- 
We can maintain two pointers l (left-most window index) and r (right-most window index). 
We have following possible scenarios -

nums[r] == 0 : We will try to include this in our window. 
Here we have two subcases:

    k != 0: We can just include nums[r] in current window and extend it. 
        We will also decrement k denoting a zero has been picked in the current window
    k == 0: Our window already contains maximum zeros (k) allowed. 
    So, we need to shrink our window size from the left till a zero is removed from the other end. 
    Then we can pick nums[r] in our window & extend it. k won't change since we have popped a zero from left and picked one from right.
nums[r] == 1: We can simply pick this element and extend our window.

'''

'''
TC:- O(n)
SC:- O(1)
where n is the size of the inputNum
'''

class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        n, ans, l = len(nums), 0, 0
        for r in range(n):
            if nums[r] == 0:                       # try to pick current 0
                if k == 0:                         # if window already picked k zeros, pop 1 from left and pick this
                    while nums[l] != 0 : 
                        l += 1
                    l += 1
                else : k-= 1                       # otherwise pick it and decrement k
            ans = max(ans, r - l + 1)              # update ans as max window size till now
        return ans
