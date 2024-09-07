'''
Given the root of a binary tree, return the number of nodes where the value of the node is equal to the average of the values in its subtree.

Note:

The average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.
A subtree of root is a tree consisting of root and all of its descendants.
'''
'''
Input: root = [4,8,5,0,1,null,6]
Output: 5
'''
'''
Constraints:
The number of nodes in the tree is in the range [1, 1000].
0 <= Node.val <= 1000
'''
'''
Complexity
TC:- O(h) where h is the height of tree
'''
class Solution:
    def averageOfSubtree(self, root: Optional[TreeNode]) -> int:
        result = 0
        def traverse(node):
            nonlocal result
            if not node:
                return 0, 0
            
            left_sum, left_count = traverse(node.left)
            right_sum, right_count = traverse(node.right)
            
            s = node.val + left_sum + right_sum
            c = 1 + left_count + right_count
            
            if s // c == node.val:
                result += 1
            
            return s, c
        
        traverse(root)
        return result
