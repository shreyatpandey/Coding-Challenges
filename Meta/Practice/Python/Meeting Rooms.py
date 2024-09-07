'''
Given an array of meeting time intervals where intervals[i] = [starti, endi], 
determine if a person could attend all meetings.
'''
'''
Example 1:

Input: intervals = [[0,30],[5,10],[15,20]]
Output: false
Example 2:

Input: intervals = [[7,10],[2,4]]
Output: true
''' 
'''
Constraints:
0 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti < endi <= 106
'''
'''
Complexity:-
TC:- O(nlog(n))
SC:- O(1)
'''
class Solution:
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
        intervals.sort()
        for i in range(len(intervals) - 1):
            if intervals[i][1] > intervals[i + 1][0]:
                return False
        return True
