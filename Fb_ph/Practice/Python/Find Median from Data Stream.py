'''
The median is the middle value in an ordered integer list. 
If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
'''
'''
Constraints:
-10^5 <= num <= 10^5
There will be at least one element in the data structure before calling findMedian.
At most 5 * 10^4 calls will be made to addNum and findMedian.
'''
 
'''
Follow up:
If all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
If 99% of all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
'''
'''
Complexity
Time:
Constructor: O(1)
addNum: O(logN)
findMedian: O(1)
Space: O(N)
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
