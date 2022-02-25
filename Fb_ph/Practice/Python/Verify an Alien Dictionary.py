'''
et NN be the length of order, and MM be the total number of characters in words.

Time complexity : O(M)O(M).

Storing the letter-order relation of each letter takes O(N)O(N) time. 
For the nested for-loops, we examine each pair of words in the outer-loop and for the inner loop, we check each letter in the current word. 
Therefore, we will iterate over all of letters in words.

Taking both into consideration, the time complexity is O(M + N) 
However, we know that Nis fixed as 2626. Therefore, the time complexity is O(M)

Space complexity : O(1)
The only extra data structure we use is the hashmap/array that serves to store the letter-order relations for each word in order. 
Because the length of order is fixed as 2626, this approach achieves constant space complexity.

'''

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
                elif Freq[word1[i]] > Freq[word2[i]]: 
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
