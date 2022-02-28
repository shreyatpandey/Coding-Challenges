'''
Time-Complexity:- O(N) where N is the length of input str
Space-Complexity:- O(N) -- for stack and O(n) for list split 
'''
class Solution:
    def simplifyPath(self, path: str) -> str:
        stack = []
        for token in path.split('/'):
            if token in ('', '.'):
                pass
            elif token == '..':
                if stack: stack.pop()
            else:
                stack.append(token)
        return '/' + '/'.join(stack)
