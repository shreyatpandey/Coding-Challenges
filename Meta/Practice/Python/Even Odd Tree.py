'''
A binary tree is named Even-Odd if it meets the following conditions:

The root of the binary tree is at level index 0, its children are at level index 1, their children are at level index 2, etc.
For every even-indexed level, all nodes at the level have odd integer values in strictly increasing order (from left to right).
For every odd-indexed level, all nodes at the level have even integer values in strictly decreasing order (from left to right).
Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return false.

'''

'''
Constraints:
The number of nodes in the tree is in the range [1, 10^5].
1 <= Node.val <= 10^6
'''

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

'''
Approach :- BFS
n - number of nodes
TC:- O(n)
SC:- O(n)
Space complexity is because of queue
'''
class Solution(object):
    def isEvenOddTree(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: bool
        """
        q = deque([(root, 0)])
        while q:
            nq = deque()
            prev = None
            while q:
                node, level = q.popleft()

                # node value and level value cannot match at all
                # requirement of the question
                if node.val % 2 == level % 2:
                    return False

                if prev is not None:
                    if node.val == prev:
                        return False
 
                    if level%2 == 0:
                        if node.val < prev: #even case for increasing
                            return False
                    else:
                        if node.val > prev: # odd case for decreasing
                            return False

                prev = node.val
                
                if node.left:
                    nq.append((node.left, level + 1))
                if node.right:
                    nq.append((node.right, level + 1))

            q = nq

        return True

