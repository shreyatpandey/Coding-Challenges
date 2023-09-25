'''
Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.
Return the smallest level x such that the sum of all the values of nodes at level x is maximal.
'''
'''
Input: root = [1,7,0,7,-8,null,null]
Output: 2
Explanation: 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.
'''
'''
Constraints:
The number of nodes in the tree is in the range [1, 104].
-10^5 <= Node.val <= 10^5
'''

'''
Use BFS to find the sum of each level, then locate the level with largest sum.
Perform level order traversal, keep track of the sum ar each level,
If the current sum of node valus is greater than what we've seen before,
we update our answer to level, and the current sum becomes out largest sum of values seen so far
'''

'''
Approach:- BFS
TC:- O(n) where n is the number of nodes
SC:- O(n) where n is the number of nodes
'''
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        max, level, maxLevel = -float('inf'), 0, 0
        q = collections.deque()
        q.append(root)
        while q:
            level += 1
            sum = 0
            for _ in range(len(q)):
                node = q.popleft()
                sum += node.val
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            if max < sum:
                max, maxLevel = sum, level        
        return maxLevel

'''
Use DFS to compute and store the sum of each level in an ArrayList, then locate the level with largest sum.
Recurse down from root, level of which is 0, increase level by 1 for each recursion down;
Use the level as the index of an ArrayList to store the sum of the correspoinding level;
Find the index of the max sum, then plus 1.
'''
'''
Approach:- DFS
TC:- O(n) where n is the number of nodes
SC:- O(n) where n is the number of nodes
'''
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        def dfs(node: TreeNode, list: List, level: int) -> None:
            if not node:
                return
            if len(list) == level:
                list.append(node.val)
            else:
                list[level] += node.val
            dfs(node.left, list, level + 1)
            dfs(node.right, list, level + 1)
        list = []    
        dfs(root, list, 0)
        return 1 + list.index(max(list))
