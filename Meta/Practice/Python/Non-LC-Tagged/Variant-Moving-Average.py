'''
write a class for RunningSumAverage
There is an infinite stream of values and you are asked to give the average of the last k values
ex: 1, 2, 5, 3, 5, 76, 24, .....
k = 3
ma = RunningSumAverage(4) # window size if 4
ma.add(1)
ma.add(3)
ma.add(2)
ma.add(5)
ma.avg() # returns 11/4 = 2
ma.add(8)
ma.avg() # returns 17/4 = 4
'''
'''
Approach :- Deque
TC :- O(1)
SC :- O(n) for deque
'''
from collections import deque
class RunningSumAverage:
    def __init__(self, size: int):
        self.size = size
        self.queue = deque()
        # number of elements seen so far
        self.window_sum = 0
        self.count = 0

    def add(self, val: int) -> float:
        self.count += 1
        # calculate the new sum by shifting the window
        self.queue.append(val)
        tail = self.queue.popleft() if self.count > self.size else 0

        self.window_sum = self.window_sum - tail + val

    def avg(self):
        return self.window_sum // min(self.size, self.count)
    # /-> float in python , // int


'''
Approach-2: Circular Queue
TC:- O(1)
SC:- O(n)
'''
class RunningSumAverage:
    def __init__(self, size: int):
        self.size = size
        self.queue = [0] * self.size
        self.head = self.window_sum = 0
        # number of elements seen so far
        self.count = 0

    def add(self, val: int) -> float:
        self.count += 1
        # calculate the new sum by shifting the window
        tail = (self.head + 1) % self.size
        self.window_sum = self.window_sum - self.queue[tail] + val
        # move on to the next head
        self.head = (self.head + 1) % self.size
        self.queue[self.head] = val
    
    def avg(self):
        return self.window_sum // min(self.size, self.count)

'''
if __name__ == '__main__':
    ma = RunningSumAverage(4)
    ma.add(1)
    ma.add(3)
    ma.add(2)
    ma.add(5)
    print("Avg : ", ma.avg())

    ma.add(8)
    print("Avg : ", ma.avg())
'''