'''
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
'''
from collections import deque
class Solution(object):
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        Queue = deque()
        ZigZagOrderTraversal = []
        if not root:
            return ZigZagOrderTraversal
        Queue.append(root)
        level = 0
        while len(Queue) != 0:
            LenQueue = len(Queue)
            ZigZagOrderTraversal.append([])
            i = 0
            while i<LenQueue :
                node = Queue.popleft()
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
