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
        
   
        stack = [root]
        ans = 0
        while(stack):
            node = stack.pop()
            if node:
                if L <= node.val <= R: ans += node.val
                if L < node.val: stack.append(node.left)
                if R > node.val: stack.append(node.right)
        return ans
