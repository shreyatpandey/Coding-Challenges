'''
You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.

 

Example 1:

Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.

'''
'''
Code Explanation:- Dfs with Connected Components
What we need to do is to find all islands first (very similar Number of Distinct Islands),
we can do it in place: for each island we rewrite it with its number (we start enumerate from 2, because 0 and 1 already reserved), 
also we evaluate size of each island in island Counter. 
Then we need to traverse our grid once again and for each empty cell check four neighbors: 
and create set off all unique islands (it can happen that for example left neighbor and upper neighbor are the same island). 
Then we evaluate sum of sizes of all neighbours and choose the biggest one.

'''
'''
Time complexity :- O(n*m), 
because we traverse our graph twice: one with dfs and another when we were looking for empty cells. 
SC:- Space complxity is potentially O(n*m) as well.
'''
class Solution:
    def largestIsland(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        neib_list = [[1,0],[-1,0],[0,-1],[0,1]]
        islands, count, ans = Counter(), 2, 0
        #count is 2 because (0,1) are reserved
        
        def dfs(t, i, j):
            if not 0 <= i < m or not 0 <= j < n or grid[i][j] != 1: return
            islands[t] += 1
            grid[i][j] = t
            for x, y in neib_list: dfs(t, x+i, y+j)
                
        for x in range(m):
            for y in range(n):
                if grid[x][y] == 1:
                    dfs(count, x, y)
                    count += 1
               
        for x in range(m):
            for y in range(n):
                if grid[x][y] != 0: continue
                neibs = set()
                for dx, dy in neib_list:
                    if 0 <= x + dx < m and 0 <= y + dy < n and grid[x+dx][y+dy] != 0:
                        neibs.add(grid[x+dx][y+dy])
                ans = max(ans, sum(islands[i] for i in neibs) + 1)
            
        return ans if ans != 0 else m*n
if __name__ == '__main__':
    s = Solution()
    Grid = [[1,0],[0,1]]
    print("Test Case-1:")
    print(s.largestIsland(Grid))
'''
Test Case-1:
Count: 4
islands: Counter({2: 1, 3: 1})
Grid: [[2, 0], [0, 3]]
3
'''
    
