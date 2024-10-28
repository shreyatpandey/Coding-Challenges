'''
Given the root of a binary tree, return the vertical order traversal of its nodes' values. 
(i.e., from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.
'''
'''
Constraints:-
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
'''

'''
Input:- 
Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
'''
'''
TC:- O(N)
where N is the number of nodes
There is no need of sorting here
SC:- O(N)
where N is the number of node

Main Point:- We only need to know the range of the column index = [minColumn,maxColumn]
this range can be used to generate the outpus without the need of sorting
'''
'''
Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
'''
from collections import defaultdict
from collections import deque
class Solution:
    def verticalOrder(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return []

        columnTable = defaultdict(list)
        min_column = max_column = 0
        queue = deque([(root, 0)])

        while queue:
            node, column = queue.popleft()

            if node is not None:
                columnTable[column].append(node.val)
                min_column = min(min_column, column)
                max_column = max(max_column, column)

                queue.append((node.left, column - 1))
                queue.append((node.right, column + 1))
        Output = []
        for i in range(min_column,max_column+1):
            Output.append(columnTable[i])
        return Output
# Output for one of the above test-case
'''
('min_column, max_column', 0, 0)
('min_column, max_column', -1, 0)
('min_column, max_column', -1, 1)
('min_column, max_column', -1, 1)
('min_column, max_column', -1, 2)
'''
        
