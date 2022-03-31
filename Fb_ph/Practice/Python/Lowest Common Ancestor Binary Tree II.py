'''
Follow Up from LCA-I without checking the node existence
TC:- O(N)
SC:- O(N) for the stack 
'''
'''
Keeping track of Parent Pointers
'''
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        parents = {root.val:None}
        stack = [root]
        while stack:
            node = stack.pop(0)
            if node.left:
                parents[node.left.val] = node
                stack.append(node.left)
            if node.right:
                parents[node.right.val] = node
                stack.append(node.right)
        ancestors = set()
        if p.val not in parents or q.val not in parents: return None
        while p:
            ancestors.add(p.val)
            p = parents[p.val]
        while q and q.val not in ancestors:
            q = parents[q.val]
        return q
      
 '''
 Eulerian Path
 TC:- O(N)
 SC:- O(N)
 '''
def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':

	def euler_tour(node, d):
		nonlocal path, depth, p, q, p_found, q_found
            
		if p_found and q_found: return None
		if node == p: p_found = True
		if node == q: q_found = True

		path.append(node)
		depth.append(d)

		if node.left:
			euler_tour(node.left, d+1)
			path.append(node)
			depth.append(d)

		if node.right:
			euler_tour(node.right, d+1)
			path.append(node)
			depth.append(d)

	# 1. Build an Eulerian Path of the tree
	path, depth = [], []
	p_found, q_found = False, False
	euler_tour(root, 0)

	# 2. If p OR q is not in the tree, then there is no LCA, return None
	if not p_found or not q_found: return None

	# 3. Find the indices of nodes p and q in the Eulerian Path       
	i, j = sorted((path.index(p), path.index(q)))   

	# 4. Find the index of the node with the smallest depth between p and q in the Eulerian Path
	k = min(range(i, j), key = lambda k: depth[k])

	# 5. The node at index k is the LCA of p and q
	return path[k]
