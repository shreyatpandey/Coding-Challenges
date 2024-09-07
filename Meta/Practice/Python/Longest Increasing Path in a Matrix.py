'''
Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. 
You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).
'''
'''
Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].

Input: matrix = [[1]]
Output: 1
'''
'''
Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
0 <= matrix[i][j] <= 231 - 1
'''


'''
Complexity:-
TC:- O(m*n) where M<=200 and is the number of rows and N<=200, is the  number of columns
SC:- O(m*n)
'''
class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
      DIR = [0, 1, 0, -1, 0]
      m, n = len(matrix), len(matrix[0])
      
      @lru_cache(None)
      def dfs(r, c):
          ans = 1
          for i in range(4):
              nr, nc = r + DIR[i], c + DIR[i+1]
              if nr < 0 or nr == m or nc < 0 or nc == n or matrix[nr][nc] <= matrix[r][c]: continue  # Out of bound or not greater
              ans = max(ans, dfs(nr, nc) + 1)
          return ans
      
      ans = 0
      for r in range(m):
          for c in range(n):
              ans = max(ans, dfs(r, c))
      return ans

'''
Approach:- Topological Sort 
TC:- O(m*n)
SC:- O(m*n)
'''
class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
      DIR = [0, 1, 0, -1, 0]
      m, n = len(matrix), len(matrix[0])
      
      outDegree = [[0] * n for _ in range(m)]
      for r in range(m):
          for c in range(n):
              for i in range(4):
                  nr, nc = r + DIR[i], c + DIR[i+1]
                  if nr < 0 or nr == m or nc < 0 or nc == n or matrix[nr][nc] <= matrix[r][c]: continue
                  outDegree[r][c] += 1
          
      q = deque([])
      for r in range(m):
          for c in range(n):
              if outDegree[r][c] == 0:
                  q.append([r, c])
                  
      level = 0
      while q:
          level += 1
          for _ in range(len(q)):
              r, c = q.popleft()
              for i in range(4):
                  nr, nc = r + DIR[i], c + DIR[i+1]
                  if nr < 0 or nr == m or nc < 0 or nc == n or matrix[nr][nc] >= matrix[r][c]: continue
                  outDegree[nr][nc] -= 1
                  if outDegree[nr][nc] == 0:
                      q.append([nr, nc])
                  
      return level
