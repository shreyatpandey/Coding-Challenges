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
 

'''
Solution Beats 99.62%
'''
class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        result = "/"
        stk = []
        listpath = path.split("/")
        for char in listpath:
            if char == "." or char =='':
                continue
        
            elif char == ".." :
                if len(stk) > 0:
                    del stk[-1]    
        
            else:
                stk.append(char)
        
        while len(stk) > 0:
            lastchar = stk[0]
            del stk[0]
            if len(stk) == 0:
                result += lastchar 
            else:
                result += lastchar + "/"
    
        return result
