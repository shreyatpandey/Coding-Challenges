'''
Given a parentheses string s containing only the characters '(' and ')'. A parentheses string is balanced if:

Any left parenthesis '(' must have a corresponding two consecutive right parenthesis '))'.
Left parenthesis '(' must go before the corresponding two consecutive right parenthesis '))'.
In other words, we treat '(' as an opening parenthesis and '))' as a closing parenthesis.

For example, "())", "())(())))" and "(())())))" are balanced, ")()", "()))" and "(()))" are not balanced.
You can insert the characters '(' and ')' at any position of the string to balance it if needed.

Return the minimum number of insertions needed to make s balanced.
'''
'''
Example 1:
Input: s = "(()))"
Output: 1
Explanation: The second '(' has two matching '))', but the first '(' has only ')' matching. We need to add one more ')' at the end of the string to be "(())))" which is balanced.
Example 2:

Input: s = "())"
Output: 0
Explanation: The string is already balanced.
'''
'''
left parenthesis '(' must have a corresponding two consecutive right parenthesis '))'.

Explanation
res represents the number of left/right parentheses already added.
right represents the number of right parentheses needed.

1) case )
If we meet a right parentheses , right--.
If right < 0, we need to add a left parentheses before it.
Then we update right += 2 and res++
This part is easy and normal.

2) case (
If we meet a left parentheses,
we check if we have odd number ')' before.
If we right, we have odd ')' before,
but we want right parentheses in paires.
So add one ')' here, then update right--; res++;.
Note that this part is not necessary if two consecutive right parenthesis not required.

Because we have ), we update right += 2.
'''
'''
Complexity:-
TC:- O(n)
SC:- O(1)
'''
class Solution:
    def minInsertions(self, s: str) -> int:
        res = right = 0
        for c in s:
            if c == '(':
                if right % 2:
                    right -= 1
                    res += 1
                right += 2
            if c == ')':
                right -= 1
                if right < 0:
                    right += 2
                    res += 1
        return right + res
        
