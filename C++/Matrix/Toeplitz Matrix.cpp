/*
Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
Output: true
*/
//Brute-Force
//TC:- O(M*N)
//SC:- O(1)

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size()-1;i++)
        {
            for(int j=0;j<matrix[0].size()-1;j++)
            {
                if(matrix[i][j] != matrix[i+1][j+1])
                    return false;
            }
        }
        return true;
    }
};

//Hash-Map
//TC:- O(M*N)
//SC:- O(M+N)

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
       unordered_map<int, int>Map;
        for(int Row=0; Row < matrix.size(); Row++) {
            for(int Column=0; Column < matrix[0].size(); Column++) {
                if (Map.count(Row-Column) == 0 ) {
                    Map.insert({Row-Column, matrix[Row][Column]});
                } 
                else if (Map[Row-Column] != matrix[Row][Column]) {
                    return false;
                }
            }
        }
        return true;
    }
};
