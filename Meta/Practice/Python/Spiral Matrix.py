'''
Given a matrix, return the matrix in a spiral order
'''

'''
Input:-
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
'''
'''
m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
'''
'''
Approach:-
Simulation
Two pointers
Taking care of the boundary of the matrix
There are 4 boundaries that is up, down, right, left
This problem can be divided into 4 sub divisions
move right: (row, col + 1)
move downwards: (row + 1, col)
move left: (row, col - 1)
move upwards: (row - 1, col)
'''

'''
Complexity:-
TC:- O(m*n) 
where m is the number of columns and n is the number of rows
SC:- O(1)
'''
class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        rowLength = len(matrix)
        colLength = len(matrix[0])
        SpiralMatrix = []
        i , j = 0,0
        while rowLength>0 and colLength>0:
            for k in range(0,colLength): #topRow
                SpiralMatrix.append(matrix[i][j])
                j += 1
            j -= 1
            rowLength -= 1
            if rowLength == 0:
                break;
            for k in range(0,rowLength): #rightmost Column Boundary
                i += 1
                SpiralMatrix.append(matrix[i][j])
            
            colLength -= 1
            if colLength == 0:
                break;
        
            for k in range(0,colLength): #BottomMost Row
                j -= 1
                SpiralMatrix.append(matrix[i][j])
            
            rowLength -= 1
            if rowLength == 0:
                break;
            
            for k in range(0,rowLength): #leftmost Column Boundary
                i -= 1
                SpiralMatrix.append(matrix[i][j])
                
            colLength -= 1
            if colLength == 0:
                break;
            j += 1
        
        return SpiralMatrix
