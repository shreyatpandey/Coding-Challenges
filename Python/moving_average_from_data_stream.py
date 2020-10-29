'''
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.
MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3
'''



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
