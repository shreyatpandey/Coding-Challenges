'''
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
'''
'''
TC:- O(max(len(l1),len(l2))
SC:- O(max(len(l1),len(l2)+1)

'''
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if l1 == None :
            return l2
        elif l2 == None:
            return l1
        carry = 0
        sumDigits = 0
        dummyNode = ListNode(0)
        current = dummyNode
        while l1 or l2 :       
            x,y = 0,0
            if l1:
                x =  l1.val
                l1 = l1.next
            if l2:
                y = l2.val
                l2 = l2.next
            sumDigits = x + y + carry
            carry = sumDigits/10
            current.next = ListNode(sumDigits%10)
            current = current.next
        if carry : #testcase:- [9,9,9,9,9,9,9] , [9,9,9,9]
            current.next = ListNode(carry)
            #current = current.next
        return dummyNode.next
