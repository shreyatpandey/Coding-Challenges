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
