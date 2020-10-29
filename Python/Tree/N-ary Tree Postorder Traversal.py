"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution(object):
    def postorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """
        stack = []
        NaryTreePreorderTraversal = []
        stack.append(root)
        while len(stack) != 0:
            node = stack[-1]
            del stack[-1]
            if node != None:
                NaryTreePreorderTraversal.append(node.val)
                stack.extend(node.children)
        NaryTreePreorderTraversal.reverse()
        return NaryTreePreorderTraversal
        
