'''
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words 
in the shortest transformation sequence from beginWord to endWord, 
or 0 if no such sequence exists.
'''
'''
Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
'''
'''
Constraints:

1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.
'''
'''
Complexity:-
Tc:- O(M^2 * N)
where M is the length of each word and N is the total number of words
For each word in the word list, we iterate over its length to find all the intermediate words corresponding to it. 
Since the length of each word is M and we have N words, the total number of iterations the algorithm takes to create all_combo_dict is M*N. 
Additionally, forming each of the intermediate word takes O(M)time because of the substring operation used to create the new string. 
This adds up to a complexity of O(M^2*N)
Breadth first search in the worst case might go to each of the N words. 
For each word, we need to examine M possible intermediate words/combinations. 
Notice, we have used the substring operation to find each of the combination. Thus, M combinations take O(M^2)
time. As a result, the time complexity of BFS traversal would also be O(M^2*N).

Sc:- O(M^2*N)
Each word in the word list would have M intermediate combinations. 
To create the all_combo_dict dictionary we save an intermediate word as the key and its corresponding original words as the value. 
Note, for each of M intermediate words we save the original word of length M. This simply means, for every word we would need a space of M^2
to save all the transformations corresponding to it. Thus, all_combo_dict would need a total space of O(M^2*N).
Visited dictionary would need a space of O(M*N) as each word is of length M.
Queue for BFS in worst case would need a space for all O(N) words and this would also result in a space complexity of O(M*N).
'''
from collections import deque
from collections import defaultdict
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if endWord not in wordList:
            return 0

        nei = defaultdict(list)
        wordList.append(beginWord)
        for word in wordList:
            for j in range(len(word)):
                pattern = word[:j] + "*" + word[j + 1 :]
                nei[pattern].append(word)

        visit = set([beginWord])
        q = deque([beginWord])
        res = 1
        while q:
            for i in range(len(q)):
                word = q.popleft()
                if word == endWord:
                    return res
                for j in range(len(word)):
                    pattern = word[:j] + "*" + word[j + 1 :]
                    for neiWord in nei[pattern]:
                        if neiWord not in visit:
                            visit.add(neiWord)
                            q.append(neiWord)
            res += 1
        return 0
