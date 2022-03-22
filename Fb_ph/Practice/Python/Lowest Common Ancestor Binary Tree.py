# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
'''
Approach:- Basic Recursive Approach
TC:- O(n)
SC:- O(n)
'''
class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        def LCA(root,p,q):
            if root == None:
                return
            
            if root == p or root == q:
                return root
            
            root.left = LCA(root.left,p,q)
            root.right = LCA(root.right,p,q)
            
            '''
            Did not understand the below two conditions
            '''
            if root.left and root.right:
                return root
            else:
                root.left = root.left if root.left else root.right
                return root.left
        
        return LCA(root,p,q)
