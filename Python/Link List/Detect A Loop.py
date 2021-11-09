class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        '''
        Got stuck in testcase:-
        input: [1] , pos = -1
        output: false
        '''
        if head == None or head.next == None :
            return False
        slow = head
        fast = head.next
        while slow != fast: # this condition itself will fail as slow == fast
            if fast == None or fast.next == None:
                return False
            slow = slow.next
            fast = fast.next.next
        return True
