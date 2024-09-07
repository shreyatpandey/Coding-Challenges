'''
You are given a 0-indexed array of unique strings words.
A palindrome pair is a pair of integers (i, j) such that:
0 <= i, j < words.length,
i != j, and
words[i] + words[j] (the concatenation of the two strings) is a 
palindrome.
Return an array of all the palindrome pairs of words.
You must write an algorithm with O(sum of words[i].length) runtime complexity.
'''
 
'''
Example 1:

Input: words = ["abcd","dcba","lls","s","sssll"]
Output: [[0,1],[1,0],[3,2],[2,4]]
Explanation: The palindromes are ["abcddcba","dcbaabcd","slls","llssssll"]
Example 2:

Input: words = ["bat","tab","cat"]
Output: [[0,1],[1,0]]
Explanation: The palindromes are ["battab","tabbat"]
'''
'''
Constraints:
1 <= words.length <= 5000
0 <= words[i].length <= 300
words[i] consists of lowercase English letters.
'''
'''
Complexity Analysis
Let n be the number of words, and kbe the length of the longest word.
Time Complexity : O(k2⋅n)
There were 2 major steps to the algorithm. 
Firstly, we needed to build the Trie. Secondly, we needed to look up each word in the Trie.

Inserting each word into the Trie takes O(k)time. 
As well as inserting the word, we also checked at each letter whether or not the remaining part of the word was a palindrome. 
These checks had a cost of O, and with k of them, gave a total cost of O(k^2).
With n words to insert, the total cost of building the Trie was therefore O(k2⋅n)

Space-Complexity:- O((k+n)^2)
The Trie is the main space usage. In the worst case, each of the O(n⋅k) letters in the input would be on separate nodes,
and each node would have up to nnn indexes in its list. This gives us a worst case of O(n2⋅k) 
which is strictly larger than the input or the output.

Inserting and looking up words only takes k space though, because we're not generating a list of prefixes like we were in approach 2. 
This is insignificant compared to the size of the Trie itself.
'''

class TrieNode:
    def __init__(self):
        self.children = dict()
        self.end = False
        self.idx = -1
        self.palindromeIdxs = list()

class Solution:
    def __init__(self):
        self.root = TrieNode()
        
    def palindromePairs(self, words: List[str]) -> List[List[int]]:
        res = list()
        
        # populate the trie with
        # the reverse of every word.
        # once we're done inserting
        # we're going to have 3 conditions
        for i in range(len(words)):
            cur = self.root
            rWord = words[i][::-1]
            for j in range(len(rWord)):
                # if the current word (from j onwards)
                # is a palindrome, add it's index to the trie node
                # (palindromIdx list) we'll use it later on to find combinations
                if self.isPalindrome(rWord[j:]):
                    cur.palindromeIdxs.append(i)
                    
                if rWord[j] not in cur.children:
                    cur.children[rWord[j]] = TrieNode()
                cur = cur.children[rWord[j]]
                
            # once the word is done
            # add it's index to the trie node
            cur.end = True
            cur.idx = i
            
        for i in range(len(words)):
            self.search(words[i], i, res)
            
        return res
        
    # to find all pairse, we can have
    # conditions:
    # 1. exact match (abc, cba)
    # 2. long word, short word in trie match (abbcc, a)
    # 3. short word, long word in trie match (lls, sssll)
    def search(self, word, idx, res):   
        cur = self.root
        for i in range(len(word)):
            # 2. long word, short trie
            # so the trie ended here and 
            # we have matched till the ith
            # character, so we check if the
            # remaining of the word is also a
            # palindrome, if yes, then we have a pair
            # for e.g. word = abcdaa, trieWord = bcda
            # we can make a pair like abcdaabcda
            if cur.end and self.isPalindrome(word[i:]):
                res.append([idx, cur.idx])
                
            if word[i] not in cur.children:
                return
            cur = cur.children[word[i]]        
        
        # 1. exact match
        # in the given list, for that 
        # we'll take every word and then
        # check if the reverse of that
        # word lies in the trie
        # for e.g. for abc and cba
        # the trie would have both c->b->a and a->b->c
        # but when we take the first word (abc)
        # we'll match this with a->b->c which is
        # actually cba and so we found a match
        if cur.end and cur.idx != idx:
            res.append([cur.idx, idx])
        
        # 3. long trie, short word
        # so the trie still has items (not cur.end)
        # and the word has ended, it's the exact
        # opposite of point 2
        # for e.g. word=abcd trieWord=bcdaa
        # we can have a pair bcdaaabcd
        # and so we have a pair
        for pIdx in cur.palindromeIdxs:
            res.append([idx, pIdx])
                
        return
        
        
    def isPalindrome(self, s):
        return s == s[::-1]
