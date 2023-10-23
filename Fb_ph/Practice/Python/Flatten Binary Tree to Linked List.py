'''
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list 
and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.

Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [0]
Output: [0]
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
'''
'''
Follow up: Can you flatten the tree in-place (with O(1) extra space)?
'''

'''
Approach:- Iterative
Tc:- O(n)
Sc:- O(1)
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
