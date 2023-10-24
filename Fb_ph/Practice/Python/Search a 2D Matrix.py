'''
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.
'''
'''
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
'''
'''
Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-10^4 <= matrix[i][j], target <= 10^4
'''
'''
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        auto RowLength = matrix.size();
         if (RowLength ==0 )
        {
            return false;
        }
        auto ColumnLength = matrix[0].size();
        int LeftIndex = 0;
        int RightIndex = RowLength*ColumnLength -1 ; // this would give total number of elements in a matrix
        while(LeftIndex <= RightIndex )
        {
            int MidValue = (LeftIndex + RightIndex)>>1;
            int  MidElement = matrix[MidValue/ColumnLength][MidValue%ColumnLength] ; //Midvalue/ColumnLength gives RowIndex and MidValue%ColumnLength gives ColumnIndex
            if ( target == MidElement)
                return true;
            else if ( MidElement < target )
            {
                LeftIndex = MidValue + 1 ;
            }
            else if ( MidElement > target)
            {
                RightIndex = MidValue - 1;
            }
        }
        return false;
    }
};
'''
