'''
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Find the kth positive integer that is missing from this array.
Example 1:

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.

'''
'''
TC:- O(log(N)
SC:- O(1)
'''
def findKthPositive(self, A, k):
        l, r = 0, len(A)
        while l < r:
            m = (l + r) / 2
            if A[m] - 1 - m < k:
                l = m + 1
            else:
                r = m
        return l + k
