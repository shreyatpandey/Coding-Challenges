'''
A row-sorted binary matrix means that all elements are 0 or 1 and each row of the matrix is sorted in non-decreasing order.
Given a row-sorted binary matrix binaryMatrix, 
return the index (0-indexed) of the leftmost column with a 1 in it. If such an index does not exist, return -1.

You can't access the Binary Matrix directly. 
You may only access the matrix using a BinaryMatrix interface:

BinaryMatrix.get(row, col) returns the element of the matrix at index (row, col) (0-indexed).
BinaryMatrix.dimensions() returns the dimensions of the matrix as a list of 2 elements [rows, cols],
which means the matrix is rows x cols.
Submissions making more than 1000 calls to BinaryMatrix.get will be judged Wrong Answer. 
'''
'''
Input: mat = [[0,0],[0,1]]
Output: 1

Input: mat = [[0,0],[1,1]]
Output: 0
'''
'''
Constraint:-
rows == mat.length
cols == mat[i].length
1 <= rows, cols <= 100
mat[i][j] is either 0 or 1.
mat[i] is sorted in non-decreasing order.
'''
'''
Approach-1:- Binary Search
TC:- 
Let N be the number of rows, and M be the number of columns.
O(Nlog(M))
There are M items in each row. Therefore, each binary search will have a cost of O(log(M))
N times binary search is perform :- O(Nlog(M))

SC:- O(1)
'''
class Solution(object):
    def leftMostColumnWithOne(self, binaryMatrix):
        """
        :type binaryMatrix: BinaryMatrix
        :rtype: int
        """
        if binaryMatrix.get(0,0) == 1 or binaryMatrix.get(1,0) == 1 :
            return 0
        RowCol = binaryMatrix.dimensions()
        Row = RowCol[0]
        Col = RowCol[1]
        #perform BinarySearch on what
        smallestIndex = Col
        for row in range(0,Row):
            LeftIndex = 0
            RightIndex = Col - 1
            while LeftIndex < RightIndex :
                mid = ( LeftIndex + RightIndex) // 2
                if binaryMatrix.get(row,mid) == 0 :
                    LeftIndex = mid + 1
                else:
                    RightIndex = mid
            if binaryMatrix.get(row,LeftIndex) == 1:
                smallestIndex = min(smallestIndex,LeftIndex)
            
        RetVal = -1 if smallestIndex == Col else smallestIndex
        return RetVal
'''
Approach-2:- Linear Scan
TC:- O(M+N)
Let N be the number of rows and M be the number of columns
At each step, we're moving 1 step left or 1 step down. Therefore, we'll always finish looking at either one of the M rows or N columns. 
Therefore, we'll stay in the grid for at most N + M steps, and therefore get a time complexity of O(N+M).

SC:- O(1) 
'''
class Solution:
    def leftMostColumnWithOne(self, binaryMatrix):
        rows, cols = binaryMatrix.dimensions()
        
        # Set pointers to the top-right corner.
        current_row = 0
        current_col = cols - 1
        
        # Repeat the search until it goes off the grid.
        while current_row < rows and current_col >= 0:
            if binaryMatrix.get(current_row, current_col) == 0:
                current_row += 1
            else:
                current_col -= 1
        
        # If we never left the last column, it must have been all 0's.
        return current_col + 1 if current_col != cols - 1 else -1
            
