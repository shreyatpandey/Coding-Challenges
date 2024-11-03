'''
Implement a sorted java iterator that returns a sorted list over k sorted lists.


class SortedIterator implements Iterator<Integer> {
	public SortedIterator(List<List<Integer>> lists) {}
	public boolean hasNext() {}
	public Integer next() {}
}
Example:


Input: 
[[1, 4, 5, 8, 9],
 [3, 4, 4, 6],
 [0, 2, 8]]
Output:  0, 1, 2, 3, 4, 4, 4, 5, 6, 8, 8, 9
'''
import heapq
class SortedIterator:
    def __init__(self, lists):
        self.lists = lists
        self.minh = []
        for i, x in enumerate(lists):
            if x:
                heapq.heappush(self.minh, (x[0], i, 0))
    
    def next(self):
        if not self.minh:
            return None
        num, i, j = heapq.heappop(self.minh)
        if j+1 < len(self.lists[i]):
            heapq.heappush(self.minh, (self.lists[i][j+1], i, j+1))
        return num
    
    def hasNext(self):
        return len(self.minh) > 0
    
    
if __name__ == "__main__":
    s = SortedIterator([[1, 4, 5, 8, 9], [3, 4, 4, 6], [0, 2, 8]])
    while s.hasNext():
        print(s.next())