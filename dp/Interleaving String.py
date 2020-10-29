"""
Approach-1 :- 1D DP Approach
TC:- O(M*N)
where M is the length of first string and N is the length of second string
SC:- O(M) where M is the length of first string
"""
"""
TestCase[1] :- s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output[1] :- true

TestCase[2] :- s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output[2] :- false
"""


class Solution(object):
    def isInterleave(self, s1, s2, s3):
        """
        :type s1: str
        :type s2: str
        :type s3: str
        :rtype: bool
        """
        if len(s3) != len(s1) + len(s2) :
            return False
        dp = [False*i for i in range(len(s2)+1)]
        for i in range(len(s1)+1) :
            for j in range(len(s2)+1) :
                if i == 0 and j == 0:
                    dp[j] = True
                elif i == 0:
                    dp[j] = dp[j-1] and s2[j-1] == s3[i+j-1]
                elif j == 0:
                    dp[j] = dp[j] and s1[i-1] == s3[i+j-1]
                else:
                    dp[j] = (dp[j] and s1[i-1] == s3[i+j-1]) or (dp[j-1] and s2[j-1] == s3[i+j-1])
        return dp[len(s2)]
