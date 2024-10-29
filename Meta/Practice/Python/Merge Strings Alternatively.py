'''
You are given two strings word1 and word2. 
Merge the strings by adding letters in alternating order, starting with word1. 
If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.
'''
'''
Constraints:
1 <= word1.length, word2.length <= 100
word1 and word2 consist of lowercase English letters.
'''
'''
TC :- O(max(len(word1), len(word2)))
SC :- Result [ Output ]
'''
class Solution(object):
    def mergeAlternately(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: str
        """
        maxLen = max(len(word1), len(word2))
        result = []
        for i in range(maxLen):
            if i < len(word1):
                result.append(word1[i])
            if i < len(word2):
                result.append(word2[i])
        return "".join(result)
        