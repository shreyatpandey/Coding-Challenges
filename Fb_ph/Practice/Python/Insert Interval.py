'''
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi]
represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. 
You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in
ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.
 

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
'''
'''
Constraints:
0 <= intervals.length <= 10^4
intervals[i].length == 2
0 <= starti <= endi <= 10^5
intervals is sorted by starti in ascending order.
newInterval.length == 2
0 <= start <= end <= 10^5
'''
'''
If the interval are overlapping,
Minimum of start and max of end interval
If the interval does not overlapp with the first interval,
then there is no way it's going to overlap with other interval
Iterate through this sorted intervals and find the intersection point
Take [0,3]
Check the end value of the insert interval with the start value of the
intersection result
'''
'''
Complexity:-
TC:- O(n)
SC:- O(n) 
as new array has to be created
'''
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        result = []
        for i in range(len(intervals)):
            if newInterval[1]<intervals[i][0]:
                result.append(newInterval)
                return result + intervals[i:]
            elif newInterval[0] > intervals[i][1]:
                result.append(intervals[i])
            else:
                newInterval = [min(newInterval[0],intervals[i][0]),
                                max(newInterval[1],intervals[i][1])]
        result.append(newInterval)
        return result


