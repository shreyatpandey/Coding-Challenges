'''
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.
'''
'''
Constraints:
k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 10^4.
'''
'''
Approach:- Merge With Divide and Conquer
TC:- O(NLogK)
SC:- O(1)
'''
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if not lists:
            return None
        if len(lists) == 1:
            return lists[0]
        mid = len(lists) // 2
        l, r = self.mergeKLists(lists[:mid]), self.mergeKLists(lists[mid:])
        return self.merge(l, r)
    
    def merge(self, l, r):
        dummy = p = ListNode()
        while l and r:
            if l.val < r.val:
                p.next = l
                l = l.next
            else:
                p.next = r
                r = r.next
            p = p.next
        p.next = l or r
        return dummy.next
'''
Intuition & Algorithm

This approach walks alongside the one above but is improved a lot.
We don't need to traverse most nodes many times repeatedly

Pair up k lists and merge each pair.

After the first pairing, k lists are merged into k/2 lists with average 2N/k length, then k/4, k/8 and so on.

Repeat this procedure until we get the final sorted linked list.

'''
'''
Approach-2:- 
TC:- O(NkLog(k))
Sc:- O(1)
'''
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        amount = len(lists)
        interval = 1
        while interval < amount:
            for i in range(0, amount - interval, interval * 2):
                lists[i] = self.merge2Lists(lists[i], lists[i + interval])
            interval *= 2
        return lists[0] if amount > 0 else None

    def merge2Lists(self, l1, l2): #give directly this solution for Merge two sorted List
        head = point = ListNode(0)
        while l1 and l2:
            if l1.val <= l2.val:
                point.next = l1
                l1 = l1.next
            else:
                point.next = l2
                l2 = l1
                l1 = point.next.next
            point = point.next
        if not l1:
            point.next=l2
        else:
            point.next=l1
        return head.next
'''
Approach-3:- Priority Queue
TC:- O(n*log(k))
where k is the number of linked list and n is the number of nodes in the linked list
SC:- O(n)
'''
def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
	heap, res = [], ListNode()
	for i, list in enumerate(lists):
		if list: 
			heappush(heap, (list.val, i, list))

	cur = res
	while heap:
		_, i, list = heappop(heap)
		if list.next:
			heappush(heap, (list.next.val, i, list.next))

		cur.next, cur = list, list

	return res.next
