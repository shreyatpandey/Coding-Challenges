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
