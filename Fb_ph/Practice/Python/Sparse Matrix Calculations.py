'''
Given two sparse matrices mat1 of size m x k and mat2 of size k x n, 
return the result of mat1 x mat2. You may assume that multiplication is always possible.

Input: mat1 = [[1,0,0],[-1,0,3]], mat2 = [[7,0,0],[0,0,0],[0,0,1]]
Output: [[7,0,0],[-7,0,3]] 

'''
'''
TC:- O(m.k.n)
m - number of rows in mat1
k - number of columns in mat1
n - number of columns in mat2

SC:- O(m.k + k.n)
With Table | Approach - 1
'''

class Solution:
    def multiply(self, A: List[List[int]], B: List[List[int]]) -> List[List[int]]:
        if A is None or B is None: return None
        m, n, l = len(A), len(A[0]), len(B[0])
        if len(B) != n:
            return [[]]
        C = [[0 for _ in range(l)] for _ in range(m)]
        tableB = {} # to store non zero element
        for k, row in enumerate(B):
            tableB[k] = {}
            for j, eleB in enumerate(row):
                if eleB: tableB[k][j] = eleB
        for i, row in enumerate(A):
            for k, eleA in enumerate(row):
                if eleA:
                    for j, eleB in tableB[k].items():
                        C[i][j] += eleA * eleB
        return C
 
'''
Without Table | Approach - 2
TC:- O(m.k.n)
SC:- O(1)
'''
class Solution(object):
    def multiply(self, A, B):
        """
        :type A: List[List[int]]
        :type B: List[List[int]]
        :rtype: List[List[int]]
        """
        if A is None or B is None: return None
        m, n, l = len(A), len(A[0]), len(B[0])
        C = [[0 for _ in range(l)] for _ in range(m)]
        for i, row in enumerate(A):
            for k, eleA in enumerate(row):
                if eleA:
                    for j, eleB in enumerate(B[k]):
                        if eleB: C[i][j] += eleA * eleB
        return C
