'''
Given the root of a binary tree, determine if it is a complete binary tree.

In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. 
It can have between 1 and 2h nodes inclusive at the last level h.

 

Example 1:


Input: root = [1,2,3,4,5,6]
Output: true
Explanation: Every level before the last is full 
(ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.

Constraints:

The number of nodes in the tree is in the range [1, 100].
1 <= Node.val <= 1000
'''

'''
Wording:-
Do a level order traversal [ basically BFS]
Even if there in one empty node before we reach the last node or the leaf node,
then it is not a complete binary tree
Else it is a complete binary tree
'''
'''
Complexity:-
TC:- O(n)
SC:- O(N)
where N is the number of nodes[or left compact tree]
'''
class Solution:
    def isCompleteTree(self, root: Optional[TreeNode]) -> bool:
        traversal_queue = deque( [ root ] )
        prev_node = root
        
        
        # Launch Level-order traversal
        
        while traversal_queue:
            
            cur_node = traversal_queue.popleft()
            
            if cur_node:
                
                if not prev_node:
                    # Empty node in the middle means this is not a complete binary tree ( not left-compact)
                    return False
                
                traversal_queue.append( cur_node.left )
                traversal_queue.append( cur_node.right )
            
            # update previous node
            prev_node = cur_node
            
        return True
