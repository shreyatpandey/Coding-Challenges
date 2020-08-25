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
        
