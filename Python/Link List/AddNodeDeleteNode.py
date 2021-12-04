class Node(object):
    def __init__(self,val):
        self.val = val
        self.next = None

class LinkList(object):
    def __init__(self): # this is very important
        self.head = None
    
    def AppendNode(self,val): #return type is Node
        newNode = Node(val)
        if self.head == None:
            self.head = newNode
            return 
        last = self.head 
        while last.next != None:
            last = last.next
        last.next = newNode
        return 
    
    def RemoveNode(self,index):
        if (index == 0):
            deleteNode = self.head.next
            self.head = deleteNode
            deleteNode = None
        else:
            current = self.head
            for i in range(0,index-1):
                if current.next != None:
                    current = current.next;
            if current != None and current.next != None:
                deleteNode = current.next
                current.next = deleteNode.next
                deleteNode = None
            return 
        
    def Print(self): #return type is void
        current = self.head
        while current != None:
            print(current.val)
            current = current.next
        return
if __name__ == '__main__':
    linkList = LinkList()
    print("|---|Test Case-1|---|")
    linkList.AppendNode(5)
    linkList.AppendNode(6)
    linkList.AppendNode(7)
    linkList.AppendNode(8)
    linkList.Print()
    print("|---|Test Case-2|---|")
    linkList.RemoveNode(0)
    linkList.Print()
    print("|---|Test Case-3|---|")
    linkList.RemoveNode(2)
    linkList.Print()
