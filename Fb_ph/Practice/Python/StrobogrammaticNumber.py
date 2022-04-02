'''
TC:- O(n)
SC:- O(1) or this map
'''
class Solution:
    def isStrobogrammatic(self, num: str) -> bool:
        m = {'0':'0','1':'1','6':'9','8':'8','9':'6'}
        end = (len(num)+1)//2
        n = len(num)-1
        for i in range(end):
            a,b = num[i] , num[n-i]
            if a not in m:
                return False
            if m[a] != b:
                return False
        return True
