'''
You need to construct a binary tree from a string consisting of parenthesis and integers.

The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. 
The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure.

You always start to construct the left child node of the parent first if it exists.

Input: s = "4(2(3)(1))(6(5))"
Output: [4,2,6,3,1,5]
'''
'''
Constraints:-
0 <= s.length <= 3 * 10^4
s consists of digits, '(', ')', and '-' only.

'''
'''
Complexity:-
TC:- O(N)
SC:- O(N)
'''
class Solution(object):
    def str2tree(self, s):
        """
        :type s: str
        :rtype: TreeNode
        """
        stack, num = [TreeNode()], ''
        s += '('
        for i, c in enumerate(s):
            if c == ')':
                stack.pop()
            elif c != '(':
                num += c
                if not s[i+1].isdigit():
                    node = TreeNode(int(num))
                    if stack[-1].left:
                        stack[-1].right = node
                    else:
                        stack[-1].left = node
                    stack.append(node)
                    num = ''
        return stack[0].left
