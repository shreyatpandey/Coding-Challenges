/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
*/

class Solution {
    private:
        void BackTrackHelper(int target,vector<int>&combination, 
                             int Leftindex,int RightIndex,
                             vector<int>&candidates,
                             vector<vector<int>>&Results) ;
            
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>Results;
        vector<int>combination;
        BackTrackHelper(target,combination,0,candidates.size(),candidates,Results);
        return Results;
    }
};
void Solution::BackTrackHelper(int target,vector<int>&combination, 
                             int Leftindex,int RightIndex,
                             vector<int>&candidates,
                             vector<vector<int>>&Results)
{
    if(target == 0)
    {
        Results.emplace_back(combination);
        return;
    }
    else if ( target < 0)
    {
        return;
    }
    for(int i=Leftindex ; i<RightIndex ; i++)
    {
        combination.emplace_back(candidates[i]);
        BackTrackHelper(target-candidates[i],combination,i,RightIndex,candidates,Results);
        combination.pop_back();
    }
    
}
