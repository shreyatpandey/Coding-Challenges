'''
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
'''
'''
For simplicity, each node's value is the same as the node's index (1-indexed). 
For example, the first node with val == 1, the second node with val == 2, and so on. 
The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. 
Each list describes the set of neighbors of a node in the graph.
'''


'''
Problem is adjList is given and not the node
Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
'''

'''
I don't think this is because it's hard or confusing, etc. 
The problem is that the problem states that we're given a node as input, whereas the test cases / submission actually pass you a list of edges.
'''


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
