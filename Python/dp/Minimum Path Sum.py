'''
Minimum Path Sum
'''
#solution-1
from functools import lru_cache
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        minPath = float('inf')
        @lru_cache(maxsize = None)
        def MinPath(row,col):
            if row < 0 or col < 0 :
                return math.inf
            
            if row == 0 and col == 0:
                return grid[row][col]
            
            up = MinPath(row-1,col) 
            left = MinPath(row,col-1)
            return grid[row][col] + min(up,left)

        
        row = len(grid)
        col = len(grid[0])
        return MinPath(row-1,col-1)
