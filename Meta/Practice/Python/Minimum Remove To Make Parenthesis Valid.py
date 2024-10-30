'''
TC:- O(N)
SC:- O(N)
'''
'''
Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) 
so that the resulting parentheses string is valid and return any valid string.

Example 1:

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
Example 2:

Input: s = "a)b(c)d"
Output: "ab(c)d"
Example 3:

Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.


'''

class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        '''
        Keep a tracker for parenthesis
        '''
        balance = 0
        seen = 0
        charLeft = []
        for char in s:
            if char == '(':
                balance += 1
                seen += 1
            elif char == ')':
                if balance == 0:
                    continue
                balance -= 1
            
            charLeft.append(char)
        
        stringResult = []
        diff = seen - balance
        for char in charLeft:
            if char =='(':
                diff -= 1
                if diff < 0:
                    continue
            stringResult.append(char)
        return "".join(stringResult)

'''
 TC:- O(N)
 SC:- O(1) or O(N)
 '''
'''
Walk through this example:-
s = "ab)(c)"

'''
class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        cnt_open, cnt_close, res = 0, 0, ''
        for ch in s:
            if ch == '(': cnt_open += 1
            if ch == ')': cnt_close += 1
            if cnt_open < cnt_close:
                cnt_close -= 1
            else:
                res = res + ch

        s = res
        #s = ab(c)
        
        cnt_open, cnt_close, res = 0, 0, ''
        for ch in reversed(s):
            if ch == '(': cnt_open += 1
            if ch == ')': cnt_close += 1
            if cnt_close < cnt_open:
                cnt_open -= 1
                #this if condition is not hit
            else:
                res = ch + res
                #this string is constructed in reverse
        return res
