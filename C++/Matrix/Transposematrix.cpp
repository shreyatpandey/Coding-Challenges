class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<vector<int>>ResultMatrix(A[0].size(),vector<int>(A.size(),0));
        
        for(int i=0;i<A.size();i++)
        {
            for ( int j=0;j<A[0].size();j++)
            {
                ResultMatrix[j][i] = A[i][j];
            }
        }
        
        return ResultMatrix;
    }
};

