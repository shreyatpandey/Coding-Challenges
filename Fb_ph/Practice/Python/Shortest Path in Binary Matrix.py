'''
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. 
If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

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
