class Solution {
    private:
        void permute ( vector<string>&Result,string buildparenthesis,int left,int right,int max );
public:
    vector<string> generateParenthesis(int n) {
        string buildparenthesis = "";
        vector<string>Result ;
        permute(Result,buildparenthesis,0,0,n);
        return Result;
        
    }
};
void Solution::permute( vector<string>&Result,string buildparenthesis,int left,int right,int max )
{
    if ( buildparenthesis.length() == 2*max)
    {
        Result.emplace_back( buildparenthesis );
    }
    if (left<max)
    {
        buildparenthesis += '(';
        permute(Result,buildparenthesis,left+1,right,max);
        buildparenthesis.pop_back();
    }
    if ( right < left)
    {
        buildparenthesis += ')';
        permute(Result,buildparenthesis,left,right+1,max);
        buildparenthesis.pop_back();
    }
    
    
}
