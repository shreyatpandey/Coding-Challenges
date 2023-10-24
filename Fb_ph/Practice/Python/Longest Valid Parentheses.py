'''
Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses 
substring
.
Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
'''
'''
Constraints:
0 <= s.length <= 3 * 10^4
s[i] is '(', or ')'.
'''
'''
Approach-1:- Using stack
Tc:- O(len(s))
Sc:- O(n) or O(len(s))
'''
''' 
The stack is used to track indices of (. So whenever we hit a ), we pop the pair from stack and update the length of valid substring.
'''
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        max_length = 0
        stck=[-1] # initialize with a start index
        for i in range(len(s)):
            if s[i] == '(':
                stck.append(i)
            else:
                stck.pop()
                if not stck: # if popped -1, add a new start index
                    stck.append(i)
                else:
                    max_length=max(max_length, i-stck[-1]) # update the length of the valid substring
        return max_length
      
'''
The valid parantheses problem can also be solved using a counter variable. 
Below implementation modifies this approach a bit and uses two counters:left and right for ( and ) respectively.

The pseudo code for this approach:
Increment left on hitting (.
Increment right on hitting ).
If left=right, then calculate the current substring length and update the max_length
If right>left, then it means it's an invalid substring. So reset both left and right to 0.
Perform the above algorithm once on original s and then on the reversed s.
'''
'''
Approach-2:- Without using stack
Tc:- O(len(s)) 
Sc:- O(1)
'''

class Solution:
    def longestValidParentheses(self, s: str) -> int:
        max_length = 0
                
        l,r=0,0        
        # traverse the string from left to right
        for i in range(len(s)):
            if s[i] == '(':
                l+=1
            else:
                r+=1                        
            if l == r:# valid balanced parantheses substring 
                max_length=max(max_length, l*2)
            elif r>l: # invalid case as ')' is more
                l=r=0
        
        l,r=0,0        
        # traverse the string from right to left
        for i in range(len(s)-1,-1,-1):
            if s[i] == '(':
                l+=1
            else:
                r+=1            
            if l == r:# valid balanced parantheses substring 
                max_length=max(max_length, l*2)
            elif l>r: # invalid case as '(' is more
                l=r=0
        return max_length
