class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        /*transpose matrix*/
        int length_matrix = matrix.size();
        for(int i=0;i<length_matrix;i++)
        {
            for(int j=0;j<i;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        /*swap rows*/
        for(int i=0;i<length_matrix;i++)
        {
            for(int j=0;j<(length_matrix)/2;j++)
            {
                swap(matrix[i][j],matrix[i][length_matrix-j-1]);
            }
        }
        
    }
};
