'''
You are given an integer array height of length n. 
There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.
'''
'''
Approach:- Two Pointer
Tc:- O(n)
where n is the size of height
Sc:- O(1)
'''
class Solution:
    def maxArea(self, height: List[int]) -> int:
        Left,Right = 0,len(height)-1
        MaxArea = 0
        while Left < Right:
            MaxArea = max(MaxArea,min(height[Left],height[Right])*(Right-Left))
            if height[Left] < height[Right]:
                Left += 1
            else:
                Right -= 1
        
        return MaxArea
if __name__ == '__main__':
    print("Test Case-1:")
    s = Solution()
    height = [1,8,6,2,5,4,8,3,7]
    print(s.maxArea(height))
'''
Test Case-1:
height[Left], height[Right] 1 7
height[Left], height[Right] 8 7
height[Left], height[Right] 8 3
height[Left], height[Right] 8 8
height[Left], height[Right] 8 4
height[Left], height[Right] 8 5
height[Left], height[Right] 8 2
height[Left], height[Right] 8 6
Max Area:- 49
'''
