class Node(object):
    def __init__(self,val):
        self.Value = val
        self.next = None
        self.TripleNext = None
    
class List(object):
    def __init__(self):
        self.head = None
    
    def lenLinkList(self,head):
        length = 0
        while head != None:
            head = head.next
            length += 1
        return length
    
    def Prepend(self,val):
        newNode = Node(val)
        if self.head == None:
            self.head = newNode
            return
        
        newNode.next = self.head
        self.head = newNode
        lengthNow = self.lenLinkList(self.head)
        if lengthNow < 4:
            self.head.TripleNext = None
        else:
            j = 0;
            current = self.head
            while j<3 and current.next != None:  # no need of 4 as we have to loop till 3
                current = current.next
                j += 1
            self.head.TripleNext = current
    
    def RemoveNode(self,index):
        if index == 0:
            deleteNode = self.head.next
            self.head = deleteNode
            deleteNode = None
            return ;
        else:
            current = self.head
            for i in range(0,index-1):
                if current != None:
                    current.TripleNext = current.next.TripleNext
                    current = current.next
            
            if current!= None and current.next != None:
                deleteNode = current.next
                current.next = deleteNode.next
                current.TripleNext = deleteNode.TripleNext
                deleteNode = None
                
        
    
    def Print(self):
        current = self.head
        while current != None:
            print("current.val:",current.Value)
            if current.TripleNext != None:
                print("TripleNext Val:",current.TripleNext.Value)
            current = current.next
        
    if __name__ == '__main__':
      listNode = List()
      print("|----|Test Case-1|----|")
      listNode.Prepend(4)
      listNode.Prepend(5)
      listNode.Prepend(6)
      listNode.Prepend(7)
      listNode.Prepend(8)
      listNode.Prepend(9)
      listNode.Print()

      print("|----|Test Case-2|----|")
      listNode.RemoveNode(3)
      listNode.Print()
