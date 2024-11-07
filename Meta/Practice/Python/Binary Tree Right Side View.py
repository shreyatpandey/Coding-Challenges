#Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
'''
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Example 2:

Input: root = [1,null,3]
Output: [1,3]
Example 3:

Input: root = []
Output: []
'''
'''
Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
'''
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
Approach:- BFS without using Deque
TC:- O(N) where N is the number of nodes
SC:- O(N) is the space of Queue/Deque
'''

from collections import deque
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
        
