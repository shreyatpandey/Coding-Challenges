class Solution(object):
    def isAlienSorted(self, words, order):
        """
        :type words: List[str]
        :type order: str
        :rtype: bool
        """
        Freq = {}
        def Check(word1,word2) :
            MinLen = min(len(word1),len(word2))
            i = 0
            for i in range(0,MinLen):
                if Freq[word1[i]]<Freq[word2[i]] :
                    return True
                elif Freq[word1[i]] > Freq[word2[i]]: #why the hell this did nor strike me
                    return False
            if len(word1) > len(word2) :
                return False
            return True
            
        for i in range(0,len(order)):
            Freq[order[i]] = i
    
        for i in range(0,len(words)-1):
            if not Check(words[i],words[i+1]) :
                return False
        return True
