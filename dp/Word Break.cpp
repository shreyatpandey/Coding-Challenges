/* Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, 
determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false

*/
class Solution {
    private:
        int input_string_length = 0;
        int dictionary_size = 0;
        int max_length_each_word_in_dictionary = 0;
        int min_length_each_word_in_dictionary = INT_MAX;
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
         input_string_length =s.size(), dictionary_size = wordDict.size();
        
        vector<bool> dp(input_string_length+1,false);
        dp[0]=true;
        
        for(auto word:wordDict)
        {
            max_length_each_word_in_dictionary = max(max_length_each_word_in_dictionary , (int)word.size());
            min_length_each_word_in_dictionary = min(min_length_each_word_in_dictionary , (int)word.size());            
        }
 
        for(int i=1;i<=input_string_length ;++i)
        {
            
            for(int j=min_length_each_word_in_dictionary; j<= max_length_each_word_in_dictionary; ++j )
            {
               if((i-j)>=0)
              {
                  if(find(wordDict.begin(),wordDict.end(),s.substr(i-j,j)) != wordDict.end() && dp[i-j])
                {
                    dp[i]=true;
                    break;
                }
            
            }
            
        }
    }
        return dp[input_string_length];
        
    }
};
