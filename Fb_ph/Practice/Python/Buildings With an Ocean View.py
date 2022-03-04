'''
Description:-
There are n buildings in a line. 
You are given an integer array heights of size n that represents the heights of the buildings in the line.

The ocean is to the right of the buildings. 
A building has an ocean view if the building can see the ocean without obstructions. 
Formally, a building has an ocean view if all the buildings to its right have a smaller height.

Return a list of indices (0-indexed) of buildings that have an ocean view, sorted in increasing order.
Example 1:

Input: heights = [4,2,3,1]
Output: [0,2,3]
Explanation: Building 1 (0-indexed) does not have an ocean view because building 2 is taller.

'''


'''
N is the len of height
TC:- O(N) 
SC:- O(N) for the maxHeights not taking into account for Result
'''

class Solution:
    def findBuildings(self, heights: List[int]) -> List[int]:
        sizeHeight = len(heights)
        Result = []
        maxHeights  = [0*i for i in range(sizeHeight+1)]
        for i in range(sizeHeight-1,-1,-1):
            if heights[i] > maxHeights[i+1]:
                Result.append(i)
            maxHeights[i] = max(heights[i],maxHeights[i+1])
        
        Result.reverse()
        return Result

'''
Space-Optimization
TC:- O(N)
SC:- O(1) not taking into account space for Result
'''
class Solution:
    def findBuildings(self, heights: List[int]) -> List[int]:
        n = len(heights)
        answer = []
        max_height = -1
        
        for current in reversed(range(n)):
            # If there is no building higher (or equal) than the current one to its right,
            # push it in the answer array.
            if max_height < heights[current]:
                answer.append(current)
            
                # Update max building till now.
                max_height = heights[current]
        
        answer.reverse()
        return answer
            
