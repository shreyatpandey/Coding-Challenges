#Solution-1
from functools import lru_cache
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        
        @lru_cache(maxsize=None)
        def noOfWays(m,n):
            if m== 0 and n == 0 and obstacleGrid[m][n] == 0:
                return 1
        
            if m<0 or n<0 or obstacleGrid[m][n] == 1:
                return 0

            up = noOfWays(m-1,n)
            left = noOfWays(m,n-1)
            return up + left
        
        row = len(obstacleGrid)
        col = len(obstacleGrid[0])
        return noOfWays(row-1,col-1)
