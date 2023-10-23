'''
Given the root of a binary search tree, 
rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, 
and every node has no left child and only one right child.
'''
'''
Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
'''
'''
Constraints:

The number of nodes in the given tree will be in the range [1, 100].
0 <= Node.val <= 1000
'''
'''
Approach:- DFS
Tc:- O(n)
where n is the number of nodes
Sc:- O(n)
For recursion stack space
'''
class Solution:
    def increasingBST(self, root: TreeNode,nxt=None) -> TreeNode:
        # Base case: If we run all the way down to None, then we can stop and just look at the
        # nxt node, because there are no longer any other nodes in the way.
        if not root: return nxt
        # If you go left nxt is the last node you were at. So at leaves, if you look at the left
        # None-child, you just get the leaf back as res.
        res = self.increasingBST(root.left, root)
        # If you go right, nxt is somewhere in the parentage of whatever you were just at, and
        # it shouldn't need to change. So at leaves, if you look at the right None-child, you
        # get back the thing that should appear after the leaf, and you can set it as the leaf's
        # .right.
        root.right = self.increasingBST(root.right, nxt)
        # The whole subtrees rooted at root.left and root.right have now been put in order, and
        # the left one references this (root) node, and this node references the smallest node
        # in the right in-order tree. So we are clear to remove the left reference from this node.
        root.left = None
        # res will hold the smallest-value node reached below this frame. Return it both so we
        # can properly assign root.right above and so that the initial call to this function gets
        # back the new root.
        return res

