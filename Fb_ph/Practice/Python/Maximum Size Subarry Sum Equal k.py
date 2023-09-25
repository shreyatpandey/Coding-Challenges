'''
Given an integer array nums and an integer k, return the maximum length of a 
subarray that sums to k. 
If there is not one, return 0 instead.

 
Example 1:

Input: nums = [1,-1,5,-2,3], k = 3
Output: 4
Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.
Example 2:

Input: nums = [-2,-1,2,1], k = 1
Output: 2
Explanation: The subarray [-1, 2] sums to 1 and is the longest.
'''
'''
Constraints:

1 <= nums.length <= 2 * 10^5
-10^4 <= nums[i] <= 10^4
-10^9 <= k <= 10^9
'''
'''
Approach:- Hash-Map
TC:- O(n) in one pass, running through the length of nums
Sc:- O(n) for the hash-map
'''
class Solution:
    def maxSubArrayLen(self, nums: List[int], k: int) -> int:
        sum_to_index_mapping = {} # key: cumulative sum until index i, value: i
        curr_sum = max_len = 0 # set initial values for cumulative sum and max length sum to k
        for i in range(len(nums)):
            curr_sum += nums[i] # update cumulative sum

        # two cases where we can update max_len
            if curr_sum == k:
                max_len = max(max_len, i + 1) # case 1: cumulative sum is k, update max_len for sure
            elif curr_sum - k in sum_to_index_mapping:
                max_len = max(max_len, i - sum_to_index_mapping[curr_sum - k]) # case 2: cumulative sum is different from k, but we can truncate a prefix of the array
            
        # store cumulative sum in dictionary, only if it is not seen
        # because only the earlier (thus shorter) subarray is valuable, when we want to get the max_len after truncation
            if curr_sum not in sum_to_index_mapping:
                sum_to_index_mapping[curr_sum] = i
        return max_len
