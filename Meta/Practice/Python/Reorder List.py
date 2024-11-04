'''
ou are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.
'''

'''
Constraints :
The number of nodes in the list is in the range [1, 5 * 104].
1 <= Node.val <= 1000
'''

'''
Input: head = [1,2,3,4]
Output: [1,4,2,3]
'''
'''
Complexity :
N = Number of nodes in LL
TC : O(N)
SC : O(1)
'''
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        slow = head
        fast = head
        while fast and fast.next != None:
            slow = slow.next
            fast = fast.next.next
        
        first = head
        secondhalf = slow.next
        slow.next = None
        secondhalf = self.reverseLinkList(secondhalf)
        dummyNode = ListNode(-1)
        temp = dummyNode
        
        while first or secondhalf:
            if first :
                temp.next = first
                first = first.next
                temp = temp.next
            if secondhalf:
                temp.next = secondhalf
                secondhalf = secondhalf.next
                temp = temp.next

        return dummyNode.next
    
    def reverseLinkList(self,head):
        current = head
        prev = None
        temp = None
        while current != None :
            temp = current.next
            current.next = prev
            prev = current
            current = temp
        head = prev
        return head