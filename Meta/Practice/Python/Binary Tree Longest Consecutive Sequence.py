'''
Given the root of a binary tree, return the length of the longest consecutive sequence path.

A consecutive sequence path is a path where the values increase by one along the path.

Note that the path can start at any node in the tree, and you cannot go from a node to its parent in the path.
Input: root = [1,null,3,2,4,null,null,null,5]
Output: 3
Explanation: Longest consecutive sequence path is 3-4-5, so return 3.
'''


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestConsecutive(self, root: Optional[TreeNode]) -> int:
        max_ = 1
        def dfs(node=root):
            if not node:
                return 0
            left, right = dfs(node.left), dfs(node.right)
            left = left+1 if (node.left and node.left.val == node.val+1) else 1
            right = right+1 if (node.right and node.right.val == node.val+1) else 1
            nonlocal max_
            max_ = max(left, right, max_)
            return max(left, right)
        dfs()
        return max_
        
