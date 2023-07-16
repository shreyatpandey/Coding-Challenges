'''
Title:- Course Schedule
Approach:- O(V+E)
'''

from collections import defaultdict
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        inDegree = defaultdict(set)
        outDegree = defaultdict(set)
        for courses in prerequisites:
            inDegree[courses[0]].add(courses[1])
            outDegree[courses[1]].add(courses[0])
        stk = []
        for i in range(numCourses):
            if i not in inDegree:
                stk.append(i)
        while len(stk) != 0:
            lastElement = stk[-1]
            del stk[-1]
            for edges in outDegree[lastElement]:
                inDegree[edges].remove(lastElement)
                if len(inDegree[edges]) == 0:
                    del inDegree[edges]
                    stk.append(edges)
            del outDegree[lastElement]
        return len(outDegree)==0 and len(inDegree) ==0
