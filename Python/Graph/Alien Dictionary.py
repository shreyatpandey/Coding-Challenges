"""
Approach-1:- Graph + Topological Sort

Test-Case[1] :- [  "wrt","wrf","er","ett","rftt"]
Output:- "wertf"

Test-Case[2] :- ["z","x"]
Output:- "zx"

Test-Case[3] :- ["abc","ab"]
Output:- ""
"""


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
                
    
    #Topological Sorting
    def FinalString(self):
        ListString = []
        Dictlen = len(self.BuildSet)
        Queue = []
        for key,items in self.BuildSet.items() :
            if self.ListIndegree[ord(key)-ord('a')] == 0:
                ListString.append(key)
                Queue.append(key)
                
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
                
        
        
