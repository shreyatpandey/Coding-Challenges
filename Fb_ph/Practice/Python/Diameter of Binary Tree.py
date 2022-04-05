'''
Given the root of a binary tree, return the length of the diameter of the tree

'''
'''
TC:- O(N)
SC:- O(N) 
Because of the implicit call to out stack.
If the tree is balanced, it did be O(log(N))
'''
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        result = [0]
        def dfs(root):
            if not root:
                return -1 #why -1, the height of the null root is -1
            left = dfs(root.left)
            right = dfs(root.right)
            result[0] = max(result[0],2+left+right) #why 2? because there is always an edge from the node
            
            return 1 + max(left,right) # this is to find the height of the tree, 1 for extra edge
        dfs(root)
        return result[0]
#diameter of leaf nodes is 0
#height of null root is -1
#we dont only want the diameter of the node rather height of the node as well
#we will return the height of the tree
#Why O(N) , visit the node only once
# max running through the left substree
