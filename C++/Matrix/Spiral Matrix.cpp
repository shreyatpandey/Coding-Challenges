// Faster than 100% Submission for C++
class Solution {
    private :
        vector<int>ResultMatrix ;
        int ColumnLength  = 0;
        int RowLength = 0 ;
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if ( matrix.size() == 0)
            return ResultMatrix ;
        RowLength = matrix.size () ;
        ColumnLength = matrix[0].size () ;
        int i = 0;
        int j = 0;
        while ( RowLength>0 && ColumnLength> 0)
        {
            for ( int k = 0 ; k<ColumnLength; k++)
            {
                ResultMatrix.emplace_back(matrix[i][j]) ;
                j++;
            }
            j -= 1;
            RowLength -= 1;
            if ( RowLength == 0 )
                break ;
            for ( int k = 0 ; k < RowLength ; k++)
            {
                i++;
                ResultMatrix.emplace_back ( matrix[i][j] );
            }
            ColumnLength -= 1;
            if ( ColumnLength == 0 )
                break ;
            for ( int k= 0; k < ColumnLength ; k++ )
            {
                j-- ;
                ResultMatrix.emplace_back( matrix[i][j] );
            }
            RowLength -= 1;
            if ( RowLength == 0)
                break ;
            for(int k = 0 ; k < RowLength ; k++ )
            {
                i -- ;
                ResultMatrix.emplace_back( matrix[i][j] ) ;
            }
            j += 1;
            ColumnLength -= 1;
            if ( ColumnLength == 0 )
                break;
                
        }
        
        return ResultMatrix ;
    }
};
