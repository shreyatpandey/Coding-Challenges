'''
Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

Constraints:

The number of nodes in the tree will be in the range [0, 104].
-231 <= Node.val <= 231 - 1
'''
'''
Approach:- BFS
TC:- O(n)
SC:- O(n)
where n is the number of nodes

'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        Result = []
        if not root:
            return Result
        Queue = deque([root])
        while Queue:
            lenQueue = len(Queue)
            loopVal = []
            for i in range(lenQueue):
                Node = Queue.popleft()
                loopVal.append(Node.val)
                if Node.left:
                    Queue.append(Node.left)
                if Node.right:
                    Queue.append(Node.right)
                    
        
            Result.append(max(loopVal))
        return Result
        
