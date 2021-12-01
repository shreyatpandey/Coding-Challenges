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
