'''
Given an integer n, return all the structurally unique BST's (binary search trees), 
which has exactly n nodes of unique values from 1 to n. Return the answer in any order.
'''
'''
Approach Recursion:-
The recursive approach involves the following steps:
Base Case: If the start index is greater than the end index, return a list containing None. 
This represents an empty tree and serves as the base case for the recursion.
Choose Root: For every number ( i ) in the range from start to end, consider ( i ) as the root of the tree.

Generate Left Subtrees: Recursively call the function to generate all possible left subtrees using numbers from start to ( i-1 ). 
This forms the left child of the root.

Generate Right Subtrees: Recursively call the function to generate all possible right subtrees using numbers from ( i+1 ) to end. 
This forms the right child of the root.

Combine Subtrees: For each combination of left and right subtrees, 
create a new tree with ( i ) as the root and the corresponding left and right subtrees. 
Append this tree to the list of all possible trees.
Return Trees: Finally, return the list of all trees generated.
'''
'''
Complexity:-
TC:- O(4^n/n*sqrt(n))
SC:- O(4^n/n*sqrt(n))
'''
class Solution:
    def generateTrees(self, n: int):
        def generate_trees(start, end):
            if start > end:
                return [None,]
            
            all_trees = []
            for i in range(start, end + 1):
                left_trees = generate_trees(start, i - 1)
                right_trees = generate_trees(i + 1, end)
                
                for l in left_trees:
                    for r in right_trees:
                        current_tree = TreeNode(i)
                        current_tree.left = l
                        current_tree.right = r
                        all_trees.append(current_tree)
            
            return all_trees
