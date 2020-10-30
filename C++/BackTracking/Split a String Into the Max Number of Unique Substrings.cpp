/* Given a string s, return the maximum number of unique substrings that the given string can be split into.*/
/*
Example 2:
Input: s = "aba"
Output: 2
Explanation: One way to split maximally is ['a', 'ba']
*/

class Solution {
    private:
        int findMaxSubstring(set<string>UniqueString , string s, int start);
public:
    int maxUniqueSplit(string s) {
        set<string>UniqueString ;
        return findMaxSubstring(UniqueString, s, 0);
        
    }
};
 int Solution::findMaxSubstring(set<string>UniqueString, string s, int start)
 {
     
        if(start >=s.length())
        {
            return 0;
        }
        
        int res = 0;
        bool check = false;
        for(int i=start;i<s.length();i++)
        {
             auto EndIndex = (i-start)+1;
             auto sub_str = s.substr(start,EndIndex);
             if(UniqueString.count(sub_str)==0)
             {
                 UniqueString.insert(sub_str);
                 int next_count = findMaxSubstring(UniqueString, s, i+1);
                 
                 if(next_count != -1)
                 {
                     res = max(next_count+1, res);
                     check = true;
                 }
                 UniqueString.erase(sub_str);
             }
        }
        
        if(check==false)
        {
            return -1;
        }
        return res;
 }
        
