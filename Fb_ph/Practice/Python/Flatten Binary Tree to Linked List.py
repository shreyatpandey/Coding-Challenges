'''
Approach:- Iterative
'''
class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        #
        ## iteration
        # For each node cur, if it has a left subtree, we put it on the right
        # subtree of the node cur, and we put the right subtree of the node cur
        # at the right bottom of the left subtree. 
        cur = root
        while cur:
            if cur.left:
                left = cur.left        # get the left subtree of cur
                right = cur.right      # get the right subtree of cur
                cur.left = None        # cur's left subtree set to be None
                cur.right = left       # switch the left subtree to the right subtree
                while left.right:      # get the far-rigth leaf of the left subtree
                    left = left.right  
                left.right = right     # put the right subtree of cur as the right subtree of the far-right leaf
            cur = cur.right            # go down the right direction

'''
Approach:- Recursion
'''
class Solution:
    
    def __init__(self):
        self.prev = None
    
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        #
        ## recursion
        if not root:
            pass
        else:
            self.flatten(root.right)
            self.flatten(root.left)
            root.right = self.prev
            root.left = None
            self.prev = root
