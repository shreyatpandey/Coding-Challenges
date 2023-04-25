/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
*/

//TC:- O(Nk)
//SC:- For the result , O(Nk)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>answer;
        vector<vector<string>>result;
        vector<int>count(26);
        for(int i=0;i<strs.size();i++)
        {
            //memset(count,0,27); //this did not work
            fill(count.begin(),count.end(),0);
            string temp = strs[i];
            for(int j=0;j<temp.length();j++)
            {   count[temp[j]-'a']++; }
            string sb = "";
            for(int k=0;k<26;k++)
            {
                sb.append(":");
                sb.append(to_string(count[k]));
            }
            
                answer[sb].push_back(strs[i]);
           
        }
        for(auto &x: answer)
        {
            result.push_back(x.second);
        }
        return result;
        
    }
};
