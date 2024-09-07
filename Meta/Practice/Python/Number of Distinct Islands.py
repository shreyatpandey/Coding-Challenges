'''
You are given an m x n binary matrix grid. 
An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) 
You may assume all four edges of the grid are surrounded by water.

An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal the other.

Return the number of distinct islands.
'''
'''
Input: grid = [[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]
Output: 1
'''
'''
Approach:- DFS by hash-map local coordinates
TC:- O(m*n) where m is the number of rows and n is the number of columns
SC:- O(m*n) for the seen set used 
'''
class Solution:
    def numDistinctIslands(self, grid: List[List[int]]) -> int:

        # Do a DFS to find all cells in the current island.
        def dfs(row, col):
            if row < 0 or col < 0 or row >= len(grid) or col >= len(grid[0]):
                return
            if (row, col) in seen or not grid[row][col]:
                return
            seen.add((row, col))
            current_island.add((row - row_origin, col - col_origin))
            dfs(row + 1, col)
            dfs(row - 1, col)
            dfs(row, col + 1)
            dfs(row, col - 1)
        
        # Repeatedly start DFS's as long as there are islands remaining.
        seen = set()
        unique_islands = set()
        for row in range(len(grid)):
            for col in range(len(grid[0])):
                current_island = set()
                row_origin = row
                col_origin = col
                dfs(row, col)
                if current_island:
                    unique_islands.add(frozenset(current_island))
        
        return len(unique_islands)

'''
Approach-2:- DFS by hash-map and path-signature
TC:- O(m*n)
SC:- O(m*n)
'''
class Solution:
    def numDistinctIslands(self, grid: List[List[int]]) -> int:

        # Do a DFS to find all cells in the current island.
        def dfs(row, col, direction):
            if row < 0 or col < 0 or row >= len(grid) or col >= len(grid[0]):
                return
            if (row, col) in seen or not grid[row][col]:
                return
            seen.add((row, col))
            path_signature.append(direction)
            dfs(row + 1, col, "D")
            dfs(row - 1, col, "U")
            dfs(row, col + 1, "R")
            dfs(row, col - 1, "L")
            path_signature.append("0")
        
        # Repeatedly start DFS's as long as there are islands remaining.
        seen = set()
        unique_islands = set()
        for row in range(len(grid)):
            for col in range(len(grid[0])):
                path_signature = []
                dfs(row, col, "0")
                if path_signature:
                    unique_islands.add(tuple(path_signature))
        
        return len(unique_islands)




'''
Approach-3:- BFS
TC:- O(m*n)
SC:- O(m*n)

'''

dirs = {(-1,0, 'U'),(1,0, 'D'),(0,-1, 'L'),(0,1, 'R')}
       
        def bfs(row, col, grid):
            queue = collections.deque([(row, col)])
            s = "S"
            while queue:
                row, col = queue.popleft()   
                if 0 <= row < len(grid) and 0 <= col < len(grid[0]) and grid[row][col] == 1:
                    grid[row][col] = 0
                    for dir in dirs:
						# record shape 
                        s += dir[2]
                        neighbor = (row + dir[0], col + dir[1])
                        queue.append(neighbor)
                else:
				   # record hitting water or out of bounds 
                   s += 'X'
			# return shape 
            return s
        
        pattern = set()
        
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    shape = bfs(i, j, grid)
										# add shape to set 
                    pattern.add(shape)
         # only unique shapes in set 
        return len(pattern)

'''
Approach:- BFS
Tc:- O(mn)
Sc:- O(mn)
'''
class Solution:
    def numDistinctIslands(self, grid: List[List[int]]) -> int:
        """
        time: O(mn)
        space: O(mn)
        """
        row, col = len(grid), len(grid[0])
        directions_array = [(-1, 0), (1, 0), (0, 1), (0, -1)]
        queue = deque([])

        distinct_islands = set()

        for r in range(row):
            for c in range(col):
                if grid[r][c] == 1:
                    # mark visited
                    grid[r][c] = 2
                    
                    queue.append((r, c))
                    island_shape = []
                    
                    while queue:
                        x, y = queue.popleft()
                        
                        for d0, d1 in directions_array:
                            dx, dy = d0 + x, d1 + y
                            
                            if (0 <= dx < row) and (0 <= dy < col) and (grid[dx][dy] == 1):
                                # mark visited 
                                grid[dx][dy] = 2
								# append the relative coordinates... r is the start row and c is the start col
                                island_shape.append((r - dx, c - dy))
                                queue.append((dx, dy))

                    distinct_islands.add(tuple(island_shape))
        return len(distinct_islands)
        

