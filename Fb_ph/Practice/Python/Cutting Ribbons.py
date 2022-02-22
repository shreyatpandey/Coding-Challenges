class Solution:
    def maxLength(self, ribbons: List[int], k: int) -> int:
        sumOfRibbons = sum(ribbons)
        if sumOfRibbons < k:
            return 0
        def isBisect(target):
            nonlocal ribbons,k
            count = 0
            for rib in ribbons:
                count += rib//target
            return count>=k
        
        left,right = 1,max(ribbons)
        while left <= right:
            midVal = (left+right)//2
            if isBisect(midVal):
                left = midVal + 1
            else:
                right = midVal -1
        
        return right
      
      
 '''
Input:- ribbons = [9,7,5], k = 3
Output: 5

Explanation:
- Cut the first ribbon to two ribbons, one of length 5 and one of length 4.
- Cut the second ribbon to two ribbons, one of length 5 and one of length 2.
- Keep the third ribbon as it is.
Now you have 3 ribbons of length 5.
 '''
