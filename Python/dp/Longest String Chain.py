"""
Approach-1: 1D Dp
TC:- O(n^2)
SC:- O(LengthofWordList) = O(N)
"""

class Solution(object):
    def longestStrChain(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        """
        Step-1: sort the list in reverse order
        Step-2: create a helper function to check if the previous word/character is present in next word/character
        Step-3: max of the dp list 
        """
        words.sort(reverse=True,key=len)
        dp = [1 for i in range(len(words))]
        for i in range(len(words)):
            for j in range(i+1,len(words)):
                if len(words[i]) == len(words[j]) :
                    continue;
                if len(words[i])-1 > len(words[j]) :
                    break;
                if self.Helper(words[i],words[j]) == True:
                    dp[j] = max(1+dp[i],dp[j])
        return max(dp)
    
    def Helper(self,word1,word2):
        i=j=0
        while i < len(word2):
            if word2[i] != word1[j] :
                if j != i:
                    return False
                j += 1
            else:
                i += 1
                j += 1
        return True
        
        
