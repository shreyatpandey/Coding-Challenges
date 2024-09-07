'''
You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).

The rain starts to fall. At time t, the depth of the water everywhere is t. 
You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. 
You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.

Return the least time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).

'''


'''
Approach:- Prioority Queue
TC:- O(N^2log(N))
log(N) to perform heappush and heappop operation
SC:- O(N^2)
where N is the length of the grid

'''
class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        N, pq, seen, res = len(grid), [(grid[0][0], 0, 0)], set([(0, 0)]), 0
        dirs = [(-1,0),(0,-1),(0,1),(1,0)]
        while True:
            T, x, y = heapq.heappop(pq)
            res = max(res, T)
            if x == y == N - 1:
                return res
            for row,col in dirs:
                row_ = x + row
                col_ = y + col
                if 0 <= row_ < N and 0 <= col_ < N and (row_,col_) not in seen:
                    seen.add((row_, col_))
                    heapq.heappush(pq, (grid[row_][col_], row_, col_))
        
