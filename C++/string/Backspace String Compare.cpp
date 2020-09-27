/*
Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".

*/



//Using Stack
//TC:O(Length of First String + Length of Second String)
//SC:- O(M+N)
class Solution {
    stack<char>HoldCharacterFirstString;
    stack<char>HoldCharacterSecondString;
    stack<char>MakeCharacterStack(string Input);
public:
    bool backspaceCompare(string S, string T) {
        
        HoldCharacterFirstString = MakeCharacterStack(S);
        HoldCharacterSecondString = MakeCharacterStack(T);
        if ( HoldCharacterFirstString.size() != HoldCharacterSecondString.size())
            return false;
        while ( HoldCharacterFirstString.size()>0)
        {
            if (HoldCharacterFirstString.top() != HoldCharacterSecondString.top())
                return false;
            HoldCharacterFirstString.pop();
            HoldCharacterSecondString.pop();
        }
        return true;
    }
};
stack<char> Solution::MakeCharacterStack(string Input)
{
    stack<char>HoldCharacter;
     for ( char ch:Input)
        {
            if (ch == '#' )
            {
                if ( HoldCharacter.size() > 0 )
                    HoldCharacter.pop();
                continue;
            }
            HoldCharacter.emplace(ch);
        }
    return HoldCharacter;
    
}
