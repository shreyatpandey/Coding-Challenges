
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

'''
Approach-1: Using deque
RunTime:- 98.01% fast
'''
from collections import deque
class Solution(object):
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        queue = deque([root])
        BinaryTreeRightSideView = []
        if not root:
            return BinaryTreeRightSideView
        while len(queue) != 0:
            LenQueue = len(queue)
            for i in range(LenQueue):
                node = queue.popleft()
                if i == LenQueue -1 :
                    BinaryTreeRightSideView.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
        return BinaryTreeRightSideView
 
 '''
 Approach-2: Without using deque, using list
 Runtime:- 48.07% fast
 '''
class Solution(object):
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        queue = []
        BinaryTreeRightSideView = []
        if not root:
            return BinaryTreeRightSideView
        queue.append(root)
        while len(queue) != 0:
            LenQueue = len(queue)
            for i in range(LenQueue):
                node = queue[0]
                del queue[0]
                if i == LenQueue -1 :
                    BinaryTreeRightSideView.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
        return BinaryTreeRightSideView
        
        
        
