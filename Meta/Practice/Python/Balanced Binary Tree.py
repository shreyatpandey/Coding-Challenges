'''
Given a binary tree. Determine if its height balanced or not.
Balanced 
Given the definition of a balanced tree
we know that a tree T is not balanced if and only if there is some node
p∈T  such that ∣height(p.left)−height(p.right)∣>1
The tree below has each node is labeled by its height,
as well as the unbalanced subtree highlighted.
'''
'''
Input: root = [3,9,20,null,null,15,7]
Output: true
'''

'''
Complexity:-
Tc:- O(n) 
where n is the number of nodes
Sc:- O(n)
for the recursion stack
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def heightDifference(root):
            if not root:
                return 0
            leftTreeHeight = heightDifference(root.left)
            if leftTreeHeight == -1:
                return -1
            rightTreeHeight = heightDifference(root.right)
            if rightTreeHeight == -1:
                return -1
            if abs(leftTreeHeight - rightTreeHeight) > 1:
                return -1
            return (max(leftTreeHeight,rightTreeHeight)+1)

        return heightDifference(root) != -1 
        
