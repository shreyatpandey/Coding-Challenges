// grid[i][j] represents a square
// length of square is 1
// perimeter of each cell would be 4 in non-overlapping case
// if one land is surrounded / touched by another land, we need to check only and only left and right cell.
// tempted to check right and left cell, but that is not required

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int RowSize = grid.size();
        if ( !RowSize) return 0;
        int Perimeter = 0;
        for(int i=0;i<RowSize;i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if (grid[i][j] == 1)
                {
                    Perimeter += 4;
                    if ( j && grid[i][j-1] )
                        Perimeter -= 2;
                    if ( i  && grid[i-1][j] )
                        Perimeter -=2;
                }
            }
        }
        return Perimeter;
    }
};
