class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length_string = s.length();
        set<char>set_string;
        int ret_length = 0;
        int i = 0, j =0;
        while(i<length_string && j<length_string)
        {
           if(set_string.count(s[j]) == 0)
               {
                   set_string.emplace(s[j]);
                    j++;
                   ret_length = max(ret_length,j-i);
                   
               }
              else
               {
                   set_string.erase(s[i]);
                   i++;
               }
        }
        return ret_length;
        
        
    }
};
