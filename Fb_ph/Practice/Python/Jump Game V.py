'''
Given an array of integers arr and an integer d. In one step you can jump from index i to index:

i + x where: i + x < arr.length and  0 < x <= d.
i - x where: i - x >= 0 and  0 < x <= d.
In addition, you can only jump from index i to index j if arr[i] > arr[j] and arr[i] > arr[k] 
for all indices k between i and j (More formally min(i, j) < k < max(i, j)).

You can choose any index of the array and start jumping. Return the maximum number of indices you can visit.

Notice that you can not jump outside of the array at any time.
'''
'''
Input: arr = [6,4,14,6,8,13,9,7,10,6,12], d = 2
Output: 4
Explanation: You can start at index 10. You can jump 10 --> 8 --> 6 --> 7 as shown.
Note that if you start at index 6 you can only jump to index 7. You cannot jump to index 5 because 13 > 9. 
You cannot jump to index 4 because index 5 is between index 4 and 6 and 13 > 9.
Similarly You cannot jump from index 3 to index 2 or index 1.
'''
'''
Constraints:
1 <= arr.length <= 1000
1 <= arr[i] <= 105
1 <= d <= arr.length
'''
'''
Complexity:-
TC:- O(n*d)
SC:- O(n)
'''
class Solution:
    def maxJumps(self, nums: List[int], d: int) -> int:
        N = len(nums)
        seen = set() # seen for lookup, to memoize
        dp = [1]*N   # stores the values of jump we can make from Ith index in DP.                                   
        #  minimum being 1 jump (i.e its self)
        
        def recursion(indx):
            # if we have indx in seen return its value  dp[indx].
            if indx in seen:
                return dp[indx]
            # base case if indx is out of range we cant jump. return 0
            if indx<0 or indx >= N:
                return 0
            
        # tempR : all the jumps we can make to the right side of indx
        # tempL : all the jumps we can make to the left side of indx
            tempR,tempL= 0,0
            curr = nums[indx] # height of current indx so we only jump allowed jump 
                    # i.e nums[i] < curr <- allowed  if curr =< nums[i] break(jump not allowed)
            
            #max jump we can make to the right Side are stored in tempR, 
            for i in range(indx+1, min(indx+d+1,N) ):
                if nums[i] < curr:
                    tempR = max(tempR, recursion(i)) # store max jumps in right
                else:
                    break
            for i in range(indx-1, max(-1,indx-d-1) , -1): 
                if nums[i] < curr:
                    tempL = max(tempL, recursion(i)) # store max jumps in  left
                else:
                    break
            # update dp[indx] by (1 + maxjumps( right, left))   ( 1 becoz it can jump on itself)
            dp[indx] = max(tempR,tempL) + 1 
            seen.add(indx) # as Indx calculated, can use its value next time, so added to seen
            return dp[indx]
        
        
        # for all indices we check how many jumps we can make
        for i in range(N): 
            if i not in seen: # if ith index is not in seen then we have comupted its jumps.
                recursion(i)
        return max(dp)  # returns the max jumps
