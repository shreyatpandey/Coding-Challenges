'''
Given a Circular Linked List node, which is sorted in ascending order, write a function to insert a value insertVal into the list 
such that it remains a sorted circular list.
The given node can be a reference to any single node in the list and 
may not necessarily be the smallest value in the circular list.

If there are multiple suitable places for insertion, you may choose any place to insert the new value. 
After the insertion, the circular list should remain sorted.

If the list is empty (i.e., the given node is null), you should create a new single circular list and return the reference to that single node. 
Otherwise, you should return the originally given node.
'''
'''
Wording:-
Key-Word - Two pointer iteration with something like previous and current
How to traverse the circular link list?
Couple of Approach:-
    a.Slow and Fast Pointer
    b. Two pointer iteration
Take Couple of Case 
Let input circular link list = [1,4,3] 
First insertval = 2
Second insertval = 0

'''
'''
TC:- O(N)
SC:- O(1)
'''
class Solution:
    def insert(self, head: 'Node', insertVal: int) -> 'Node':
        node = Node(insertVal)  
        
        if not head:
            node.next = node
            return node

        prev, curr = head, head.next
        
        while prev.next != head:
            # Case1: 1 <- Node(2) <- 3
            if prev.val <= node.val <= curr.val:
                break
            
            # Case2: 3 -> 1, 3 -> Node(4) -> 1, 3 -> Node(0) -> 1
            if prev.val > curr.val and (node.val > prev.val or node.val < curr.val):
                break
            
            prev, curr = prev.next, curr.next

        # Insert node.
        #Where we cannot insert node in the loop
        node.next = curr
        prev.next = node           
        
        return head
