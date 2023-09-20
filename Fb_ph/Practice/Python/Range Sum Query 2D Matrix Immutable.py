'''
Given a 2D matrix matrix, handle multiple queries of the following type:

Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) 
and lower right corner (row2, col2).
Implement the NumMatrix class:

NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
int sumRegion(int row1, int col1, int row2, int col2)
Returns the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
You must design an algorithm where sumRegion works on O(1) time complexity.
'''
'''
Constraints:-
m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
-10^4 <= matrix[i][j] <= 10^4
0 <= row1 <= row2 < m
0 <= col1 <= col2 < n
At most 104 calls will be made to sumRegion.
'''
'''
Complexity
TC:- O(1) per query, O(mn) time pre-computation
Each sumRegion query take O(1) time
SC:- O(mn)
To store cumulative sum region
'''
class NumMatrix:
    def __init__(self, matrix: List[List[int]]):
        m, n = len(matrix), len(matrix[0])
        self.sum = [[0] * (n + 1) for _ in range(m + 1)]  # sum[i][j] is sum of all elements inside the rectangle [0,0,i,j]
        for r in range(1, m + 1):
            for c in range(1, n + 1):
                self.sum[r][c] = self.sum[r - 1][c] + self.sum[r][c - 1] - self.sum[r - 1][c - 1] + matrix[r - 1][c - 1]
        

    def sumRegion(self, r1: int, c1: int, r2: int, c2: int) -> int:
        r1, c1, r2, c2 = r1 + 1, c1 + 1, r2 + 1, c2 + 1  # Since our `sum` starts by 1 so we need to increase r1, c1, r2, c2 by 1
        return self.sum[r2][c2] - self.sum[r2][c1 - 1] - self.sum[r1 - 1][c2] + self.sum[r1 - 1][c1 - 1]
        
