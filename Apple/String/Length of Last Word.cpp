/*
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal 
substring
 consisting of non-space characters only.
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int stringLen = s.length();
        int length = 0;
        while(stringLen>0)
        {
            stringLen--;
            if(s[stringLen] != ' ')
            {
                length ++;
            }
            else if (length>0)
            {
                return length;
            }
        }
        return length;
    }
};
