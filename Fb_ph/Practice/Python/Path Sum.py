'''
Given the root of a binary tree and an integer targetSum, 
return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.
'''
'''
Input: root = [1,2,3], targetSum = 5
Output: false
Explanation: There two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.
'''
'''
Complexity
Tc:- O(n) where n is the number of nodes
O(log(n)) for balanced tree
Sc:- O(n) for recursion stack
O(log(n)) for balanced tree
'''
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        def hasSum(root,targetSum):
            if not root:
                return False
            targetSum -= root.val
            if not root.left and not root.right:
                return targetSum==0
            return hasSum(root.left,targetSum) or\
            hasSum(root.right,targetSum)
        if not root:
            return False
        return hasSum(root,targetSum)
