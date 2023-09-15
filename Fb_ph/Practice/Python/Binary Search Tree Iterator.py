'''
''
Question:-
Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. 
The pointer should be initialized to a non-existent number smaller than any element in the BST.

boolean hasNext() 
--Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
int next() 
-- Moves the pointer to the right, then returns the number at the pointer.

Notice that by initializing the pointer to a non-existent smallest number, 
the first call to next() will return the smallest element in the BST.
You may assume that next() calls will always be valid. 
That is, there will be at least a next number in the in-order traversal when next() is called.
'''
'''
TC:-
hasNext:- O(1)
We just check if there are any elements left in the stack or not
This can be done in O(1)

next- O(1)
It involves two major operation. 
Pop Operation in Stack is O(1)
Now for the while loop we are only looking for the left traversal of the tree
We are not processing the entire tree/traversing entire tree
Amortized(Average) Time:- O(1)

SC:- O(N)
for the stack space to contain N Node of the tree
'''
'''
Sample Output:-
stack: [TreeNode{val: 7, left: TreeNode{val: 3, left: None, right: None},
right: TreeNode{val: 15, left: TreeNode{val: 9, left: None, right: None},
right: TreeNode{val: 20, left: None, right: None}}}, 
TreeNode{val: 3, left: None, right: None}]
node.val: 3
x: None
node.val: 7
x: TreeNode{val: 15, left: TreeNode{val: 9, left: None, right: None}, right: TreeNode{val: 20, left: None, right: None}}
node.val: 9
x: None
node.val: 15
x: TreeNode{val: 20, left: None, right: None}
node.val: 20
x: None
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:

    def __init__(self, root: Optional[TreeNode]):
        self.stack = []
        while root:
            self.stack.append(root)
            root = root.left

    def next(self) -> int:
        node = self.stack.pop()
        x = node.right
        while x:
            self.stack.append(x)
            x = x.left
        return node.val
        

    def hasNext(self) -> bool:
        return len(self.stack) > 0


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
