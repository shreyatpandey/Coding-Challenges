class Solution(object):
    def transpose(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        ResultMatrix=[[0*j for j in range(len(A))]for i in range(len(A[0]))]
        for i in range(len(A)):
            for j in range(0,len(A[0])):
                ResultMatrix[j][i] = A[i][j]
        
        return ResultMatrix
                
                
