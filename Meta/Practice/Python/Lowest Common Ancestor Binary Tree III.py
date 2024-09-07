'''
Given two nodes of a binary tree p and q, return their lowest common ancestor (LCA).

Each node will have a reference to its parent node. The definition for Node is below:

class Node {
    public int val;
    public Node left;
    public Node right;
    public Node parent;
}

'''
'''
TC:- O(n) where n is the height of the tree
SC:- O(1) 
'''
class Solution:
    def lowestCommonAncestor(self, p: 'Node', q: 'Node') -> 'Node':
        def Depth(node):
            depth = 0
            while node != None:
                depth += 1
                node = node.parent
            return depth
        
        pDepth = Depth(p)
        qDepth = Depth(q)
        
        while pDepth < qDepth:
            q = q.parent
            qDepth -= 1
        
        while qDepth < pDepth:
            p = p.parent
            pDepth -= 1
        
        
        while p != q:
            p = p.parent
            q = q.parent 
        
        return p
