'''
Given an integer n, return a list of all possible full binary trees with n nodes. 
Each node of each tree in the answer must have Node.val == 0.
Each element of the answer is the root node of one possible tree. 
You may return the final list of trees in any order.
A full binary tree is a binary tree where each node has exactly 0 or 2 children.
'''
'''
Input: n = 7
Output: [[0,0,0,null,null,0,0,null,null,0,0],
[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
Example 2:
Input: n = 3
Output: [[0,0,0]]
'''
'''
Complexity:-
TC:- O(2^n)
SC:- O(n)
'''
'''
Approach
Initialize a hash table to store the generated trees.
If n is even, return an empty list.
If n is 1, add a new tree to the hash table.
For i from 1 to n - 1, do:
Generate all possible full binary trees with i nodes.
Generate all possible full binary trees with n - i - 1 nodes.
For each pair of trees, create a new tree with the first tree as the left subtree and the second tree as the right subtree.
Add the new tree to the hash table.
Return the list of trees in the hash table
'''
class Solution:
    def allPossibleFBT(self, n: int) -> List[Optional[TreeNode]]:
        if n % 2 == 0:
            return []

        memo = {}

        def _allPossibleFBT(n):
            if n in memo:
                return memo[n]

            list = []
            if n == 1:
                list.append(TreeNode(0))
            else:
                for i in range(1, n - 1, 2):
                    lTrees = _allPossibleFBT(i)
                    rTrees = _allPossibleFBT(n - i - 1)

                    for lt in lTrees:
                        for rt in rTrees:
                            list.append(TreeNode(0, lt, rt))

            memo[n] = list
            return list

        return _allPossibleFBT(n)
        

