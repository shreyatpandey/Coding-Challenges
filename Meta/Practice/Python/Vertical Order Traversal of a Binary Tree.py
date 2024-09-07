'''
Question:-
Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. 
The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. 
There may be multiple nodes in the same row and same column.
***In such a case, sort these nodes by their values.***
This makes all the difference

Return the vertical order traversal of the binary tree.

'''
'''
Only difference between this question and Binary Tree Vertical Order Traversal is that:-
In Binary Tree Vertical Order Traversal we dont need to sort the array

'''


'''
TC:- O(Nlog(N/k)) where k is the width of the tree
Partition Sorting
In the first step , it takes O(N) TC for both BFS and DFS traversal
In the second step, we need to sort hashmap 
TC of sorting k equal-sized subgroups with total N elements would be :- O(k.N/k.log(N/k)) = O(N.log(N/k))

SC:- O(N)

'''

class Solution:
    def verticalTraversal(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None:
            return []

        columnTable = defaultdict(list)
        min_column = max_column = 0

        def BFS(root):
            nonlocal min_column, max_column
            queue = deque([(root, 0, 0)])

            while queue:
                node, row, column = queue.popleft()

                if node is not None:
                    columnTable[column].append((row, node.val))
                    min_column = min(min_column, column)
                    max_column = max(max_column, column)

                    queue.append((node.left, row + 1, column - 1))
                    queue.append((node.right, row + 1, column + 1))

        # step 1). BFS traversal
        BFS(root)
         # step 2). extract the values from the columnTable
        ret = []
        for col in range(min_column, max_column + 1):
            # sort first by 'row', then by 'value', in ascending order
            ret.append([val for row, val in sorted(columnTable[col])])

        return ret
