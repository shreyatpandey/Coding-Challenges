/*
Given a binary string s, return the number of non-empty substrings that have the same number of 0's and 1's,
and all the 0's and all the 1's in these substrings are grouped consecutively.
Input: s = "10101"
Output: 4
Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.
*/
//TC:- O(n)
//SC:- O(1)
class Solution {
public:
    int countBinarySubstrings(string s) {
        int currentIndex = 1, previous = 0, Result = 0;
        for(int i=1;i<s.size();i++)
        {
            if(s[i] == s[i-1])
            {
                currentIndex += 1;
            }
            else
            {
                Result += min(currentIndex,previous);
                previous = currentIndex;
                currentIndex = 1;
            }
        }
        Result = Result + min(currentIndex,previous);
        return Result;
    }
};
