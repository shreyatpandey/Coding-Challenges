class Solution(object):
    def shortestDistance(self, words, word1, word2):
        """
        :type words: List[str]
        :type word1: str
        :type word2: str
        :rtype: int
        """
        ShortestDistance = float('inf')
        Word1Indices = [i for i, x in enumerate(words) if x == word1 ]
        Word2Indices = [i for i, x in enumerate(words) if x == word2 ]
        
        for i in range(0,len(Word1Indices)) :
            for j in range(0,len(Word2Indices)) :
                if abs(Word1Indices[i] - Word2Indices[j]) < ShortestDistance :
                    ShortestDistance = abs(Word1Indices[i] - Word2Indices[j])
        
        return ShortestDistance
