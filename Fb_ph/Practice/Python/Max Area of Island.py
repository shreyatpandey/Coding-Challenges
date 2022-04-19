'''
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) 
You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

'''
'''
Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1

'''
'''
Wording:-
If we are on a land square and explore every square connected to it 4-directionally to that given square, 
then the total number of squares explored will be the area of that connected shape.
use a queue for the traversal
'''

'''
Approach:- BFS
TC:- O(M*N) 
where M is the length of the row and N is the length of the column
SC:- O(M*N) for the Queue
'''
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        rowLen = len(grid)
        colLen = len(grid[0])
        maxArea = 0
        dirs = [(-1,0),(0,-1),(0,1),(1,0)]
        def bfs(x,y): #what should be the return type of this, it would return area covered
            queue = deque([])
            queue.append((x,y))
            curArea = 1
            while len(queue)>0:
                '''
                first = queue[0][0]
                second = queue[0][1]
                del queue[0]
                '''
                first,second = queue.popleft()
                for _x,_y in dirs:
                    _xcor = first + _x
                    _ycor = second + _y
                    if _xcor>=0 and _ycor>=0 and _xcor<rowLen and _ycor<colLen and grid[_xcor][_ycor] == 1:
                        grid[_xcor][_ycor] = 2
                        curArea += 1
                        queue.append((_xcor,_ycor))
            return curArea
        
        
        
        for row in range(rowLen):
            for col in range(colLen):
                if grid[row][col] == 1:
                    grid[row][col] = 2
                    area = bfs(row,col)
                    maxArea = max(area,maxArea)
        
        
        return maxArea
