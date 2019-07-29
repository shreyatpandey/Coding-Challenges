class Solution {
private:
    int row_ = {0};
    int column_ = {0};
    
public:
bool is_valid(int i, int j) {
    return i >= 0 && i < row_ && j >= 0 && j < column_;
}

void dfs(vector<vector<char>>& grid, int i, int j) {
    if (grid[i][j] == '0') 
    {
        return;
    }
    grid[i][j] = '0';
    if (is_valid(i-1, j)) dfs(grid, i-1, j);
    if (is_valid(i+1, j)) dfs(grid, i+1, j);
    if (is_valid(i, j-1)) dfs(grid, i, j-1);
    if (is_valid(i, j+1)) dfs(grid, i, j+1);
}

int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;
    row_ = grid.size();
    column_ = grid[0].size();
    int count = 0;
    for (size_t i = 0; i < row_; ++i) {
        for (size_t j = 0; j < column_; ++j) {
            if (grid[i][j] == '1') {
                cout<<"i:"<<i<<"j:"<<j<<endl;
                ++count;
                dfs(grid, i, j);
            }
        }
    }
    return count;
}
};
