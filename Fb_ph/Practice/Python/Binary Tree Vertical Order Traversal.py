'''
TC:- O(N)
where N is the number of nodes
There is no need of sorting here
SC:- O(N)
where N is the number of node

Main Point:- We only need to know the range of the column index = [minColumn,maxColumn]
this range can be used to generate the outpus without the need of sorting
'''
from collections import defaultdict
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
        
