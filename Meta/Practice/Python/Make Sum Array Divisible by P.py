'''
Given an array of positive integers nums, remove the smallest subarray (possibly empty) such that the sum of the remaining elements is divisible by p. 
It is not allowed to remove the whole array.

Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.

A subarray is defined as a contiguous block of elements in the array.

'''
'''
Input: nums = [3,1,4,2], p = 6
Output: 1
Explanation: The sum of the elements in nums is 10, which is not divisible by 6. We can remove the subarray [4],
 and the sum of the remaining elements is 6, which is divisible by 6.

Example 3:
Input: nums = [1,2,3], p = 3
Output: 0
Explanation: Here the sum is 6. which is already divisible by 3. Thus we do not need to remove anything.
'''
'''
Constraints :-
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
1 <= p <= 10^9

'''
'''
Intuition
Calculate the need = sum(A) % p.
Then one pass, record the prefix sum in a hashmap.


Explanation
Then the question become:
Find the shortest array with sum % p = need.

last[remainder] = index records the last index that
(A[0] + A[1] + .. + A[i]) % p = remainder


Complexity
Time O(N)
Space O(N)
'''
class Solution(object):
    def minSubarray(self, A, p):
        """
        :type nums: List[int]
        :type p: int
        :rtype: int
        """
        need = sum(A) % p
        dp = {0: -1}
        cur = 0
        res = n = len(A)
        for i, a in enumerate(A):
            cur = (cur + a) % p
            dp[cur] = i
            if (cur - need) % p in dp:
                res = min(res, i - dp[(cur - need) % p])
        return res if res < n else -1