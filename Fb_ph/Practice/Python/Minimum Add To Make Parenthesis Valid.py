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
