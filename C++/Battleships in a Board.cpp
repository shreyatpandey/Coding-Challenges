/*O(1) extra memory*/
class Solution {
    private:
        int row_size = 0;
        int column_size = 0;
        int count_Battleships = 0;
        
public:
    int countBattleships(vector<vector<char>>& board) {
        row_size = board.size();
        column_size = board[0].size();
        for(int i=0;i<row_size;i++)
        {
            for(int j=0;j<column_size;j++)
            {
                  if (board[i][j] == 'X' && !(i > 0 && board[i - 1][j] == 'X' || j > 0 && board[i][j - 1] == 'X')) 
                  
                  {
                    
                     count_Battleships += 1;
                
                    }
            }
        }
        
        return count_Battleships;
    }
};
