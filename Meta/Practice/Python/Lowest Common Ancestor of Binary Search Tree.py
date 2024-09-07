'''
TC:- O(log(N))
SC:- O(1)
'''
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        current = root
        while current:
            if p.val > current.val and q.val > current.val:
                current= current.right
            if p.val < current.val and q.val < current.val:
                current = current.left
            else:
                return current
