class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>result(numRows,vector<int>(numRows,0));
        for(int i=0;i<numRows;i++)
        {
            result[i][0] = 1;
            result[i][i] = 1;
            for(int j=1;j<i;j++)
            {
                result[i][j] = result[i-1][j-1] + result[i-1][j];
            }
        }
  
        for(int i=0;i<numRows;i++)
        {
            int m = i+1;
            result[i].erase(result[i].begin()+m,result[i].begin()+numRows);
        }
        
        return result;
        
    }
};
