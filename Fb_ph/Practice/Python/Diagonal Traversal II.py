'''
Given a 2D integer array nums, return all elements of nums in diagonal order as shown in the below images.

Example 1:
Input: nums = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,4,2,7,5,3,8,6,9]

'''


'''
Complexity
Tc:- O(n)
Sc:- O(sqrt(n))
'''
class Solution:
    def findDiagonalOrder(self, nums: List[List[int]]) -> List[int]:
        queue = deque([(0, 0)])
        ans = []
        
        while queue:
            row, col = queue.popleft()
            ans.append(nums[row][col])
            
            if col == 0 and row + 1 < len(nums):
                queue.append((row + 1, col))
                
            if col + 1 < len(nums[row]):
                queue.append((row, col + 1))
        
        return ans
        
