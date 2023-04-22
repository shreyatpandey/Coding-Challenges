/*
Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. 
Return all such possible sentences in any order.
Note that the same word in the dictionary may be reused multiple times in the segmentation.
Example 1:

Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]
Example 2:

Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
Explanation: Note that you are allowed to reuse a dictionary word.
*/

//Approach-1:- HashMap + Backtracking
class Solution {
public:
    unordered_map<string , bool> map;
    void dfs(string s, vector<string> &ans, string str)
    {
        if(s.size() == 0)
        {
            str.pop_back();
            ans.push_back(str);
        }
        for(int i = 0; i < s.size(); i++)
        {
            string left = s.substr(0, i + 1);
            string right = s.substr(i + 1);
            if(map.find(left) != map.end())
            {
                dfs(right, ans, str + left + " ");
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        vector<string> ans;
        for(auto w: wordDict) map[w] = true;
        dfs(s, ans, "");
        return ans;
    }
};

//Approach-2:- Dp
vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        unordered_set<string>word_Set(wordDict.begin(),wordDict.end());
         vector<vector<string>>dp(n+1,vector<string>());
         dp[0].push_back("");
    
          for(int i = 0; i < n; ++i){
            for(int j = i+1; j <= n; ++j){
                string temp = s.substr(i, j-i);
                if(word_Set.count(temp)){
                    for(auto x : dp[i]){
                        dp[j].emplace_back(x + (x == "" ? "" : " ") + temp);  
                    }
                }
            }
        }
         return dp[n];
    }
