"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution(object):
    def preorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """
        if root == None:
            return []
        stack = []
        result = []
        stack.append(root)
        while len(stack) != 0:
            node = stack.pop()
            result.append(node.val)
            if node != None:
                node.children.reverse()
                stack.extend(node.children)
        return result
