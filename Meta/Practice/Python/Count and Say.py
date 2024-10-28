'''
TC:- O(n^2)
SC:- O(n)
'''

class Solution:
    def countAndSay(self, n: int) -> str:
        ret = "1"
        for _ in range(n-1):
            ret = self.nextStep(ret)
        return ret
    
    def nextStep(self, s):
        i, ret = 0, ""
        while i < len(s):
            count = 1
            while i+1 < len(s) and s[i+1] == s[i]:
                count += 1
                i += 1
            ret += str(count) + s[i]
            i += 1
        return ret
