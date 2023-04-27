/*
You are given an m x n matrix mat and two integers r and c representing the number of rows and the number of columns of the wanted reshaped matrix.

The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the reshape operation with given parameters is possible and legal, output the new reshaped matrix; 
Otherwise, output the original matrix.
// Hint-1
M[i][j]=M[n*i+j] , where n is the number of cols. 
This is the one way of converting 2-d indices into one 1-d index. Now, how will you convert 1-d index into 2-d indices?
M[i] => M[i/n][i%n] 
*/


class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int rowLength = mat.size();
        int colLength = mat[0].size();
        if ( rowLength*colLength != r*c)
            return mat;
        int count = 0;
        vector<vector<int>>Result(r,vector<int>(c,0));
        for(int row=0;row<rowLength;row++)
        {
            for(int col=0;col<colLength;col++)
            {
                Result[count/c][count%c] = mat[row][col];
                count += 1;
            }
        }
        return Result;
    }
};
