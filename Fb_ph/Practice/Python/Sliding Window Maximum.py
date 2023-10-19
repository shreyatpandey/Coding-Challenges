'''
You are given an array of integers nums, there is a sliding window of size k which is moving 
from the very left of the array to the very right. You can only see the k numbers in the window. 
Each time the sliding window moves right by one position.
Return the max sliding window.

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
'''
'''
Constraints:
1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
1 <= k <= nums.length
'''
'''
Deque:- Always decreasing
If the max value in deque is greater than previous one,
we eliminate the previous value
Whenever new element is added, check if the new value is greater than
the top most value of the deque
'''
'''
Complexity:-
Tc:- O(N)
Adding every vaue to deque - O(N)
Then removing every single value from deque - O(N)
Sc:- O(N)
For dequeue
Mononotically decreasing queue
'''
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        Result = []
        queue = deque()
        left,right = 0,0 # pointers for window
        while right < len(nums):
            #make sure no smaller values exist in our queue
            while queue and nums[queue[-1]] < nums[right]:
                queue.pop()
            queue.append(right) #it would contain indices
            #left value is out of bounds , then remove the left
            #value from the window
            if left > queue[0]:
                queue.popleft()

            if right+1 >= k:
                Result.append(nums[queue[0]])
                left += 1 # this is important as it woudl wrong result
            right += 1

        return Result
        
