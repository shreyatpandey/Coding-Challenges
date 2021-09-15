'''
Given an integer n, return any array containing n unique integers such that they add up to 0.
'''
class Solution(object):
    def sumZero(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        ans = []
        if n&1 != 0:
            ans.append(0)
        for i in range(1,n):
            if len(ans) == n:
                return ans
            ans.append(i)
            ans.append(-i)
        
        return ans
            
        
