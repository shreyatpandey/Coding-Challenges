'''
You are given two positive integers n and k. A factor of an integer n is defined as an integer i where n % i == 0.

Consider a list of all factors of n sorted in ascending order, 
return the kth factor in this list or return -1 if n has less than k factors.
'''
'''
Example 1:

Input: n = 12, k = 3
Output: 3
Explanation: Factors list is [1, 2, 3, 4, 6, 12], the 3rd factor is 3.
'''
'''
Constraints:
1 <= k <= n <= 1000
Follow up:
Could you solve this problem in less than O(n) complexity?
'''
class Solution:
    def kthFactor(self, n: int, k: int) -> int:
        root = math.sqrt(n)
        for i in range(1, int(root)+1):
            if n % i == 0:
                k -= 1
                if k == 0: return i
        for i in range(int(root), 0, -1):
            if i*i == n: 
                continue
            if n % i == 0:
                k -= 1
                if k == 0: return n//i
        return -1
