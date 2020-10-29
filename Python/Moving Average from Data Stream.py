class MovingAverage:
    
    def __init__(self, size: int):
        """
        Initialize your data structure here.
        """
        self.list = []
        self.length = 0
        self.size = size
        

    def next(self, val: int) -> float:
        if len(self.list) < self.size :
            self.list.append(val)
            self.length += 1
            return (sum(self.list) / self.length)
        else:
            del self.list[0]
            self.list.append(val)
            return (sum(self.list) / self.length)
            
        


# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param_1 = obj.next(val)
