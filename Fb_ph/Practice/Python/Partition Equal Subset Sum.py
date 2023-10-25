'''
Given an integer array nums, return true 
if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100
'''
'''
Approach:- 1-D array DP
n be the number of array elements and m be the subSetSum.
Complexity
Tc:- O(m.n)
Sc:- O(m)
'''
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        # Calculate the total sum of the input array
        total_sum = sum(nums)
        
        # If the total sum is odd, we cannot partition the array into two equal sum subsets
        if total_sum % 2 == 1:
            return False
        
        # Calculate the target sum for each subset
        target_sum = total_sum // 2
        
        # Initialize a boolean list of size target_sum+1 to keep track of whether a sum can be formed using the input array
        dp = [False] * (target_sum+1)
        
        # We can always form a sum of 0 using the input array
        dp[0] = True
        
        # Loop through each element in the input array
        for num in nums:
            # Starting from the target sum, loop backwards through the dp list
            for j in range(target_sum, num-1, -1):
                # If we can form a sum j-num using the previous elements in the input array,
                # we can also form a sum j using the current element
                dp[j] = dp[j] or dp[j-num]
        
        # Return whether or not we can form a sum of target_sum using the input array
        return dp[target_sum]

'''
Approach:- Recursion with memoization
n be the number of array elements and m be the subSetSum.
Tc:- O(m.n)
Sc:- O(m.n)
'''
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        @lru_cache(maxsize=None)
        def dfs(nums: Tuple[int], n: int, subset_sum: int) -> bool:
            # Base cases
            if subset_sum == 0:
                return True
            if n == 0 or subset_sum < 0:
                return False
            result = (dfs(nums, n - 1, subset_sum - nums[n - 1])
                    or dfs(nums, n - 1, subset_sum))
            return result

        # find sum of array elements
        total_sum = sum(nums)

        # if total_sum is odd, it cannot be partitioned into equal sum subsets
        if total_sum % 2 != 0:
            return False

        subset_sum = total_sum // 2
        n = len(nums)
        return dfs(tuple(nums), n - 1, subset_sum)
