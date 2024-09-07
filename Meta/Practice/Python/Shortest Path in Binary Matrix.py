'''
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. 
If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) 
to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.

Input: grid = [[0,1],[1,0]]
Output: 2
'''
'''
n == grid.length
n == grid[i].length
1 <= n <= 100
grid[i][j] is 0 or 1
'''
'''
Comment:- To avoid revisiting we can securely set the visiting grid as non-empty
'''
'''
TC:- O(N)
as each space cell is visited only once
SC:- O(N)
for the visited list for each space cell
'''

def shortestPathBinaryMatrix(grid):
    n = len(grid)
    dirs = [(-1,-1),(-1,0),(0,-1),(1,0),(1,-1),(0,1),(-1,1),(1,1)]
    if grid[0][0] or grid[n-1][n-1]:
        return -1
    q = [(0, 0, 1)]
    grid[0][0] = 1
    for i, j, d in q:
        if i == n-1 and j == n-1: 
            return d
        for row,col in dirs:
            x = row + i
            y = col + j
            if 0 <= x < n and 0 <= y < n and not grid[x][y]:
                grid[x][y] = 1
                q.append((x, y, d+1))
    return -1

if __name__ == '__main__':
    print("Test-Case:1")
    grid = [[0,1],[1,0]]
    print(shortestPathBinaryMatrix(grid))
    
    print("Test-Case:2")
    grid = [[0,0,0],[1,1,0],[1,1,0]]
    print(shortestPathBinaryMatrix(grid))

'''
Output:-
Test-Case:1
2
Test-Case:2
4
'''

'''
Approach-2:- Not overwriting the input
Tc:- O(N) where N is the number of cells to be processed
Sc:- O(N) for queue and visited

'''
class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        # check if source and target are not clear cells
        if grid[0][0] != 0 or grid[-1][-1] != 0:
            return -1
        
        N = len(grid)            
        # offsets required for all 8 directions
        offsets = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]
        
        q = deque()
        q.append((0,0)) # starting point
        visited = {(0, 0)}
        
        
        # finds unvisited clear cells using 8 offsets
        def get_neighbours(x,y):
            for x_offset, y_offset in offsets:
                new_row = x + x_offset
                new_col = y + y_offset
                
                if 0 <= new_row < N and 0 <= new_col < N and not grid[new_row][new_col] and (new_row, new_col) not in visited:
                    yield (new_row, new_col)                                                
            
        
        current_distance = 1 # start with one clear cell
        # standard iterative BFS traversal
        while q:
            length = len(q)
            
            # loop through all the cells at the same distance
            for _ in range(length):
                row, col = q.popleft()
                
                if row == N-1 and col==N-1: # reached target
                    return current_distance
                
                # loop though all valid neignbours
                for p in get_neighbours(row, col):
                    visited.add(p)
                    q.append(p)
                                    
            current_distance+=1 # update the level or distance from source
        
        return -1    
