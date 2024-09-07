'''
Given the root node of a binary search tree and two integers low and high, 
return the sum of values of all nodes with a value in the inclusive range [low, high].
'''

'''
Constraints:

The number of nodes in the tree is in the range [1, 2 * 104].
1 <= Node.val <= 105
1 <= low <= high <= 105
All Node.val are unique.

'''

'''
Time-Complexity:- O(N)
Space-Complexity:- O(N)
'''

class Solution:
    def rangeSumBST(self, root: TreeNode, L: int, R: int) -> int:
        def dfs(node):
            if not node: return 0
            if node.val < L: return dfs(node.right)
            elif node.val > R: return dfs(node.left)
            else: return dfs(node.left) + dfs(node.right) + node.val
        return dfs(root)
        
   
        Queue = deque([root])
        ans = 0
        while Queue:
            node = Queue.popleft()
            if low <= node.val <= high:
                ans += node.val
            if node.left:
                Queue.append(node.left)
            if node.right:
                Queue.append(node.right)
        
        return ans
