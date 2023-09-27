'''
You are given an m x n binary matrix grid. 
An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) 
You may assume all four edges of the grid are surrounded by water.

An island is considered to be the same as another if they have the same shape, 
or have the same shape after rotation (90, 180, or 270 degrees only) or reflection (left/right direction or up/down direction).

Return the number of distinct islands.
'''
'''
Input: grid = [[1,1,0,0,0],[1,0,0,0,0],[0,0,0,0,1],[0,0,0,1,1]]
Output: 1
Explanation: The two islands are considered the same because 
if we make a 180 degrees clockwise rotation on the first island, then two islands will have the same shapes.
'''
'''
Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1.
'''
'''
Explanation:-
1. Find the shape of the island.
Simple DFS, always start at top left. Same as Number of distinct islands 1.

2. Find 4 possible reflections for this shape.
For each point (x, y) in the original shape, it has 4 corresponding reflection points.

(x, y)
(-x, y)
(x, -y)
(-x, -y)
Find all these, sort them and add to our list of reflections.

3. Find 4 possible rotations for this shape.
For each point (x, y) in the original shape, it has 4 corresponding rotated points.

(y, x)
(y, -x)
(-y, x)
(-y, -x)
Find all these, sort them and add to our list of rotations.

4. Choose one of these 4 rotations + 4 reflections as a representative for this shape and use it as a key to our hashmap for this island.
We can choose the smallest shape as our representative for the 8 reflections and rotations, and use it as the key to our hashmap.
'''
'''
Approach:- DFS
TC:- 
O(m*n+d*k*logk) or O(m*n*log(m*n))
where
m, n = height/width of the grid 
d = Number of islands 
k = number of cells in the biggest island

dfs = (O(m*n))
cannonical = O(k*logk)
Main loop =  O(m*n+d*k*logk)

SC:- 
O(m×n) where
m, n = height/width of the grid
'''

class Solution:
    def numDistinctIslands2(self, grid: List[List[int]]) -> int:
        def dfs(x, y, coords):
            if x < 0 or x >= len(grid) or y < 0 or y >= len(grid[0]) or grid[x][y] == 0:
                return
            grid[x][y] = 0
            coords.append((x, y))
            for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                dfs(x + dx, y + dy, coords)

        def canonical(coords):
            shapes = []
            for i, j in [(1, 1), (1, -1), (-1, 1), (-1, -1)]:
                # Reflection
                shape = sorted([(x * i, y * j) for x, y in coords])
                shape = [(x - shape[0][0], y - shape[0][1]) for x, y in shape]
                shapes.append(shape)

                # Rotations
                shape = sorted([(y * i, x * j) for x, y in coords])
                shape = [(x - shape[0][0], y - shape[0][1]) for x, y in shape]
                shapes.append(shape)
                
            return min(shapes)

        distinct_islands = set()
        for x in range(len(grid)):
            for y in range(len(grid[0])):
                if grid[x][y] == 1:
                    coords = []
                    #print("coords:",coords)
                    dfs(x, y, coords)
                    distinct_islands.add(tuple(canonical(coords)))
                    #print("distinct_islands:",distinct_islands)

        return len(distinct_islands)

if __name__ == '__main__':
    print("Test Case-1:")
    s = Solution()
    grid = [[0,0],[1,1]]
    print(s.numDistinctIslands2(grid))
'''
Test Case-1:
coords: [(1, 0), (1, 1)]
shapes-1: [[(0, 0), (0, 1)]]
shapes-2: [[(0, 0), (0, 1)], [(0, 0), (1, 0)]]
shapes-1: [[(0, 0), (0, 1)], [(0, 0), (1, 0)], [(0, 0), (0, 1)]]
shapes-2: [[(0, 0), (0, 1)], [(0, 0), (1, 0)], [(0, 0), (0, 1)], [(0, 0), (1, 0)]]
shapes-1: [[(0, 0), (0, 1)], [(0, 0), (1, 0)], [(0, 0), (0, 1)], [(0, 0), (1, 0)], [(0, 0), (0, 1)]]
shapes-2: [[(0, 0), (0, 1)], [(0, 0), (1, 0)], [(0, 0), (0, 1)], [(0, 0), (1, 0)], [(0, 0), (0, 1)], [(0, 0), (1, 0)]]
shapes-1: [[(0, 0), (0, 1)], [(0, 0), (1, 0)], [(0, 0), (0, 1)], [(0, 0), (1, 0)], [(0, 0), (0, 1)], [(0, 0), (1, 0)], [(0, 0), (0, 1)]]
shapes-2: [[(0, 0), (0, 1)], [(0, 0), (1, 0)], [(0, 0), (0, 1)], [(0, 0), (1, 0)], [(0, 0), (0, 1)], [(0, 0), (1, 0)], [(0, 0), (0, 1)], [(0, 0), (1, 0)]]
distinct_islands: {((0, 0), (0, 1))}
1
'''
