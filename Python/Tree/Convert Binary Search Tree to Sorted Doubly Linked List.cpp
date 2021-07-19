"""
# Definition for a Node.
class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
"""

class Solution:
    def treeToDoublyList(self, root: 'Node') -> 'Node':
        if not root:
            return None
        head,tail = None,None
        def InOrder(root) : #return type void
            nonlocal head,tail
            if not root:
                return 
            InOrder(root.left)
            if tail:
                tail.right = root
                root.left = tail
            else:
                head = root
            tail = root
            InOrder(root.right)

        InOrder(root)
        tail.right = head
        head.left = tail

        return head
        
