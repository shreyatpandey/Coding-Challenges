/*
Given a string, determine if a permutation of the string could form a palindrome.
Example1

Input: s = "code"
Output: False
Explanation: 
No solution
Example2

Input: s = "aab"
Output: True
Explanation: 
"aab" --> "aba"
Example3

Input: s = "carerac"
Output: True
Explanation: 
"carerac" --> "carerac"
*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#include<ctype.h>

bool palindrome_permutation(char s[], int stringLength)
{
    
    int frequency_count[26] = {0};
    int odd_char = 0;
    for(int i=0;i<stringLength;i++)
    {
         if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
        {
            char temp = tolower(s[i]);
            frequency_count[temp-'a']++;
        }
    }
    for(int i=0;i<26;i++)
    {
        if ( frequency_count[i]%2 != 0)
        {
            odd_char += 1;
        }
         if(odd_char > 1)
        {
            return false;
        }
        
    }
    return true;
}
    
int main()
{
    char Input[] = "Tacte Coa";
    int stringLength = strlen(Input);
    assert(palindrome_permutation(Input,stringLength)==0);
    
    char Input1[] = "aab";
    stringLength = strlen(Input1);
    assert(palindrome_permutation(Input1,stringLength)==1);
    
    return 0;
}
