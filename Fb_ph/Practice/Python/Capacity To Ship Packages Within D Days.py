
'''
A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. 
Each day, we load the ship with packages on the conveyor belt (in the order given by weights). 
We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.
'''
'''
Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

'''

class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        '''
        how do we know the max capacity of the ship?
        '''
        def isMin(capacity):
            nonlocal weights, days
            countDays  = 1
            maxWeight = capacity
            for weight in weights:
                if weight > maxWeight:
                    maxWeight = capacity
                    countDays += 1
                maxWeight -= weight
            if countDays <= days :
                return True
            else:
                return False
        
        left = max(weights)
        right = sum(weights)
        while left < right:
            midVal = left + (right-left)//2
            if isMin(midVal):
                right = midVal
            else:
                left = midVal + 1
        
        return left
 
