'''
Appraoch-1:- Stack Solution
TC:- O(N), N is the length of the input string
SC:- O(N-D), D is the total length of the duplicates
'''
class Solution:
    def removeDuplicates(self, S: str) -> str:
        stack = []
        for ch in S:
            if stack and stack == output[-1]: 
                stack.pop()
            else: 
                stack.append(ch)
        return ''.join(stack)
