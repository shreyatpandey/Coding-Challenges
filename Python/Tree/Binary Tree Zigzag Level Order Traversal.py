# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
"""
Approach-1 : Without using Deque
RunTime : 99.27%
"""
class Solution(object):
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        Queue = []
        ZigZagOrderTraversal = []
        if not root:
            return ZigZagOrderTraversal;
        Queue.append(root)
        level = 0
        while len(Queue) != 0:
            LenQueue = len(Queue)
            ZigZagOrderTraversal.append([])
            i = 0
            while i<LenQueue :
                node = Queue[0]
                del Queue[0]
                ZigZagOrderTraversal[level].append(node.val)
                if node.left:
                    Queue.append(node.left)
                if node.right:
                    Queue.append(node.right)
                i += 1
            if (level & 1) == 1:
                ZigZagOrderTraversal[level].reverse()
            level += 1
        return ZigZagOrderTraversal
                
                
        
