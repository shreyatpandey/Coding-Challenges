'''
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. 
This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
'''
'''
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true
'''
'''
Constraints:

m == matrix.length
n == matrix[i].length
1 <= n, m <= 300
-10^9 <= matrix[i][j] <= 10^9
All the integers in each row are sorted in ascending order.
All the integers in each column are sorted in ascending order.
-10^9 <= target <= 10^9
'''
'''
Complexity
TC:- O(m+n)
where m is the length of rows in matrix
where n is the length of cols in matrix
Sc:- O(1)
'''
class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if not len(matrix) or not len(matrix[0]):
			    # Quick response for empty matrix
            return False
        
        h, w = len(matrix), len(matrix[0])
        
        # Start adaptive search from bottom left corner
        y, x = h-1, 0
        
        while True:
            
            if y < 0 or x >= w:
                break
            
            current = matrix[y][x]
            
            if target < current:
                # target is smaller, then go up
                y -= 1
            
            elif target > current:
                # target is larger, then go right
                x += 1
            
            else:
                # hit target
                return True
            
        return False
