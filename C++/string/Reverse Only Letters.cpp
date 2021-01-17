/*
Given a string S, return the "reversed" string where all characters that are not a letter stay in the same place, and all letters reverse their positions.
Example 1:

Input: "ab-cd"
Output: "dc-ba"
*/
/* 
No Edge Case check like string is null
Any tabluar spaces or new line character
*/
//SC:- O(N) stack space
//TC:- O(N) , N is length of String
class Solution {
public:
    string reverseOnlyLetters(string S) {
        stack<char>HoldChar;
        int j  = 0;
        while ( j < S.length())
        {
            if ( isalpha(S[j]))
                HoldChar.push(S[j]);
            j +=1 ;
        }
        j = 0;
        while(j<S.length())
        {
            if ( isalpha(S[j]) )
            {
                S[j] = HoldChar.top();
                HoldChar.pop();
            }
            j += 1;
        }
        return S;
    }
};
