'''
Questions:-
You are given an m x n grid grid of values 0, 1, or 2, where:

each 0 marks an empty land that you can pass by freely,
each 1 marks a building that you cannot pass through, and
each 2 marks an obstacle that you cannot pass through.
You want to build a house on an empty land that reaches all buildings in the shortest total travel distance. 
You can only move up, down, left, and right.

Return the shortest travel distance for such a house. If it is not possible to build such a house according to the above rules, return -1.

The total travel distance is the sum of the distances between the houses of the friends and the meeting point.

The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|

'''


'''
Algo:-
Do a BFS from each building to find for each empty land its shortest distance to that particular building. 
Then we iterate over all empty lands and find for each land its sum of shortest distances to all buildings, 
and record the minimum value of such sums. Finally, we return the minimum value we recorded.
'''
'''
More Explanation:-
Undirected Graph
Starting from 0 to 1
Extra 2-D Array to keep record of how many bui;lding can be reached
'''
'''
Time complexity: O(k*l)
Space complexity: O(m*n*k), 
where m = len(grid), n = len(grid[0]) 
k is the number of buildings in the grid, and l is the number of empty lands in the grid.
'''
class Solution(object):
    def shortestDistance(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """        
        def bfs(y0, x0):
            seen = [[0]*n for _ in range(m)]
            q = collections.deque([(y0, x0, 0)])
            while q:
                y, x, d = q.popleft()
                for yp, xp in {(y-1,x), (y+1, x), (y, x+1), (y, x-1)}:
                    if 0 <= yp < m and 0 <= xp < n and grid[yp][xp] == 0 and seen[yp][xp] == 0:
                        seen[yp][xp] = 1
                        if not rec[yp][xp]:
                            rec[yp][xp] = [d+1] #why [], we would be storing list in that particular coordinate
                        else:
                            rec[yp][xp].append(d+1)
                        q.append((yp, xp, d+1))
                        
        m = len(grid)
        n = len(grid[0])
        rec = [[None]*n for _ in range(m)]  
        building_count = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1: # Do a BFS from each building to find empty lands
                    building_count += 1
                    bfs(i, j)
        minimum = float('inf')
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0:
                    if rec[i][j] and len(rec[i][j]) == building_count:
                        minimum = min(minimum, sum(rec[i][j]))
        return minimum if minimum != float('inf') else -1
