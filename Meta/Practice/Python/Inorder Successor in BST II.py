'''
Given a node in a binary search tree, return the in-order successor of that node in the BST. 
If that node has no in-order successor, return null.

The successor of a node is the node with the smallest key greater than node.val.

You will have direct access to the node but not to the root of the tree. 
Each node will have a reference to its parent node. Below is the definition for Node:

class Node {
    public int val;
    public Node left;
    public Node right;
    public Node parent;
}
'''
'''
Complexity
TC:- O(N) for skewed tree
O(log(N)) for balanced tree
SC:- O(1) since we are not using any extra space
'''
class Solution:
    def inorderSuccessor(self, node: 'Node') -> 'Optional[Node]':
        # the successor is somewhere lower in the right subtree
        if node.right:
            node = node.right
            while node.left:
                node = node.left
            return node
        
        # the successor is somewhere upper in the tree
        while node.parent and node == node.parent.right:
            node = node.parent
        return node.parent
        
