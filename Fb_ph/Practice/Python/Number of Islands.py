'''
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.
'''
'''
Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
'''
'''
Constraints:-
m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
'''
'''
Approach-1:- BFS
TC:- O(m*n)
SC:- O(m*n)
'''
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        dirs = [(-1,0),(0,-1),(0,1),(1,0)]
        rowLen = len(grid)
        colLen = len(grid[0])
        noOfIslands = 0
        for row in range(rowLen):
            for col in range(colLen):
                if grid[row][col] == '1':
                    noOfIslands += 1
                    queue = []
                    queue.append((row,col))
                    while len(queue)>0:
                        first = queue[0][0]
                        second = queue[0][1]
                        del queue[0]
                        for x,y in dirs:
                            _xcor = first + x
                            _ycor = second + y
                            if _xcor>=0 and _ycor>=0 and _xcor<rowLen and _ycor<colLen and grid[_xcor][_ycor] == '1':
                                grid[_xcor][_ycor] = '0'
                                queue.append((_xcor,_ycor))
        return noOfIslands

'''
Approach-2:- DFS
TC:- O(m*n)
SC:- O(min(m,n))

'''
class Solution(object):
    row_size = 0;
    column_size = 0

    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        if len(grid) == 0:
            return 0
        self.row_size = len(grid)
        self.column_size = len(grid[0])
        number_of_islands = 0
        for i in range(self.row_size):
            for j in range(self.column_size):
                if grid[i][j] == '1':
                    self.dfs_mountain(grid,i,j)
                    number_of_islands += 1
        
        return number_of_islands
    
    def dfs_mountain(self,grid,i,j):
            if grid[i][j] == '0':
                return;
            grid[i][j] = '0'
            if self.check_boundaries(grid,i-1,j):
                self.dfs_mountain(grid,i-1,j)
            if self.check_boundaries(grid,i+1,j):
                self.dfs_mountain(grid,i+1,j)
            if self.check_boundaries(grid,i,j-1):
                self.dfs_mountain(grid,i,j-1)
            if self.check_boundaries(grid,i,j+1):
                self.dfs_mountain(grid,i,j+1)
    
    
    def check_boundaries(self,grid,i,j):
          return (i>=0 and i<self.row_size and j>=0 and j<self.column_size)
                    

