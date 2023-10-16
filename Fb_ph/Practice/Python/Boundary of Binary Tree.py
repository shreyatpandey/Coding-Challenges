'''
The boundary of a binary tree is the concatenation of the root, the left boundary, 
the leaves ordered from left-to-right, and the reverse order of the right boundary.

The left boundary is the set of nodes defined by the following:

The root node's left child is in the left boundary. If the root does not have a left child, then the left boundary is empty.
If a node in the left boundary and has a left child, then the left child is in the left boundary.
If a node is in the left boundary, has no left child, but has a right child, then the right child is in the left boundary.
The leftmost leaf is not in the left boundary.
The right boundary is similar to the left boundary, except it is the right side of the root's right subtree.
Again, the leaf is not part of the right boundary, and the right boundary is empty if the root does not have a right child.

The leaves are nodes that do not have any children. For this problem, the root is not a leaf.

Given the root of a binary tree, return the values of its boundary.

 
Input: root = [1,null,2,3,4]
Output: [1,3,4,2]
Explanation:
- The left boundary is empty because the root does not have a left child.
- The right boundary follows the path starting from the root's right child 2 -> 4.
  4 is a leaf, so the right boundary is [2].
- The leaves from left to right are [3,4].
Concatenating everything results in [1] + [] + [3,4] + [2] = [1,3,4,2].

'''



'''
Complexity
Tc:- O(n) 
For complete traversal of tree
Sc:- O(n)
For the recursive stack of depth n
Further for leftBoundary, rightBoundary, and Leaves combined together can be 
of size n where n is the number of nodes
'''

class Solution:
    def boundaryOfBinaryTree(self, root: Optional[TreeNode]) -> List[int]:
        def leftSideDfs(node): # similar to preorder traversal
            if not node.left and not node.right:
                return
            result.append(node.val)
            if node.left:
                leftSideDfs(node.left)
            elif node.right:
                leftSideDfs(node.right)

        def rightSideDfs(node): #similat to postorder traversal
            if not node.left and not node.right:
                return
            if node.right:
                rightSideDfs(node.right)
            elif node.left:
                rightSideDfs(node.left)
            result.append(node.val)
        
        def rootLeaves(node):
            if not node:
                return
            rootLeaves(node.left)
            if node != root and not node.right and not node.left:
                result.append(node.val)
            rootLeaves(node.right)

        result = [root.val]
        if root.left:
            leftSideDfs(root.left)
        rootLeaves(root)
        if root.right:
            rightSideDfs(root.right)
        return result
        
