'''
Given an array of intervals intervals where intervals[i] = [starti, endi], 
return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
'''
'''
Example 1:
Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
'''
'''
The problem can be solved using a greedy algorithm. The intervals are first sorted by their end time. 
This is done because we want to finish each interval as early as possible, so we have more time to accommodate the remaining intervals.
After sorting the intervals, the previous interval is initialized as the first interval in the sorted list, and 
a counter is initiated to keep track of the number of removed intervals. 
As we iterate through the intervals starting from the second one, 
we check if the current interval's start time is greater than or equal to the previous interval's end time. 
If it is, they are not overlapping and we update the previous interval to be the current one. 
If they overlap, the current interval is removed and the removal counter is incremented.
'''
'''
TC:- O(nlog(n))
SC:- O(1)
'''
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        if not intervals: 
            return 0 
        # Sort the intervals by end time 
        intervals.sort(key=lambda x: x[1]) 
        # Initialize the previous interval to the first one 
        prev_interval = intervals[0] 
        num_removed = 0 
        # Iterate through the intervals starting from the second one 
        for i in range(1, len(intervals)): 
            # If the current interval does not overlap with the previous, update prev_interval 
            if intervals[i][0] >= prev_interval[1]: 
                prev_interval = intervals[i] 
            # If they overlap, we remove the current interval, increment num_removed 
            else: 
                num_removed += 1 
        return num_removed 
