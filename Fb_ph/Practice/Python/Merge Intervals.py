'''
Input:-
Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

intervals = [[1,3],[2,4]]
Output:- [[1,4]]

'''
'''
TC:- O(nlog(n))
SC:- O(logN) for mergesort 
'''
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        merged = []
        for i in range(len(intervals)):
            if merged == []:
                merged.append(intervals[i])
            else:
                previous_end = merged[-1][1]
                current_start = intervals[i][0]
                current_end = intervals[i][1]
                if previous_end >= current_start: # overlap
                    merged[-1][1] = max(previous_end,current_end)
                else:
                    merged.append(intervals[i])
        return merged
 
'''
Follow-Up
'''
'''
Q] Question: How do you add intervals and merge them for a large stream of intervals? (Facebook Follow-up Question)
We need to have two functions for the tree (add interval and query tree).

Implementation Details
TreeNode - On top of the left child, right child, start boundary, and end boundary, 
we have a middle field that determines whether a new interval goes to the left child, right right or merged with the current node.

add - If the new interval touches or crosses the middle of the current node, we update the current node. 
Otherwise, we put the new interval into the left subtree or right subtree.

Why do we use middle for comparison and not start or end boundaries?
The reason is that we can use merge-sort technique to query the merged intervals result when the left subtree does not overlap with the right subtree.
query - Use merge-sort technique by retrieving the merged intervals of the left subtree (i.e. left_intervals) 
and those of the right subtree (i.e. right_intervals).
Because of the implementation of add, we can guarantee that
if there's an interval in the left_intervals that overlaps with the current node, 
then we know that all the intervals after that interval overlaps with the current node.
The first few intervals or zero intervals in the right_intervals overlap with the current node.
Here's the visualization:

left_res = [ (intervals that do not overlap), (intervals that overlap with current node) ]
right_res = [ (intervals that overlap with current node), (intervals that do not overlap) ]

class TreeNode:
    def __init__(self, start, end, middle):
        self.start = start
        self.end = end
        self.middle = middle
        self.left = self.right = None

class Solution:
    def __init__(self):
        self.root = None
    
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals:
            return []
        
        for start, end in intervals:
            if not self.root:
                self.root = TreeNode(start, end, (start + end) // 2)
            else:
                self.add(self.root, start, end)
        
        return self.query(self.root)
    
    
    def add(self, node, start, end):     
        if end < node.middle:
            if node.left:
                self.add(node.left, start, end)
            else:
                node.left = TreeNode(start, end, (start + end) // 2)
        
        elif start > node.middle:
            if node.right:
                self.add(node.right, start, end)
            else:
                node.right = TreeNode(start, end, (start + end) // 2)
        
        else:
            node.start = min(node.start, start)
            node.end = max(node.end, end)
    
    def query(self, node):
        if not node:
            return []
        
        # merge-sort divide and conquer
        left_intervals = self.query(node.left)
        right_intervals = self.query(node.right)
        res = []
        
        inserted = False
        
        for lres in left_intervals:
            if lres[1] < node.start:
                res.append(lres)
            else:
                res.append([min(lres[0], node.start), node.end])
                inserted = True
                break
        
        if not inserted:
            res.append([node.start, node.end])
        
        for rres in right_intervals:
            if rres[0] <= node.end:
                res[-1][1] = max(node.end, rres[1])
            else:
                res.append(rres)
        
        return res
'''
'''
Initial sorting will not help much since it consists of large dataset
Priority Queue would also not be not of much help as it would take care of only min interval and 
for rest of the interval would not be in sorted order
'''


        
