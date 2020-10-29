class Solution(object):
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        
        RowInitial = 0 
        RowEnd = n-1
        ColumnInitial = 0
        ColumnEnd = n-1
        ResultSpiralMatrix = [[0*i for i in range(n)]for j in range(n)]
        Begin = 1
        while RowInitial<=RowEnd and ColumnInitial<=ColumnEnd :
            for i in range(ColumnInitial,ColumnEnd+1):
                ResultSpiralMatrix[RowInitial][i] = Begin
                Begin += 1
            RowInitial += 1
            for i in range(RowInitial,RowEnd+1):
                ResultSpiralMatrix[i][ColumnEnd] = Begin
                Begin += 1
            ColumnEnd -= 1
            for i in range(ColumnEnd,ColumnInitial-1,-1):
                ResultSpiralMatrix[RowEnd][i] = Begin
                Begin += 1
            RowEnd -= 1
            for i in range(RowEnd,RowInitial-1,-1):
                ResultSpiralMatrix[i][ColumnInitial] = Begin
                Begin += 1
            ColumnInitial += 1
        
        return ResultSpiralMatrix
            
