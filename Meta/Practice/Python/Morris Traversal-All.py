
'''
Morris Inorder
Tc:- O(n)
Sc:- O(1)
'''
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        Result = []
        current = root
        while current:
            if current.left:
                previous = current.left
                while previous.right and previous.right != current:
                    previous = previous.right
                if not previous.right:
                    previous.right = current
                    current = current.left
                else:
                    previous.right = None
                    Result.append(current.val)
                    current = current.right
            else:
                Result.append(current.val)
                current = current.right
        return Result

'''
Morris PreOrder traversal
Complexity
Tc:- O(n)
Sc:- O(1)
'''
'''
Morris solution notes:

We can safely comment out one line of code without breaking the algorithm:
else:
#     last.right = None
       curr = curr.right
Hints for understanding how it works.
2a) If a node, call it A, does not have a left child node, we simply add A's value to the resulting array, and move on to the right node.
2b) If a node, call it A, does have a left child node, we will mark it as curr twice. The first time, A's last has been found, A's value is recorded, 
and last.
right has been set to A. 
The second time, we mark it as curr because we have marked A's last as 'curr', recorded it, and set curr to curr.right, which is A. 
Now we have the scenario where last.right is not None because last.right is curr, addressed by this code,
             else:
                    last.right = None
                    curr = curr.right
where we find A's last again, but this time, last.right is curr, so we know it is the second time we have set A as curr. 
Therefore, we know we have recorded all values of A and its left subtree, so we can now move to A's right child without recording anything.
'''
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        answer = []
        curr = root
        
        while curr:
            # If there is no left child, go for the right child.
            # Otherwise, find the last node in the left subtree. 
            if not curr.left:
                answer.append(curr.val)
                curr = curr.right
            else:
                last = curr.left
                while last.right and last.right != curr:
                    last = last.right
                    
                # If the last node is not modified, we let 
                # 'curr' be its right child. Otherwise, it means we 
                # have finished visiting the entire left subtree.
                if not last.right:
                    answer.append(curr.val)
                    last.right = curr
                    curr = curr.left
                else:
                    last.right = None
                    curr = curr.right
        
        return answer

'''
Morris PostOrder
Complexity:-
Tc:- O(n)
where n is the number of nodes
Sc:- O(1)
'''
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        def reverse(start,end):
            if start == end:
                return
            previous,node= start, start.right
            while previous != end:
                next = node.right
                node.right = previous
                previous = node
                node = next
        
        
        Result = []
        if not root:
            return Result
        dummy = TreeNode(-1)
        previous = None
        dummy.left = root
        root = dummy
        while root :
            if root.left:
                previous = root.left
                while previous.right != None and previous.right != root:
                    previous = previous.right
                if previous.right == None:
                    previous.right = root
                    root = root.left
                else:
                    node = previous
                    reverse(root.left,previous)
                    while node != root.left:
                        Result.append(node.val)
                        node = node.right
                    Result.append(node.val)
                    reverse(previous,root.left)
                    previous.right = None
                    root = root.right
            else:
                root = root.right
        return Result
        
