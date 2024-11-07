'''
Let n be the number of nodes
Complexity
TC :- O(n)
SC :- O(n) for stack
'''
def bToDLL(root):
    s = []
    s.append([root, 0])
    res = []
    flag = True
    head = None
    prev = None
    while len(s) > 0:
        x = s.pop()
        t = x[0]
        state = x[1]
        if state == 3 or t == None: continue
        s.append([t, state+1])
        if state == 0: s.append([t.left, 0])
        elif state == 1: 
            if prev != None: prev.right = t
            t.left = prev 
            prev = t 

            if flag:  
                head = t 
                flag = False  

        elif state == 2: s.append([t.right, 0])

    return head

'''
Approach :- 2
Morris Traversal
TC :- O(n)
Sc :- O(1)
'''
class Node: 
    def __init__(self, val): 
        self.right = None
        self.data = val 
        self.left = None
        
def bToDLL(root):
        # do Code here
        curr = root
        prev = None #Used to keep track of prev node
        final_head = None #used to return the final head
        while curr:
            if not curr.left:
                if not final_head:
                    prev = curr
                    final_head = curr
                else:
                      #set next of prev as curr and prev of curr as prev
                    prev.right = curr
                    curr.left = prev
                #set the new prev node
                prev = curr
                curr = curr.right
            else:
                pre = curr.left
                while pre.right and pre.right != curr:
                    pre = pre.right
                if not pre.right:
                    pre.right = curr
                    curr = curr.left
                else:
                    curr = pre.right
                    #set next of prev as curr and prev of curr as prev
                    prev.right = curr
                    curr.left = prev
                    #set the new prev node
                    prev = curr
                    curr = curr.right
                    
        return final_head

def print_dll(head): 
      
    # Function to print nodes in given 
    # doubly linked list 
    while head is not None: 
        print(head.data, end=" ") 
        head = head.right 
# Driver program to test above functions 
# Let us create the tree as 
# shown in above diagram 
if __name__ == '__main__': 
    root = Node(10) 
    root.left = Node(12) 
    root.right = Node(15) 
    root.left.left = Node(25) 
    root.left.right = Node(30) 
    root.right.left = Node(36) 
      
    head = bToDLL(root) 
      
    # Print the converted list 
    print_dll(head) 