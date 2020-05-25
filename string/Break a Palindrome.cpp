/*
Given a palindromic string palindrome, 
replace exactly one character by any lowercase English letter so that the string becomes the lexicographically smallest possible string that isn't a palindrome.
After doing so, return the final string.  If there is no way to do so, return the empty string.
*/
/*
Example 1:

Input: palindrome = "abccba"
Output: "aaccba"
*/

class Solution {
    private:
        bool checkPalindrome ( string input);
public:
    string breakPalindrome(string palindrome) {
        if (palindrome.length() == 1 ) 
            return "" ;
            
        for(int i=0;i<palindrome.length();i++)
        {
            if ( i == palindrome.length()-1)
            {
                palindrome[i] = palindrome[palindrome.length()-1] + 1;
                return palindrome;
            }
            
            
            if ( palindrome[i] == 'a')
            {
                continue;
            }
            if ( palindrome[i] > 'a')
            {
                char original = palindrome[i] ;
                palindrome[i] = 'a';
                if ( checkPalindrome(palindrome))
                {
                    palindrome[i] = original;
                }
                else
                    return palindrome;
                
            }
        }
        return "";
        
        
    }
};

bool Solution :: checkPalindrome(string input)
{
    for(int i=0;i<input.length()/2;i++)
    {
        if ( input [i] != input[input.length()-i-1])
            return false;
    }
    return true;
}
