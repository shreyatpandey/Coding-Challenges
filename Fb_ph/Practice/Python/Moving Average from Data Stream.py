'''
Approach-1: Using Deque
TC:- O(1)
SC:- O(n)
'''
from collections import deque
class MovingAverage:
    def __init__(self, size: int):
        self.size = size
        self.queue = deque()
        # number of elements seen so far
        self.window_sum = 0
        self.count = 0

    def next(self, val: int) -> float:
        self.count += 1
        # calculate the new sum by shifting the window
        self.queue.append(val)
        tail = self.queue.popleft() if self.count > self.size else 0

        self.window_sum = self.window_sum - tail + val

        return self.window_sum / min(self.size, self.count)
 
'''
Approach-2: Circular Queue
TC:- O(1)
SC:- O(n)
'''
class MovingAverage:
    def __init__(self, size: int):
        self.size = size
        self.queue = [0] * self.size
        self.head = self.window_sum = 0
        # number of elements seen so far
        self.count = 0

    def next(self, val: int) -> float:
        self.count += 1
        # calculate the new sum by shifting the window
        tail = (self.head + 1) % self.size
        self.window_sum = self.window_sum - self.queue[tail] + val
        # move on to the next head
        self.head = (self.head + 1) % self.size
        self.queue[self.head] = val
        return self.window_sum / min(self.size, self.count)
'''
My Solution
Using List/Array
TC:- O(n)
SC:- O(n)
'''
class MovingAverage:
    def __init__(self, size: int):
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
        
