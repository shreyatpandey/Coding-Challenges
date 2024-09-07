'''
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
'''
'''
Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.
'''

'''
Approach:- Topological sorting
Tc:- O(V+E)
V - number of courses
adjlist takes O(V) times
creating inDegree = O(n)
Sc:- 
O(m+n)
For adjList
For stack operation

'''
from collections import defaultdict
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        inDegree = defaultdict(set)
        outDegree = defaultdict(set)
        for courses in prerequisites:
            inDegree[courses[0]].add(courses[1])
            outDegree[courses[1]].add(courses[0])
        stk = [] # or queue = deque
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

'''
Approach:- DFS
Tc:- O(m+n)
Sc:- O(m+n)
'''
class Solution:
    def dfs(self, node, adj, visit, inStack):
        # If the node is already in the stack, we have a cycle.
        if inStack[node]:
            return True
        if visit[node]:
            return False
        # Mark the current node as visited and part of current recursion stack.
        visit[node] = True
        inStack[node] = True
        for neighbor in adj[node]:
            if self.dfs(neighbor, adj, visit, inStack):
                return True
        # Remove the node from the stack.
        inStack[node] = False
        return False

    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj = [[] for _ in range(numCourses)]
        for prerequisite in prerequisites:
            adj[prerequisite[1]].append(prerequisite[0])

        visit = [False] * numCourses
        inStack = [False] * numCourses
        for i in range(numCourses):
            if self.dfs(i, adj, visit, inStack):
                return False
        return True
            
