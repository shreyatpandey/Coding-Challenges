class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int i_BeginIndex = 0;
        int i_LastIndex = A.size()-1;
        int i_Temp = i_LastIndex ;
        vector<int>ResultVector(A.size(),0);
        while ( i_BeginIndex<=i_LastIndex )
        {
            if ( A[i_BeginIndex]*A[i_BeginIndex] > A[i_LastIndex]*A[i_LastIndex])
            {
                ResultVector[i_Temp--] = A[i_BeginIndex]*A[i_BeginIndex] ;
                i_BeginIndex ++;
            }
            else
            {
                ResultVector[i_Temp--] = A[i_LastIndex]*A[i_LastIndex];
                i_LastIndex -- ;
            }
        }
        return ResultVector;
    }
};
