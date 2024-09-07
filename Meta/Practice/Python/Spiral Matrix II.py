'''
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
'''
'''
Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
'''
'''
Let us notice one clue property about our spiral matrix: first we need to go to the right and rotate clockwise 90 degrees,
then we go down and again when we reached bottom, we rotate 90 degrees clockwise and so on. 
So, all we need to do is to rotate 90 degrees clockwise when we need:

When we reached border of our matrix
When we reached cell which is already filled.
Let x, y be coordinates on our grid and dx, dy is current direction we need to move.
In geometrical sense, rotate by 90 degrees clockwise is written as dx, dy = -dy, dx.

Note, that matrix[y][x] is cell with coordinates (x,y), which is not completely obvious.
'''
'''
Complexity: 
time complexity is O(n^2), we process each element once. 
Space complexity is O(n^2) as well.
'''
class Solution:
    def generateMatrix(self, n):
        matrix = [[0] * n for _ in range(n)]
        x, y, dx, dy = 0, 0, 1, 0
        for i in range(n*n):
            matrix[y][x] = i + 1
            if not 0 <= x + dx < n or not 0 <= y + dy < n or matrix[y+dy][x+dx] != 0:
                dx, dy = -dy, dx
            x, y = x + dx, y + dy
        return matrix
