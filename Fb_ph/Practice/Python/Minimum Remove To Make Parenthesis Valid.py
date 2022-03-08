'''
Input:-
Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.


Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.

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
        
        
'''
My-Solution
TC:- O(n)
SC:- O(n)
'''
class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
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
    
        diff = seen - balance
        stringResult = []
        for char in charLeft:
            if char == '(':
                diff -= 1
                if diff < 0:
                    continue
            stringResult.append(char)
            
        return "".join(stringResult)

