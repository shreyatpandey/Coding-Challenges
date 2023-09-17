'''
Given a string s and a dictionary of strings wordDict, 
add spaces in s to construct a sentence where each word is a valid dictionary word. 
Return all such possible sentences in any order.

Note that the same word in the dictionary may be reused multiple times in the segmentation. 

Example 1:

Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: []
'''
'''
Constraints:
1 <= s.length <= 20
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 10
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.
Input is generated in a way that the length of the answer doesn't exceed 105.
'''

'''
Let W be the number of words in WordDict
N - length of the string
TC:- O(N^2 + 2^N + W)
SC:- O(2^N.N + W)
'''
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        def helper(s, wordDict, memo):
            if s in memo: return memo[s]
            if not s: return []
    
            res = []
            for word in wordDict:
                if not s.startswith(word):
                    continue
                if len(word) == len(s):
                    res.append(word)
                else:
                    resultOfTheRest = helper(s[len(word):], wordDict, memo)
                    for item in resultOfTheRest:
                        item = word + ' ' + item
                        res.append(item)
            memo[s] = res
            return res

        return helper(s,wordDict,{})
