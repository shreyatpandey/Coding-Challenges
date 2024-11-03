'''
A parentheses string is valid if and only if:

It is the empty string,
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.

For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
Return the minimum number of moves required to make s valid.

Input:- 
Example 1:

Input: s = "())"
Output: 1
Example 2:

Input: s = "((("
Output: 3

'''


'''
Time-Complexity:- O(n)
Space-Complexity:- O(1)
'''
def minAddToMakeValid(self, S):
        left = right = 0
        for i in S:
            if right == 0 and i == ')':
                left += 1
            else:
                right += 1 if i == '(' else -1
        return left + right
     
    
'''
 Explanation:-
left records the number of ( we need to add on the left of S.
right records the number of ) we need to add on the right of S,
which equals to the number of current opened parentheses.


Loop char c in the string S:
if (c == '('), we increment right,
if (c == ')'), we decrement right.
When right is already 0, we increment left
Return left + right in the end  
'''
        
