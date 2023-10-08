'''
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.
'''
'''
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
'''
'''
Constraints:
m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-2^31 <= matrix[i][j] <= 2^31 - 1
'''
'''
Complexity:-
Tc:- O(m*n) 
where m is the number of rows
n is the number of columns
Sc:- O(1)
Most important
'''
'''
Explanation:-
The approach to get constant space is to use first row and first col of the matrix as a tracker.
At each row or col, if you see a zero, then mark the first row or first col as zero with the current row and col.
Then iterate through the array again to see where the first row and col were marked as zero and then set that row/col as 0.
After doing that, you'll need to traverse through the first row and/or
first col if there were any zeroes there to begin with and set everything to be equal to 0 in the first row and/or first col.
'''
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:

        m = len(matrix)
        n = len(matrix[0])
		
        first_row_has_zero = False
        first_col_has_zero = False
        
        # iterate through matrix to mark the zero row and cols
        for row in range(m):
            for col in range(n):
                if matrix[row][col] == 0:
                    if row == 0:
                        first_row_has_zero = True
                    if col == 0:
                        first_col_has_zero = True
                    matrix[row][0] = matrix[0][col] = 0
    
        # iterate through matrix to update the cell to be zero if it's in a zero row or col
        for row in range(1, m):
            for col in range(1, n):
                matrix[row][col] = 0 if matrix[0][col] == 0 or matrix[row][0] == 0 else matrix[row][col]
        
        # update the first row and col if they're zero
        if first_row_has_zero:
            for col in range(n):
                matrix[0][col] = 0
        
        if first_col_has_zero:
            for row in range(m):
                matrix[row][0] = 0
