'''
You are given a doubly linked list, which contains nodes that have a next pointer, a previous pointer, 
and an additional child pointer. 
This child pointer may or may not point to a separate doubly linked list, also containing these special nodes. 
These child lists may have one or more children of their own, and so on, 
to produce a multilevel data structure as shown in the example below.

Given the head of the first level of the list, flatten the list so that all the nodes appear in a single-level, doubly linked list. 
Let curr be a node with a child list. 
The nodes in the child list should appear after curr and before curr.next in the flattened list.

Return the head of the flattened list. The nodes in the list must have all of their child pointers set to null.
'''

'''
Recursive:
'''
class Solution:
    def flatten(self, head: 'Node') -> 'Node':
        if not head: return None
        def travel(node):
            while node:
                q = node.next
                if not q: tail = node
                if node.child:
                    node.next = node.child
                    node.child.prev = node
                    t = travel(node.child)
                    if q:
                        q.prev = t
                    t.next= q
                    node.child = None
                node = node.next
            return tail
        travel(head)
        return head

'''
DFS with stack
'''
class Solution:
    def flatten(self, head: 'Node') -> 'Node':
        if not head: return None
        stack = [head]; p = None
        while stack:
            r = stack.pop()
            if p:
                p.next,r.prev = r,p
            p = r
            if r.next:
                stack.append(r.next)
            if r.child:
                stack.append(r.child)
                r.child = None
        return head
