'''
Given a balanced parentheses string s, return the score of the string.

The score of a balanced parentheses string is based on the following rule:

"()" has score 1.
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.
 

Example 1:

Input: s = "()"
Output: 1
'''
'''
Constraints:-
2 <= s.length <= 50
s consists of only '(' and ')'.
s is a balanced parentheses string.

'''
'''
Approach-1: Using stack
TC:- O(n)
SC:- O(n) for stack
'''
class Solution(object):
    def scoreOfParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        stack = [0]
        for char in s:
            if char == '(':
                stack.append(0)
            else:
                lastVal = stack.pop()
                stack[-1] += max(2*lastVal,1)
        
        return stack.pop()
'''
Approach-2: Using O(1) space
TC:- O(n)
SC:- O(1)
'''
'''
Wording:
Keep a track of '(' and increment the cound and ')' decrement the count. If we meet '()', then we would need to calculate the power of 2.
Because the final answer would have the power of 2 , because of every '()' we meet, the exterior parenthesis would contain the this inner set of '()'
TC:- O(n)
SC:- O(1)
'''
class Solution(object):
    def scoreOfParentheses(self, S):
        """
        :type s: str
        :rtype: int
        """
        ans = 0
        balance = 0
        for i, x in enumerate(S):
            if x == '(':
                balance += 1
            else:
                balance -= 1
                if S[i-1] == '(':
                    ans += (pow(2,balance))
        return ans
