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
Ans:-
Create 101 buckets using an array of size 101.
Store the numbers into these buckets.
Find median by looping through this array.
Time Complexity
addNum() is O(1)
findMedian() is O(1) since array has fixed size.
Space Complexity: O(1) since array has fixed size.

If 99% of all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
Ans:-
Divide problem into 3 subproblems. Here are the groupings:
Numbers < 0: You have 2 options: 
1. Use 2-heap solution (that we coded in original solution), 
or 1. Use 1 array, which represents 1 bucket

0 <= Numbers <= 100: Use 100 buckets using an array of size 100

100 < Numbers: You have 2 options: 
1. Use 2-heap solution (that we coded in original solution), or 1. 
Use 1 array, which represents 1 bucket
For each number we get in the stream, insert it into 1 of the 3 groupings,
keeping track of the count of numbers in each of these 3 groupings
To find the median, see which grouping the median must fall into and find it there.

For Numbers < 0 and 100 < Numbers, 
using 2 arrays/buckets is the more practical solution since it is very unlikely the median will fall into either bucket/array. 
This makes findMedian() O(1) in average case. 
In the worst case, all numbers fall in 1 array,
and we would either have to use Quickselect (O(n) average case, O(n2) worst case), or sorting (O(n log n)) to find the median.
If you use 2 heaps instead, you will get findMedian() of O(1) average case, O(log n) worst case.
'''
'''
The idea is to divide numbers into 2 balanced halves, one half low stores low numbers, 
the other half high stores high numbers. 
To access the median in O(1), 
we need a data structure that give us the maximum of low half and the minimum of high half in O(1). 
That's where maxHeap and minHeap come into play.

We use maxHeap to store a half of low numbers, top of the maxHeap is the highest number among low numbers.
We use minHeap to store a half of high numbers, top of the minHeap is the lowest number among high numbers.
We need to balance the size between maxHeap and minHeap while processing. Hence after adding k elements,
If k = 2 * i then maxHeap.size = minHeap.size = i
If k = 2 * i + 1, let maxHeap store 1 element more than minHeap, then maxHeap.size = minHeap.size + 1.

When adding a new number num into our MedianFinder:
Firstly, add num to the maxHeap, now maxHeap may contain the big element (which should belong to minHeap). 
So we need to balance, by removing the highest element from maxHeap, and offer it to minHeap.
Now, the minHeap might hold more elements than maxHeap, in that case, we need to balance the size, 
by removing the lowest element from minHeap and offer it back to maxHeap.

When doing findMedian():
If maxHeap.size > minHeap.size return top of the maxHeap, which is the highest number amongs low numbers.
Else if maxHeap.size == minHeap return the (maxHeap.top() + minHeap.top()) / 2

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
        self.minHeap = []
        self.maxHeap = []

    def addNum(self, num):
        """
        :type num: int
        :rtype: None
        """
        heappush(self.maxHeap, -num)
        heappush(self.minHeap, -heappop(self.maxHeap))
        if len(self.minHeap) > len(self.maxHeap):
            heappush(self.maxHeap, -heappop(self.minHeap))
        

    def findMedian(self):
        """
        :rtype: float
        """
        if len(self.maxHeap) > len(self.minHeap):
            return -self.maxHeap[0]
        return (-self.maxHeap[0] + self.minHeap[0]) / 2
