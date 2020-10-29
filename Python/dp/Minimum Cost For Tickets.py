'''
In a country popular for train travel, you have planned some train travelling one year in advance.  
The days of the year that you will travel is given as an array days.  
Each day is an integer from 1 to 365.
Train tickets are sold in 3 different ways:
a 1-day pass is sold for costs[0] dollars;
a 7-day pass is sold for costs[1] dollars;
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.  
For example, if we get a 7-day pass on day 2, then we can travel for 7 days: day 2, 3, 4, 5, 6, 7, and 8.

Return the minimum number of dollars you need to travel every day in the given list of days.
'''
class Solution(object):
    def mincostTickets(self, days, costs):
        """
        :type days: List[int]
        :type costs: List[int]
        :rtype: int
        """
        maxtraveldays = days[-1]
        dp = [0* i for i in range(maxtraveldays+1)]
        for day in days:
            dp[day] = float('inf') 
        for i in range(1, maxtraveldays+1):
            if dp[i]!=float('inf'):
                dp[i] = dp[i-1]
                continue
            dp[i] = min(dp[i-1]+costs[0], dp[max(i-7, 0)]+costs[1], dp[max(i-30, 0)]+costs[2]) 
        return dp[maxtraveldays]
