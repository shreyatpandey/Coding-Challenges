'''
The chess knight has a unique movement, it may move two squares vertically and one square horizontally, 
or two squares horizontally and one square vertically (with both forming the shape of an L). 
The possible movements of chess knight are shown in this diagaram:

A chess knight can move as indicated in the chess diagram below

Given an integer n, return how many distinct phone numbers of length n we can dial.

You are allowed to place the knight on any numeric cell initially and then you should perform n - 1 jumps to dial a number of length n. 
All jumps should be valid knight jumps.

As the answer may be very large, return the answer modulo 10^9 + 7

Example 2:

Input: n = 2
Output: 20
Explanation: All the valid number we can dial are [04, 06, 16, 18, 27, 29, 34, 38, 40, 43, 49, 60, 61, 67, 72, 76, 81, 83, 92, 94]

'''
'''
Constraints:-
1 <= n <= 5000
'''
'''
Complexity:-
TC:- O(N)
SC:- O(1)
DP-Based Solution
'''
class Solution(object):
    def knightDialer(self, N):
        """
        :type n: int
        :rtype: int
        """
        neighbors = {
                        0:(4,6),
                        1:(6,8),
                        2:(7,9),
                        3:(4,8),
                        4:(0,3,9),
                        5:(),
                        6:(0,1,7),
                        7:(2,6),
                        8:(1,3),
                        9:(2,4)
                            }
        current_counts = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
        for _ in range(N-1):
            next_counts = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
            for src_key in range(10):
                for dst_key in neighbors[src_key]:
                    next_counts[dst_key] = (next_counts[dst_key] + current_counts[src_key]) % (10**9 + 7)
            current_counts = next_counts
        return sum(current_counts) % (10**9 + 7)
