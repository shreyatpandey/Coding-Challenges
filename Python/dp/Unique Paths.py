'''
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
'''
#Solution-1
class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        dp = [[1]*n]*m
        for i in range(1,m):
            for j in range(1,n):
                dp[i][j] = dp[i-1][j]+dp[i][j-1]
        return dp[m-1][n-1]

 #Solution-2
from functools import lru_cache
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        @lru_cache(maxsize = None)
        def Recur(m,n):
            if m == 1  or n == 1:
                return 1
            up = Recur(m-1,n)
            left = Recur(m,n-1)
            return up + left
        
        return Recur(m,n)
