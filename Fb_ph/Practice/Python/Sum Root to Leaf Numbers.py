'''
Approach-1:- Preorder Iterative Traversal
TC:- O(N)
SC:- O(H) for Queue
'''
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        deque, res = collections.deque(), 0
        if root:
            deque.append(root)
        while deque:
            node = deque.popleft()
            if not node.left and not node.right:
                res += node.val
            if node.left:
                node.left.val += node.val*10
                deque.append(node.left)
            if node.right:
                node.right.val += node.val*10
                deque.append(node.right)
        return res
  '''
  Approach:- Morrison Preorder Traversal
  TC:- O(N)
  SC:- O(1)
  '''
  class Solution:
    def sumNumbers(self, root: TreeNode):
        root_to_leaf = curr_number = 0
        
        while root:  
            # If there is a left child,
            # then compute the predecessor.
            # If there is no link predecessor.right = root --> set it.
            # If there is a link predecessor.right = root --> break it.
            if root.left: 
                # Predecessor node is one step to the left 
                # and then to the right till you can.
                predecessor = root.left 
                steps = 1
                while predecessor.right and predecessor.right is not root: 
                    predecessor = predecessor.right 
                    steps += 1

                # Set link predecessor.right = root
                # and go to explore the left subtree
                if predecessor.right is None:
                    curr_number = curr_number * 10 + root.val                    
                    predecessor.right = root  
                    root = root.left  
                # Break the link predecessor.right = root
                # Once the link is broken, 
                # it's time to change subtree and go to the right
                else:
                    # If you're on the leaf, update the sum
                    if predecessor.left is None:
                        root_to_leaf += curr_number
                    # This part of tree is explored, backtrack
                    for _ in range(steps):
                        curr_number //= 10
                    predecessor.right = None
                    root = root.right 
                    
            # If there is no left child
            # then just go right.        
            else: 
                curr_number = curr_number * 10 + root.val
                # if you're on the leaf, update the sum
                if root.right is None:
                    root_to_leaf += curr_number
                root = root.right
                        
        return root_to_leaf
