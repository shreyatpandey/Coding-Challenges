'''
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words
[beginWord, s1, s2, ..., sk].
'''
'''
Example 1:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"
'''
'''
Explanation:-
A defaultdict d is created, which will be used to store a mapping from each "intermediate word" (words that can be obtained from the original word by changing one letter) to a list of words that can be formed from it. 
The for-loop iterates over each word in the wordList, and for each word, it replaces each letter of the word with a * character, 
one at a time, and stores the resulting intermediate word as a key in the d dictionary, 
with the original word as a value in the corresponding list.
If the endWord is not present in the wordList, then no transformation sequence is possible, so an empty list is returned.
A depth-first search (DFS) function is defined to find all possible transformation sequences between beginWord and endWord. 
The function takes in a v node, the visited dictionary, a path list, and a paths list, which will be used to store the transformation sequences found. 
If v is not visited, the current path list is added to paths list, with the path being reversed if visited is visited1. 
Then, for each adjacent node u of v 
(i.e., a word that can be formed from v by changing one letter), the dfs function is called recursively.
'''
'''
Complexity:-
Tc:-O(NK^2+α).
Here N is the number of words in wordList, K is the maximum length of a word, α is the number of possible paths from beginWord to endWord in the directed graph we have.

Copying the wordList into the set will take O(N).

In BFS, every word will be traversed and for each word, we will find the neighbors using the function findNeighbors which has a time complexity of O(K^2).
Therefore the total complexity for all the N words will be O(NK^2).
Also, each word will be enqueued and will be removed from the set hence it will take O(N).
The total time complexity of BFS will therefore be equal to O(NK^2).
While backtracking, we will essentially be finding all the paths from beginWord to
endWord. Thus the time complexity will be equal to O(α).

Sc:- O(NK)
Here N is the Number of words in wordList, K is the Maximum length of a word.

Storing the words in a set will take O(NK) space.

To build the adjacency list O(N) space is required as the BFS will produce a directed
graph and hence there will be at max (N−1) edges.

In backtracking, stack space will be consumed which will be equal to the maximum number of active functions in the stack 
which is equal to the N as the path can have all the words in the wordList. Hence space required is O(N).
'''
from collections import defaultdict
from collections import deque
class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        prefix_d = defaultdict(list)
        for word in wordList:
            for i in range(0,len(word)):
                prefix_d[word[0:i]+"*"+word[i+1:]].append(word)
        
        order = {beginWord: []}
        queue = deque([beginWord])
        temp_q = deque()
        go_on = True
        end_list = []
        #BFS 
        while queue and go_on:  # There is no node even added to temp_q
            temp_d = {}
            while queue:        # Pop every node on this level
                cur = queue.popleft()
                for i in range(0, len(cur)):
                    for j in prefix_d[cur[0:i]+"*"+cur[i+1:]]:
                        if j == endWord:
                            end_list.append(j)
                            go_on = False
                        if j not in order:
                            if j not in temp_d:
                                temp_d[j] = [cur]
                                temp_q.append(j)
                            else:
                                temp_d[j].append(cur)
            queue = temp_q
            temp_q = deque()
            order.update(temp_d)
        
        ret = []
        
        # DFS to restore the paths
        def dfs(path, node):
            path = path + [node]    # add the node(Deepcopy)
            if order[node] == []:
                ret.append(list(path[::-1]))
                return
            for i in order[node]:
                dfs(path, i)
        if endWord in order:
            dfs([], endWord)
        else:
            return []
        
        return ret
 
