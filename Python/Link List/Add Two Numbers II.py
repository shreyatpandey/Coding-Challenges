# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        def LenLink(self,root):
            Len = 0
            while root:
                root = root.next
                Len += 1
            return Len
        len1,len2 = LenLink(self,l1), LenLink(self,l2)
        maxlen = max(len1,len2)
        dummy = ListNode(0)
        prevnine = None
        current = dummy
        Result = None
        for i in range(0,maxlen):
            currentval = 0
            if maxlen-i<=len1:
                currentval += l1.val
                l1 = l1.next
            if maxlen-i <=len2:
                currentval += l2.val
                l2 = l2.next
            if currentval>9:
                while ( prevnine != None and prevnine != current):
                    prevnine.val = ( prevnine.val + 1 ) % 10
                    prevnine = prevnine.next
                current.val = (current.val + 1)% 10
                prevnine = current if currentval==9 else None
            
            if currentval %10 == 9:
                prevnine = prevnine if prevnine else current
            else:
                prevnine = None
            
            current.next = ListNode(currentval%10)  
            current = current.next
      
        if dummy.val != 0 :
            Result = ListNode(dummy.val)
            Result.next = dummy.next
        else :
            Result = dummy.next
        
        return Result
