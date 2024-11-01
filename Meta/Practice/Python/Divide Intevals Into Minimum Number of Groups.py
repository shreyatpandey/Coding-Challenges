'''
You are given a 2D integer array intervals where intervals[i] = [lefti, righti]
represents the inclusive interval [lefti, righti].

You have to divide the intervals into one or more groups such that each interval is in exactly one group, 
and no two intervals that are in the same group intersect each other.

Return the minimum number of groups you need to make.

Two intervals intersect if there is at least one common number between them. 
For example, the intervals [1, 5] and [5, 8] intersect.

Example 1:

Input: intervals = [[5,10],[6,8],[1,5],[2,3],[1,10]]
Output: 3
Explanation: We can divide the intervals into the following groups:
- Group 1: [1, 5], [6, 8].
- Group 2: [2, 3], [5, 10].
- Group 3: [1, 10].
It can be proven that it is not possible to divide the intervals into fewer than 3 groups.
'''
'''
Constraints:
1 <= intervals.length <= 10^5
intervals[i].length == 2
1 <= lefti <= righti <= 10^6
'''
'''
At time point intervals[i][0],
start using a meeting room(group).

At time point intervals[i][1] + 1,
end using a meeting room.

Sort all events by time,
and accumulate the number of room(group) used.
'''

'''
Approach :- 
Sweep Line Algorithm

TC :- O(nlogn)
SC :- O(n)

'''
def minGroups(intervals):
    A = []
    for a,b in intervals:
        A.append([a, 1])
        A.append([b + 1, -1])
    res = cur = 0
    for a, diff in sorted(A):
        cur += diff
        res = max(res, cur)
    return res

