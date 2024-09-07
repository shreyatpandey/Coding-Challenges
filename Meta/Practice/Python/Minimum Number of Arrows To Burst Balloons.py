'''
There are some spherical balloons taped onto a flat wall that represents the XY-plane.
The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] 
denotes a balloon whose horizontal diameter stretches between xstart and xend. You do not know the exact y-coordinates of the balloons.

Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. 
A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. 
There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.

Given the array points, return the minimum number of arrows that must be shot to burst all balloons.
'''
'''
Example 1:

Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
- Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].
'''
'''
Constraints:

1 <= points.length <= 10^5
points[i].length == 2
-2**31 <= xstart < xend <= 2**31 - 1
'''
'''
Complexity:-
Tc:- O(nlog(n))
Sc:- O(log(n)) 
This depends upon which sorting algorithm we are implementing
'''

class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        n = len(points)
        if n<2:
            return n

        #sort by start and end point
        START, END = 0,1
        points.sort(key=lambda i: (i[START],i[END]) )
        prev, cur = points[0], None
        darts = 0

        for i in range(1, n):
            cur = points[i]

            if cur[START] <= prev[END]:
                #overlap, wait for more overlap to throw dart
                prev = [cur[START], min(cur[END],prev[END])]
            else:
                #no overlap, throw dart at previous
                darts += 1
                prev = cur
		
		#pop the last balloon and return
        return darts+1
        
