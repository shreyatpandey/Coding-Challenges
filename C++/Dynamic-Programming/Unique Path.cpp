//Approach:- Top-Down + Memoization
//TC:- O(N*M)
//SC:- O(N*M)
class Solution {
    int Paths(vector<vector<int>>&Dp,int m,int n,int i,int j);
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>Dp(m,vector<int>(n,-1));
        return Paths(Dp,m,n,0,0);
    }
};
int Solution::Paths(vector<vector<int>>&Dp,int m,int n,int i,int j)
{
    if (i>=m || j>= n)
        return 0;
    if(i == m-1 || j == n-1)
        return 1;
    if ( Dp[i][j] != -1)
        return Dp[i][j];
    int answer = Paths(Dp,m,n,i+1,j) + Paths(Dp,m,n,i,j+1);
    Dp[i][j] = answer;
    return answer;
}
