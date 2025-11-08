'''
Given two nodes of a DAG (Directed Acyclic Graph) p and q, return their lowest common ancestor (LCA).

Each node will have a reference to its parent nodes (multiple parents possible).
The definition for Node is below:
'''

class Node:
    def __init__(self, val=0, left=None, right=None, parents=None):
        self.val = val
        self.left = left
        self.right = right
        self.parents = parents if parents is not None else []  # List of parent nodes

'''
Approach: 
1. Get all ancestors of node p using BFS
2. Perform BFS from node q until we find a node that's also an ancestor of p
3. The first common ancestor found is the LCA

TC: O(V + E) where V is number of ancestors visited, E is number of parent relationships
SC: O(V) for storing all ancestors in sets and queue
'''
class Solution:
    def lowestCommonAncestor(self, p: 'Node', q: 'Node') -> 'Node':
        # Get all ancestors of p using BFS
        def getAllAncestors(node):
            ancestors = set()
            queue = [node]
            visited = set()
            
            while queue:
                current = queue.pop(0)
                if current in visited:
                    continue
                visited.add(current)
                ancestors.add(current)
                
                # Traverse all parents
                for parent in current.parents:
                    if parent not in visited:
                        queue.append(parent)
            
            return ancestors
        
        # Get all ancestors of p
        p_ancestors = getAllAncestors(p)
        
        # BFS from q to find first common ancestor
        queue = [q]
        visited = set()
        
        while queue:
            current = queue.pop(0)
            if current in visited:
                continue
            visited.add(current)
            
            # If current node is in p's ancestors, it's the LCA
            if current in p_ancestors:
                return current
            
            # Traverse all parents of current node
            for parent in current.parents:
                if parent not in visited:
                    queue.append(parent)
        
        return None  # No common ancestor found


'''
Alternative Approach: Two-pointer with level-order traversal
More efficient for finding shortest common ancestor path

TC: O(V + E)
SC: O(V)
'''
class SolutionAlternative:
    def lowestCommonAncestor(self, p: 'Node', q: 'Node') -> 'Node':
        from collections import deque
        
        # BFS from both nodes simultaneously
        queue_p = deque([p])
        queue_q = deque([q])
        visited_p = {p}
        visited_q = {q}
        
        while queue_p or queue_q:
            # Process one level from p
            if queue_p:
                level_size = len(queue_p)
                for _ in range(level_size):
                    node = queue_p.popleft()
                    # Check if this node was visited from q
                    if node in visited_q:
                        return node
                    
                    for parent in node.parents:
                        if parent not in visited_p:
                            visited_p.add(parent)
                            queue_p.append(parent)
            
            # Process one level from q
            if queue_q:
                level_size = len(queue_q)
                for _ in range(level_size):
                    node = queue_q.popleft()
                    # Check if this node was visited from p
                    if node in visited_p:
                        return node
                    
                    for parent in node.parents:
                        if parent not in visited_q:
                            visited_q.add(parent)
                            queue_q.append(parent)
        
        return None  # No common ancestor found