//Approach-1
//It can be thought of matrix with 0 and 1 pixel :- he idea is to count 0-neighbors for each 1-pixel. Because every segment of the perimeter is a border between 0 and 1 pixels. 
//and every border between 0 and 1 pixels is a part of the perimeter. 
//That would have worked even if we had several islands.
// Time Complexity:- O(n*m) where n is the number of rows and m is the number of columns
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;
        int m = grid.size();
        if(!m) return 0;
        int n = grid[0].size();
        if(!n) return 0;
        for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
           if(grid[i][j] == 1)
           {
               if(!j || grid[i][j-1] == 0)
                 ++res;
               if(!i || grid[i-1][j] == 0)
                 ++res;
               if(j == n-1 || grid[i][j+1] == 0)
                 ++res;
               if(i == m-1 || grid[i+1][j] == 0)
                 ++res;
           }
        return res;
        
    }
};

//Approach-2
//More efficient approach
//Time complexity:- O(n*m)
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int RowLength = grid.size();
        int Perimeter = 0;
        /*Edge-Case*/
        if(RowLength == 0)
        {
            return Perimeter;
        }
        int ColumnLength = grid[0].size();
        for(int i=0;i<RowLength;i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if ( grid[i][j] == 1 )
                {
                    Perimeter += 4;
                    if ( j && grid[i][j-1])
                    {
                        Perimeter -= 2;
                    }
                    if ( i && grid[i-1][j])
                    {
                        Perimeter -= 2;
                    }
                }
            }   
        }
        return Perimeter;
    }
};
