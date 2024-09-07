'''
Python InOrder Traversal
Time-Complexoty:- O(n)
Just use inorder traversal, which finds the nodes in ascending order, and store the head and previous node in global variables. 
After the traversal is finished, prev is the "tail" of the double linked list so just connect it to the head.
Why InOrder? The Inorder traversal of a BT would always give elements in sorted order
Time-Complexity:- O(N)
Space-Complexioty:- O(N) for the recursion stack

Convert a Binary Search Tree to a sorted Circular Doubly-Linked List in place.
'''

class Solution(object):
    head = None
    prev = None

    def treeToDoublyList(self, root):
        if not root: return None
        self.treeToDoublyListHelper(root)
        #final linking of the head and and last node
        self.prev.right = self.head
        self.head.left = self.prev
        return self.head

    def treeToDoublyListHelper(self, node):
        if not node: return
        self.treeToDoublyListHelper(node.left)
        if self.prev:
            node.left = self.prev
            self.prev.right = node
        else:  # We are at the head.
            self.head = node
        self.prev = node
        self.treeToDoublyListHelper(node.right)
'''
Approach:- Iterative
Tc:- O(n)
Sc:- O(n)
'''
class Solution:
    def treeToDoublyList(self, root: 'Node') -> 'Node':
        ## RC ##
        ## APPROACH : ITERATIVE + STACK ##
        ## Similar to Leetcode: 94 Binary tree inorder traversal ##
        ## LOGIC ##
        ## 1. using pre order traversal, store the prev node and for current node point that prev node and for that prev node point this current node ##
        ## 2. first when currNode is Node, top of stack is the FirstNode, and as iterating change every next node to LastNode ##
        ## 3. At last link first and last nodes ##
        
		## TIME COMPLEXITY : O(N) ##
		## SPACE COMPLEXITY : O(N) ##

        if not root: 
            return root
        
        if not root.left and not root.right:
            root.left = root
            root.right = root
            return root
        
        stack = []
        currNode = root
        prevNode = None
        firstNode = None
        lastNode = None
        while( stack or currNode ):
            while( currNode ):
                stack.append( currNode )
                currNode = currNode.left
            
            node = stack.pop()
            node.left = prevNode
            if( prevNode ):
                prevNode.right = node
            prevNode = node
            
            if( not firstNode ): 
                firstNode = node
            lastNode = node
            
            currNode = node.right
        
        # joining first and last numbers
        firstNode.left = lastNode
        lastNode.right = firstNode
        
        return firstNode
