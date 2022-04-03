'''
Follow-Up Questions:-
1. What if the matrix is stored on disk, and the memory is limited such that you can only load at most one row of the matrix into the memory at once?
Compare half of 1 row with half of the next/previous row.

2. What if the matrix is so large that you can only load up a partial row into the memory at once?
Hash 2 rows (so only 1 element needs to be loaded at a time) and compare the results, excluding the appropriate beginning or ending element.

'''
'''
Question:- Toeplitz matrix
Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise, return false.
A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.

'''
def isToeplitzMatrix(self, m):
  for i in range(len(m) - 1):
      for j in range(len(m[0]) - 1):
          if m[i][j] != m[i + 1][j + 1]:
              return False
  return True

#Make it 1 line:
def isToeplitzMatrix(self, m):
  return all(m[i][j] == m[i+1][j+1] for i in range(len(m)-1) for j in range(len(m[0])-1))

#Or shorter and more pythonic.
def isToeplitzMatrix(self, m):
  return all(r1[:-1] == r2[1:] for r1,r2 in zip(m, m[1:]))


'''
Most Optimal Solution to take care of follow-up
TC:- O(M*N)
SC:- O(M+N)
'''
class Solution:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        Map = {}
        for row in range(len(matrix)):
            for col in range(len(matrix[0])):
                Diag = row - col
                if  Diag not in Map:
                    Map[Diag] = matrix[row][col]
                else:
                    if Map[Diag] != matrix[row][col]:
                        return False
        return True

''''
Answer To Follow-Up 
Questions
'''
############################################################################################
# Follow-Up Solution
#   Runtime: O(MN)
#       Every cell is touched about once.
#   Space: O(N)
#       We need to store a deque of length equal to the number of columns.
############################################################################################
from collections import deque
class Solution:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        # Validate Input
        if not matrix or not matrix[0]:
            return False                
        
        # Create a deque tracking the expected values for the next row
        expected = deque(matrix[0])
        
        # Iterate through all the remaining rows, verifying they align with the
        #   expected row.
        for row_i in range(1, len(matrix)):
            row = matrix[row_i]
            expected.pop()
            expected.appendleft(row[0])
            
			# Only check from index 1 and down as we've just added index 0 to expected
            for col_i in range(1, len(row)):
                if row[col_i] != expected[col_i]:
                    return False
        
        # If we've reached here, all diagonals aligned
        return True
#https://leetcode.com/problems/toeplitz-matrix/discuss/516366/Python-Follow-Up-1-with-Explanation-and-Diagrams
