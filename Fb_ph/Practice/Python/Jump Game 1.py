'''
You are given an integer array nums. 
You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.
'''
'''
Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 105
'''


'''
Approach:- Greedy Solution
TC:- O(n)
SC:- O(1)
'''

class Solution:
    def canJump(self, nums: List[int]) -> bool: 
        destination = len(nums) - 1
        for i in range(destination-1, -1 , -1):
            # start from the second last position of nums 
            if i + nums[i] >= destination:
                # if from ith index, we can reach destination
                # update our destination to ith index
                destination = i
        # if destination reaches 0 meaning that we can reach end from first index
        # otherwise we can't
        return destination == 0
        
        # Explanation:
        # Greedy approach:
        # We start at the last index of the array and work our way backwards
        # for eg: nums = [2,3,1,1,4]
        # so we start from our destination i.e. 4, and work our way towards it 
        # meaning if we can reach 4 from its neighbour i.e. 1 , then it means 
        # all we need to make sure is that we can reach 1;
        # because if we reach 1 we can obviously reach 4
        # similarly if we can reach first occurr of 1 from 3 then all we need to do is 
		# reach 3, because if we can, then we can reach 4 and so on.
        # NOTE: we dont want to minimize the number of steps to reach
        #       we just want to check if we can or cannot reach
        #       Thats why, this approach works.
