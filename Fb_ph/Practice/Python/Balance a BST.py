'''
Given the root of a binary search tree, return a balanced binary search tree with the same node values. 
If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.
'''
'''
Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.
'''
'''
Constraints:

The number of nodes in the tree is in the range [1, 10^4].
1 <= Node.val <= 10^5
'''
'''
Complexity:-
Tc:- O(n)
where n is the number of nodes
Sc:- O(n)
'''
class Solution:
    def bst(self, nums, i, j):
        if i > j:
            return None
        mid = (i+j) // 2
        node = TreeNode(nums[mid])
        node.left = self.bst(nums, i, mid-1)
        node.right = self.bst(nums, mid+1, j)
        return node
    
    def dfs(self, node):
        if not node:
            return []
        l, r = self.dfs(node.left), self.dfs(node.right)
        return l + [node.val] + r
    
    def balanceBST(self, root: TreeNode) -> TreeNode:
        nums = self.dfs(root)
        return self.bst(nums, 0, len(nums)-1)
