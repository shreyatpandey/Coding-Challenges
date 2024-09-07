'''
Approach:-DFS
TC:- O(n)
SC:- O(n)
'''
class Solution:
    def addOneRow(self, root: Optional[TreeNode], val: int, depth: int) -> Optional[TreeNode]:
        if depth == 1: return TreeNode(val, root)
        
        def add_row(node, depth):
            if node:
                if depth == 1:
                    node.left  = TreeNode(val, left  = node.left)
                    node.right = TreeNode(val, right = node.right)

                add_row(node.left, depth - 1)
                add_row(node.right, depth - 1)
            
        add_row(root, depth - 1)
        
        return root

'''
Approach:-BFS
TC:- O(n)
SC:- O(n)
'''
class Solution:
    def addOneRow(self, root: Optional[TreeNode], val: int, depth: int) -> Optional[TreeNode]:
        if depth == 1: return TreeNode(val, root)
        
        queue = deque([root])
        while depth - 1 != 1:
            for _ in range(len(queue)):
                node = queue.popleft()
                if node.left:  queue.append(node.left)
                if node.right: queue.append(node.right)
            depth -= 1
                
        while queue:
            node = queue.popleft()
            node.left  = TreeNode(val, left  = node.left)
            node.right = TreeNode(val, right = node.right)
            
        return root
