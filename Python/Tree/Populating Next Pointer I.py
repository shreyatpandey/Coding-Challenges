'''
Populating Next Right Pointer:-
O(1) <-> Constant Space
there is next pointer in the node
It can be divided into two conditions:-
(1) Establishing next connection with same common parent
(2) Establishing next connection with different parent
    right child of the left node with left child of the right node of different parent

leftmost = root.left
#why are we starting with left node?
while leftmost:
    At each level, visualize this like a link-list
    node = leftmost
    while node:
        above two conditions
        (1) Establishing next connection with same common parent
        (2) Establishing next connection with different parent
            right child of the left node with left child of the right node of different parent
        node = node.next
    leftmost = leftmost.left
return root
'''
