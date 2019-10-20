/* Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.*/

class Solution 
{
    private:
        int _row_length;
        int _column_length ;
        int _max_square_length ;
        
            
            
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        _row_length = matrix.size();
        _column_length = _row_length>0?matrix[0].size():0;
        vector<vector<int>>dp(_row_length+1,vector<int>(_column_length+1, 0));
        _max_square_length = 0;
        for(int i=1;i<=_row_length;i++)
        {
            for(int j=1;j<=_column_length;j++)
            {
                if(matrix[i-1][j-1] == '1')
                {
                    dp[i][j] = min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1])+1;
                    _max_square_length = max(_max_square_length,dp[i][j]);
                }
            }
        }
        return (_max_square_length *_max_square_length);
        
    }
};
