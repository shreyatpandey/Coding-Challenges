class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>Result(m,vector<int>(n,0));
        if ( m*n != original.size())
            return vector<vector<int>>();
        int totalLength = m*n ;
        int index = 0;
        while(index < original.size())
        {
            int rowIndex = index/n;
            int colIndex = index%n;
            Result[rowIndex][colIndex] = original[index];
            index += 1;
        }
        return Result;
    }
};
