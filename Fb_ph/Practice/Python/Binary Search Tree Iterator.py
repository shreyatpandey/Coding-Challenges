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
