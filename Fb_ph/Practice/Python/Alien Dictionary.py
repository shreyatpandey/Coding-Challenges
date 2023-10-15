'''
There is a new alien language that uses the English alphabet. However, the order among the letters is unknown to you.

You are given a list of strings words from the alien language's dictionary, 
where the strings in words are sorted lexicographically by the rules of this new language.

Return a string of the unique letters in the new alien language sorted in lexicographically increasing order by the new language's rules. 
If there is no solution, return "". If there are multiple solutions, return any of them.

A string s is lexicographically smaller than a string t if at the first letter where they differ, the letter in s comes before the letter in t in the alien language. 
If the first min(s.length, t.length) letters are the same, then s is smaller if and only if s.length < t.length.

 

Example 1:

Input: words = ["wrt","wrf","er","ett","rftt"]
Output: "wertf"
Example 2:

Input: words = ["z","x"]
Output: "zx"
Example 3:

Input: words = ["z","x","z"]
Output: ""
Explanation: The order is invalid, so return "".
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] consists of only lowercase English letters.
'''
'''


'''

"""
Approach-1:- Graph + Topological Sort
Test-Case[1] :- [  "wrt","wrf","er","ett","rftt"]
Output:- "wertf"
Test-Case[2] :- ["z","x"]
Output:- "zx"
Test-Case[3] :- ["abc","ab"]
Output:- ""
"""
'''
Complexity
TC:- O(N+K) similar to O(V+E)
where N is the total number of words and k is the total number of unique characters
SC:- O(V+E) for the adjacency list 
where V is the total number of characters in input array and E is the total number of connections/dependency
'''

from collections import OrderedDict
class Solution(object):
    def __init__(self) :
        self.ListIndegree = [0*i for i in range(26)]
        self.BuildSet = OrderedDict()
    
    def alienOrder(self, words):
        """
        :type words: List[str]
        :rtype: str
        """
        self.BuildGraph(words)
        return self.FinalString()
        
    #Build Graph here
    def BuildGraph(self,words) :
        for word in words:
            for character in word:
                if character not in self.BuildSet:
                    self.BuildSet[character] = set()
        print("self.BuildSet-1:",self.BuildSet)
        for i in range(1,len(words)):
            first = words[i-1]
            second = words[i]
            MinLength = min(len(first),len(second))
            for j in range(MinLength) :
                out = first[j]
                inplace = second[j]
                if out != inplace :
                    if inplace not in self.BuildSet[out]:
                        self.BuildSet[out].add(inplace)
                        self.ListIndegree[ord(inplace)-ord('a')] += 1
                    break;
                    
                #Takes care of the edge case:- ["abc","ab"]
                if j + 1 == MinLength and len(first) > len(second):
                    self.BuildSet.clear();
                    return;
        print("self.BuildSet-2:",self.BuildSet)
        print("ListIndegree:",self.ListIndegree)
    
     #Topological Sorting
    def FinalString(self):
        ListString = []
        Dictlen = len(self.BuildSet)
        Queue = []
        for key,items in self.BuildSet.items() :
            if self.ListIndegree[ord(key)-ord('a')] == 0:
                ListString.append(key)
                Queue.append(key)
        
        print("ListString:",ListString)
                
        while ( len(Queue)>0) :
            current = Queue[0]
            del Queue[0]
            LoopMap = self.BuildSet[current]
            if len(LoopMap) == 0 :
                continue;
            for neighbour in LoopMap :
                self.ListIndegree[ord(neighbour)-ord('a')] -= 1
                if self.ListIndegree[ord(neighbour)-ord('a')] == 0:
                    Queue.append(neighbour)
                    ListString.append(neighbour)
        if len(ListString) == Dictlen :
            return ''.join(ListString)
        else:
            return ""
                
if __name__ == '__main__':
    
    print("Test Case-1:")
    Input = ["wrt","wrf","er","ett","rftt"]
    s = Solution()
    print("s.alienOrder:",s.alienOrder(Input))
    print('\n')
    
    
    print("Test Case-2:")
    Input = ["abc","ab"]
    s1 = Solution()
    print("s.alienOrder:",s1.alienOrder(Input))
    print('\n')
    
    print("Test Case-3:")
    Input = ["a","bc","cde"]
    s2 = Solution()
    print("s.alienOrder:",s2.alienOrder(Input))

'''
Test Case-1:
self.BuildSet-1: OrderedDict([('w', set()), ('r', set()), ('t', set()), ('f', set()), ('e', set())])
self.BuildSet-2: OrderedDict([('w', {'e'}), ('r', {'t'}), ('t', {'f'}), ('f', set()), ('e', {'r'})])
ListIndegree: [0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0]
ListString: ['w']
s.alienOrder: wertf


Test Case-2:
self.BuildSet-1: OrderedDict([('a', set()), ('b', set()), ('c', set())])
ListString: []
s.alienOrder: 


Test Case-3:
self.BuildSet-1: OrderedDict([('a', set()), ('b', set()), ('c', set()), ('d', set()), ('e', set())])
self.BuildSet-2: OrderedDict([('a', {'b'}), ('b', {'c'}), ('c', set()), ('d', set()), ('e', set())])
ListIndegree: [0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
ListString: ['a', 'd', 'e']
s.alienOrder: adebc
'''
                
