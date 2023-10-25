'''
Complexity
Tc:- O(n)
Sc-:- O(1)
'''
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummyNode = ListNode(-1)
        pairNode = 2
        dummyNode.next = head
        previous = dummyNode
        nextPtr= current = dummyNode
        length = self.lengthofLinkList(head)
        
        while(length>=pairNode):
            current = previous.next
            nextPtr = current.next
            for i in range(1,pairNode):
                current.next = nextPtr.next
                nextPtr.next = previous.next
                previous.next = nextPtr
                nextPtr = current.next
            previous = current
            length -= pairNode
        
        return dummyNode.next
    
    def lengthofLinkList(self,head):
        current = head
        length = 0
        while current != None:
            length += 1
            current = current.next
        return length

'''
Reverse Nodes in k-groups
'''
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head or k == 1:
            return head
        
        dummyNode = ListNode(-1)
        dummyNode.next = head
        previous = dummyNode
        nextPtr= current = dummyNode
        length = self.lengthofLinkList(head)
        
        while(length>=k):
            current = previous.next
            nextPtr = current.next
            for i in range(1,k):
                current.next = nextPtr.next
                nextPtr.next = previous.next
                previous.next = nextPtr
                nextPtr = current.next
            previous = current
            length -= k
        
        return dummyNode.next
    
    def lengthofLinkList(self,head):
        current = head
        length = 0
        while current != None:
            length += 1
            current = current.next
        return length
        
