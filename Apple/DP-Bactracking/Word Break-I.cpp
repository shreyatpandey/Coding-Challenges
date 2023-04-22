/*
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.
Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
*/
// TC:-O(N^3)
//SC:-O(N)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>word_set(wordDict.begin(),wordDict.end());
        int n=s.size();
        vector<bool>dp(n+1,0);
        dp[0]=1;
        for(int i=0;i<n;i++){
            if(!dp[i])continue;
            for(int j=i+1;j<=n;j++){
                if( word_set.count(s.substr(i,j-i)))
                dp[j]=1;
            }
        }
        return dp[n];
    }
};
