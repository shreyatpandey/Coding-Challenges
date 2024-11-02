'''
There are n persons on a social media website. You are given an integer array ages where ages[i] is the age of the ith person.

A Person x will not send a friend request to a person y (x != y) if any of the following conditions is true:

age[y] <= 0.5 * age[x] + 7
age[y] > age[x]
age[y] > 100 && age[x] < 100
Otherwise, x will send a friend request to y.

Note that if x sends a request to y, y will not necessarily send a request to x. Also, a person will not send a friend request to themself.

Return the total number of friend requests made.

Example 1:

Input: ages = [16,16]
Output: 2
Explanation: 2 people friend request each other.

'''
'''
Constraints:

n == ages.length
1 <= n <= 2 * 104
1 <= ages[i] <= 120

'''

'''
Complexity:-
TC:- O(n) which is time to find freqMap.
There are max 120 different ages, so we can say two loops take up O(120) * O(120) => constant.
'''
from collections import Counter
class Solution(object):
    def numFriendRequests(self, ages):
        """
        :type ages: List[int]
        :rtype: int
        """
        ans = 0
        cnt = Counter(ages)
        for k1, v1 in cnt.items():
            for k2, v2 in cnt.items():
                if (k2 > 0.5*k1 + 7 and
                    k2 <= k1):
                    # if both conditions met
                    ans += v1 * v2
                    if k1 == k2:
                        ans -= v1
        return ans
