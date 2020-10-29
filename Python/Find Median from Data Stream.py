'''
Sorting-Approach
Time Complexity: O(nlogn)
Time Limit Exceeded
'''
class MedianFinder(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.list_median = []

    def addNum(self, num):
        """
        :type num: int
        :rtype: None
        """
        self.list_median.append(num)

    def findMedian(self):
        """
        :rtype: float
        """
        self.list_median.sort()
        length = len(self.list_median)
        if length %2 == 0:
            return ((self.list_median[length//2] + self.list_median[length//2-1])/2.0)
        else:
            return self.list_median[length//2]
        
'''
Heap Approach
'''
from heapq import *
class MedianFinder(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.heaps = None, [], []
        self.i = 1

    def addNum(self, num):
        """
        :type num: int
        :rtype: None
        """
        heappush(self.heaps[-self.i], -heappushpop(self.heaps[self.i], num * self.i))
        self.i *= -1
        

    def findMedian(self):
        """
        :rtype: float
        """
        return (self.heaps[self.i][0] * self.i - self.heaps[-1][0]) / 2.0
        
