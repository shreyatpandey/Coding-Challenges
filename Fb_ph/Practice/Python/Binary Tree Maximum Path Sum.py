'''
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them.
A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
'''
'''
Constraints:-
The number of nodes in the tree is in the range [1, 3 * 104].
-1000 <= Node.val <= 1000
'''
'''
Wording:-
Key is that the node value can be negative.
The idea is to update node values with the biggest, positive cumulative sum gathered by its children:

If both contributions are negative, no value is added. We dont need to include nodes with negative values as it does not give the maximum path.
If both are positive, only the biggest one is added, so that we don't include both children during the rest of the tree exploration.
Leaves return its own value and we recursively work our way upwards.
A global maximum sum variable is maintained so that every path can be individually checked, 
while updated node values on the tree allow for exploration of other valid paths outside of the current subtree.

'''
'''
Complexity:-
TC:- O(N) where N is the number of nodes, as we are visiting each node not more than 2 times
SC:- O(H) , where H is the height of the tree to keep track of recursion stack for DFS traversal.
In avg case of balanced tree the tree height = O(log(N)), in worst case its H = N

'''


class Solution(object):
    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.max_sum = float('-inf')
        self.dfs(root)
        return self.max_sum
    
    def dfs(self, node):
        if not node: return 0
        
        # only add positive contributions
        leftST_sum = max(0, self.dfs(node.left))
        rightST_sum = max(0, self.dfs(node.right))

        # check if cumulative sum at current node > global max sum so far
        # this evaluates a candidate path
        self.max_sum = max(self.max_sum, leftST_sum + rightST_sum + node.val)
        
        # add to the current node ONLY one of the children contributions
        # in order to maintain the constraint of considering only paths
        # if not, we would be exploring explore the whole tree - against problem definition
        return max(leftST_sum, rightST_sum) + node.val
        

