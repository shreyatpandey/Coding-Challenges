

#Recursive solution | Overlapping Subproblems | TLE
class Solution(object):
    def longestCommonSubsequence(self, text1, text2):
        """
        :type text1: str
        :type text2: str
        :rtype: int
        """
        def longestcommonsubsequence(text1,text2,lengthtext1,lengthtext2):
            if lengthtext1 == 0 or lengthtext2 == 0: 
                return 0; 
            elif text1[lengthtext1-1] == text2[lengthtext2-1]: 
                return 1 + longestcommonsubsequence(text1, text2,lengthtext1-1, lengthtext2-1); 
            else: 
                return max(longestcommonsubsequence(text1, text2, lengthtext1,lengthtext2-1), longestcommonsubsequence(text1, text2, lengthtext1-1, lengthtext2)) 

        return longestcommonsubsequence(text1,text2,len(text1),len(text2))
    
    #Bottom-Up Fashion | Memoization
    class Solution(object):
        def longestCommonSubsequence(self, text1, text2):
        """
        :type text1: str
        :type text2: str
        :rtype: int
        """
            lengthtext1 = len(text1) 
            lengthtext2 = len(text2) 

            LCS = [[]]
            LCS = [[0]*(lengthtext2+1) for i in range(lengthtext1+1)] 
            for i in range(lengthtext1+1): 
                for j in range(lengthtext2+1): 
                    if i == 0 or j == 0 : 
                        LCS[i][j] = 0
                    elif text1[i-1] == text2[j-1]: 
                        LCS[i][j] = LCS[i-1][j-1]+1
                    else: 
                        LCS[i][j] = max(LCS[i-1][j] , LCS[i][j-1]) 

            return LCS[lengthtext1][lengthtext2] 


