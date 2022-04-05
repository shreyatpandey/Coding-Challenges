"""
# Definition for a Node.
class Node(object):
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""
'''
TC:- O(N+M)
where N is the number of nodes and M is the number of edges
SC:- O(N)
O(H) for the recursion stack and O(N) for the hash map
'''

class Solution(object):
    def cloneGraph(self, node):
        """
        :type node: Node
        :rtype: Node
        """
        Map = {}
        def clone(node):
            if node in Map:
                return Map[node]
            
            copy = Node(node.val)
            Map[node] = copy
            for neighbor in node.neighbors:
                copy.neighbors.append(clone(neighbor))
            
            return copy
        return clone(node) if node else  None
