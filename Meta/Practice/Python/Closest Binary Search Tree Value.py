'''
Given the root of a binary search tree and a target value, 
return the value in the BST that is closest to the target. If there are multiple answers, print the smallest.

Input: root = [4,2,5,1,3], target = 3.714286
Output: 4
'''
'''
Constraints:-
The number of nodes in the tree is in the range [1, 104].
0 <= Node.val <= 10^9
-10^9 <= target <= 10^9
'''
'''
Approach:- Binary Search
Generally TC & SC for a BST = O(height of tree)


Average Case:
TC: O(logN) ; SC: O(logN)

Worst Case(skewed tree i.e. all nodes in one line):
TC: O(N); SC: O(N)

TC:- O(H) //final
SC:- O(1) //final

Advantages of Below Solution:-
1. In the case of relatively large k, comparable with N.
2. Below solution would take care :- For [4,2,5,1,3] and target 4.5 it returns 5, but should return 4
    a. The above test case fails in the official solution of Leetcode
'''
class Solution:
    def closestValue(self, root: Optional[TreeNode], target: float) -> int:
        min_val = root.val
        while root:
            if abs(root.val-target) < abs(min_val - target):
                min_val = root.val
            elif abs(root.val-target) == abs(min_val - target):
                min_val = min(min_val, root.val)
            if root.val < target:
                root = root.right
            else:
                root = root.left
        return min_val

'''
Approach:- Iterative
TC:- O(H+k) is the worst case where H is the height of the tree
O(k) is the average case is the balanced tree
It's known that average case is a balanced tree,
in that case stack always contains a few elements, and hence
one does 2k operations to go to kth element in
inorder traversal (k times to push into stack and
then k times to pop out of stack).
SC:- O(H)
It is used to keep the stack in case of non-balanced tree
'''
class Solution:
    def closestValue(self, root: TreeNode, target: float) -> int:
        stack, pred = [], float('-inf')   
        while stack or root:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            
            if pred <= target and target < root.val:
                return min(pred, root.val, key = lambda x: abs(target - x))
                
            pred = root.val
            root = root.right

        return pred
        
        




