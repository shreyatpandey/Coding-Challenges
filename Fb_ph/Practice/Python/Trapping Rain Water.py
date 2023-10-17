'''
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it can trap after raining.
'''
'''
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped.
'''
'''
So, we can say that if there is a larger bar at one end (say right), we are assured that the water trapped 
would be dependant on height of bar in current direction (from left to right). 
As soon as we find the bar at other end (right) is smaller, we start iterating in opposite direction (from right to left).
We must maintain left_max and right_max during the iteration, 
but now we can do it in one iteration using 2 pointers, switching between the two.
'''
'''
Two Pointer Approach
Complexity
Tc:- O(n)
Sc:- O(1)
'''
class Solution:
    def trap(self, height: List[int]) -> int:
        left, right = 0, len(height)-1 # these pointers are traversal of list/array <-->indexing
        left_wall, right_wall = 0,0 ;  # these pointer <=> need to learn more about this usage
        water = 0
    
        while left < right:
            if height[left] < height[right] :
                if height[left] > left_wall:
                    left_wall = height[left]
                else:
                    water += left_wall - height[left]
                left += 1
            else:
                if height[right]>right_wall: 
                    right_wall = height[right]
                else : 
                    water += right_wall - height[right]
                right -=1
        
        return water
