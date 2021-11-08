#Time-Complexity :- O(log(n))
class Solution(object):
    def findMin(self,nums):
        startIndex = 0
        finalIndex = len(nums)-1
        #edge case:- array is alread sorted either in increasing order
        if nums[len(nums)-1] > nums[0]:
            return nums[0]
        minElement = float('inf')
        while startIndex <= finalIndex:
            midVal = startIndex + (finalIndex - startIndex) // 2
            if nums[midVal] > nums[midVal+1] :
                minElement = min(minElement,nums[midVal+1])
                return minElement
            if nums[midVal-1] > nums[midVal] :
                minElement = min(minElement,nums[midVal]) 
                return minElement
            if nums[0] < nums[midVal]:
                startIndex = midVal + 1
                #need to go right
            elif nums[midVal] < nums[0] :
                finalIndex = midVal - 1
        
        return minElement
