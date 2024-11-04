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
        print("Self.minh", self.minh)
        num, i, j = heapq.heappop(self.minh)
        print("num : ", num)
        if j+1 < len(self.lists[i]):
            heapq.heappush(self.minh, (self.lists[i][j+1], i, j+1))
        return num
    
    def hasNext(self):
        return len(self.minh) > 0
    
    
if __name__ == "__main__":
    s = SortedIterator([[1, 4, 5, 8, 9], [3, 4, 4, 6], [0, 2, 8]])
    while s.hasNext():
        print(s.next())

'''
Output : Trace
Self.minh [(0, 2, 0), (3, 1, 0), (1, 0, 0)]
num :  0
0
Self.minh [(1, 0, 0), (3, 1, 0), (2, 2, 1)]
num :  1
1
Self.minh [(2, 2, 1), (3, 1, 0), (4, 0, 1)]
num :  2
2
Self.minh [(3, 1, 0), (4, 0, 1), (8, 2, 2)]
num :  3
3
Self.minh [(4, 0, 1), (8, 2, 2), (4, 1, 1)]
num :  4
4
Self.minh [(4, 1, 1), (8, 2, 2), (5, 0, 2)]
num :  4
4
Self.minh [(4, 1, 2), (8, 2, 2), (5, 0, 2)]
num :  4
4
Self.minh [(5, 0, 2), (8, 2, 2), (6, 1, 3)]
num :  5
5
Self.minh [(6, 1, 3), (8, 2, 2), (8, 0, 3)]
num :  6
6
Self.minh [(8, 0, 3), (8, 2, 2)]
num :  8
8
Self.minh [(8, 2, 2), (9, 0, 4)]
num :  8
8
Self.minh [(9, 0, 4)]
num :  9
9
'''