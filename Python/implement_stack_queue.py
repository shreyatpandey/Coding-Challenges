
class Stack(object):
    def init(self):
        self.queue1= []
        self.top = 0
    
    def push(self,x):
        self.queue1.insert(0,x) #fill up position from first
        self.top = x
        print("queue:",self.queue1)
        for i in range(0,len(self.queue1)-1):
            self.queue1.insert(0,self.queue1[-1])
            self.queue1.pop()
        print("Now_queue:",self.queue1)
            
    
    def pop(self):
        return(self.queue1.pop())
        
    def top(self):
        return(self.queue1[-1])
        
    def empty(self):
        if not self.queue1:
            return False
        else:
            return True
    
obj = Stack()
obj.init()
obj.push(5)
obj.push(10)
obj.push(15)
obj.pop()