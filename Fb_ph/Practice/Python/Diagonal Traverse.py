'''
We also need to keep track of whether we're traversing top-right or bottom-left, and accordingly set the starting and ending cells in the addDiagonal function call.

The only tricky part is updating the boundaries after we've added a diagonal, but I think the code is self-explanatory.
'''

'''
TC:- O(n*m)
SC:- O(1)
'''

class Solution:
    def findDiagonalOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix or not matrix[0]:
            return []

        result = []
        row, col, d = 0, 0, 0
        dirs = [(-1, 1), (1, -1)]

        for i in range(len(matrix) * len(matrix[0])):
            result.append(matrix[row][col])
            row += dirs[d][0]
            col += dirs[d][1]

            if row >= len(matrix):
                row = len(matrix) - 1
                col += 2
                d = 1 - d
            elif col >= len(matrix[0]):
                col = len(matrix[0]) - 1
                row += 2
                d = 1 - d
            elif row < 0:
                row = 0
                d = 1 - d
            elif col < 0:
                col = 0
                d = 1 - d

        return result
