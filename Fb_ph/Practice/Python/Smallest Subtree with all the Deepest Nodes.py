
'''
Given the root of a binary tree, the depth of each node is the shortest distance to the root.

Return the smallest subtree such that it contains all the deepest nodes in the original tree.

A node is called the deepest if it has the largest depth possible among any node in the entire tree.

The subtree of a node is a tree consisting of that node, plus the set of all descendants of that node.

Input: root = [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]
Explanation: We return the node with value 2, colored in yellow in the diagram.
The nodes coloured in blue are the deepest nodes of the tree.
Notice that nodes 5, 3 and 2 contain the deepest nodes in the tree but node 2 is the smallest subtree among them, so we return it.

Constraints:

The number of nodes in the tree will be in the range [1, 500].
0 <= Node.val <= 500
The values of the nodes in the tree are unique.

'''
'''
Let us use dfs(level, node) function, where:

level is distance between root of our tree and current node we are in.
result of this function is the distance between node and its farthest children: that is the largest numbers of steps we need to make to reach leaf.
So, how exactly this function will work:

If not node, then we are in the leaf and result is 0.

in other case, we run recursively dfs for node.left and node.right.
What we keep in our cand: in first value sum of distances to root and to farthest leaf, second value is distance to root and final value is current node.
Note, that cand[0] represent length of the longest path going from root to leaf, through our node.
if cand[0] > self.ans[0]: it means that we found node with longer path going from root to leaf, and it means that we need to update self.ans.
Also, if cand[0] = self.ans[0] and also lft = rgh, it means that we are now on the longest path from root to leaf and we have a fork: 
we can go either left or right and in both cases will have longest paths. Note, that we start from root of our tree, 
so it this way we will get fork which is the closest to our root, and this is exactly what we want in the end.
Finally, we return cand[0] - cand[1]: distance from node to farthest children.

'''
'''
Complexity: time complexity is O(n): to visit all nodes in tree. 
Space complexity is O(h), where h is height of tree.
'''
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def subtreeWithAllDeepest(self, root: TreeNode) -> TreeNode:
        def dfs(lvl, node):
            nonlocal ans
            if not node: return 0
            lft = dfs(lvl + 1, node.left)
            rgh = dfs(lvl + 1, node.right)
            cand = (max(lft, rgh) + 1 + lvl, lvl, node)

            if cand[0] > ans[0] or cand[0] == ans[0] and lft == rgh:
                ans = cand
          
            return cand[0] - cand[1]
        ans = (0, 0, None)
        dfs(0, root)
        return ans[2]
