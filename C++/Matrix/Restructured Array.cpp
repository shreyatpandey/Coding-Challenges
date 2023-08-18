#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int>QuerySearch(vector<int>&input,vector<vector<int>>&querysearch)
    {
        vector<int>Result ;
        int LengthColumn = input[0] ;
        for(int i=0;i<querysearch.size();i++)
        {
            int IndexPresent = (LengthColumn*(querysearch[i][0]-1)) + querysearch[i][1] ;
            if ( IndexPresent < input.size() )
            {
                Result.push_back ( input[IndexPresent] );
            }
        }
        return Result ;
    }
};

int main()
{
    Solution S;
    vector<int>input = {4,1,2,3,4,5,6,7,8,9,10,11,12} ;
    vector<vector<int>>querysearch = { {3,2} , {2,1} };
    vector<int>Result = S.QuerySearch ( input,querysearch ) ;
    for(int i=0;i<Result.size();i++)
    {
        cout<<"Value:"<<Result[i]<<endl;
    }
    return 0;
    
}
