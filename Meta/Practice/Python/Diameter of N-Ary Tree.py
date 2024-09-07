'''
Given a root of an N-ary tree, you need to compute the length of the diameter of the tree.

The diameter of an N-ary tree is the length of the longest path between any two nodes in the tree. This path may or may not pass through the root.

(Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value.)

Constraints:

The depth of the n-ary tree is less than or equal to 1000.
The total number of nodes is between [1, 104].

'''
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []
"""

'''
Wording:-
n this solution, we are exploring all nodes of the input N-Ary Tree using Depth-First Search.

Length of the longest path passing through a node = 1st Max Height among N children + 2nd Max Height among N children + 2

Thus, Diameter of the entire tree = Max(Length of the longest path passing through each node)

'''


'''
Complexity:-
For complexity calculation, let us assume:
N = Maximum number of children of a node. Each node can have 0 to N nodes.
M = Total number of nodes in the input N-Ary Tree.

Time Complexity:

In a Tree, if there are M nodes, then there will be M-1 edges.
In this solution, each node and each edge will be visited once.
Thus, Total Time Complexity = O(V + E) = O(M + M-1) = O(M)

Space Complexity: O(Height of the input tree)

In worst case, for a skewed tree, height can be equal to the total number of nodes. Thus, worst case space complexity = O(M)
In best / average case, for a balanced N-ary tree, height = O(log M / log N) = O(logN M)
'''

class Solution:
    def diameter(self, root: 'Node') -> int:
        """
        :type root: 'Node'
        :rtype: int
        """
        def diameterHelper(root):
            if not root.children:
                return 0
            
            #Setting below maximums to -1 helps in the case if there is only one child
            # node of this root node.
            maxHeight1 = -1
            maxHeight2 = -1
            
            for child in root.children:
                childHeight = diameterHelper(child)
                if childHeight > maxHeight1:
                    maxHeight2 = maxHeight1
                    maxHeight1 = childHeight
                elif childHeight > maxHeight2:
                    maxHeight2 = childHeight
            
            maxDiameter[0] = max(maxDiameter[0],maxHeight1+maxHeight2 +2)
            return maxHeight1 + 1
        if not root or not root.children:
            return 0
        maxDiameter = [0]
        diameterHelper(root)
        return maxDiameter[0]
