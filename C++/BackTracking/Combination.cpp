/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
You may return the answer in any order.
Example 1:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

*/


class Solution {
    private:
        void BackTrackHelper(vector<vector<int>>&Combination,vector<int>&Result,int LeftIndex, int RightIndex,int k) ;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>Combination ;
        vector<int>Result ;
        BackTrackHelper(Combination,Result,1,n,k);
        return Combination;
        
    }
};
void Solution::BackTrackHelper(vector<vector<int>>&Combination,vector<int>&Result,int LeftIndex, int RightIndex,int k)
{
    if ( Result.size() == k)
    {
      Combination.emplace_back(Result);
    }
    for(int Loop = LeftIndex; Loop<RightIndex+1 ;Loop++)
    {
        Result.emplace_back(Loop);
        BackTrackHelper(Combination,Result,Loop+1,RightIndex,k);
        Result.pop_back();
        
    }
}
