'''
Apporach:- Basic Intuition
Perform Inorder Traversal of Link List
That would give a sorted array
Then merge the two array
Tc:- O((N+M)log(M+N))
where M and N are the number of nodes in two bst
Sc:- O(N+M)
'''
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        self.arr1, self.arr2 = [], []
        self.inorder(root1, self.arr1)
        self.inorder(root2, self.arr2)
        return self.merge2lists(self.arr1, self.arr2)
    
    def inorder(self, root: TreeNode, arr: List[int]):
        if root == None:
            return
        self.inorder(root.left, arr)
        arr.append(root.val)
        self.inorder(root.right, arr)
    
    def merge2lists(self, arr1: List[int], arr2: List[int]) -> List[int]:
        res = []
        i, j = 0, 0
        while i < len(arr1) and j < len(arr2):
            if arr1[i] < arr2[j]:
                res.append(arr1[i])
                i += 1
            else:
                res.append(arr2[j])
                j += 1
        if i < len(arr1):
            res += arr1[i:]
        if j < len(arr2):
            res += arr2[j:]
        return res

'''
Approach-2:- Iterative In Order
Tc:- O(N+M)
Sc:- O(n+m) for output list
'''
class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        stack1, stack2, output = [], [], []
        
        while root1 or root2 or stack1 or stack2:
            # update both stacks
            # by going left till possible
            while root1:
                stack1.append(root1)
                root1 = root1.left
            while root2:
                stack2.append(root2)
                root2 = root2.left

            # Add the smallest value into output,
            # pop it from the stack,
            # and then do one step right
            if not stack2 or stack1 and stack1[-1].val <= stack2[-1].val:
                root1 = stack1.pop()
                output.append(root1.val)
                root1 = root1.right
            else:
                root2 = stack2.pop()
                output.append(root2.val)   
                root2 = root2.right

        return output
