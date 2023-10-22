'''
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. 
If it is impossible to finish all courses, return an empty array.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].

Example 3:

Input: numCourses = 1, prerequisites = []
Output: [0]
'''
'''
Constraints:
1 <= numCourses <= 2000
0 <= prerequisites.length <= numCourses * (numCourses - 1)
prerequisites[i].length == 2
0 <= ai, bi < numCourses
ai != bi
All the pairs [ai, bi] are distinct.

'''
'''
Approach:- Node Indegree Kahn's algorithm
Tc:- O(V+E)
Sc:- O(V+E)
'''
class Solution(object):
    def findOrder(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: List[int]
        """
        #Approach is through Kahn's Algorithm
        #Approach-1 to create Adjacency List
        #Step-1 :- Create Adjacency List
        inDegree = defaultdict(set)
        outDegree = defaultdict(set)
        orderCourses = []
        for vert1,vert2 in prerequisites:
            inDegree[vert1].add(vert2)
            outDegree[vert2].add(vert1)
        
            
        #Step-2: check that if inDegree 
        stk = []
        for i in range(0,numCourses):
            if i not in inDegree:
                stk.append(i)
                
        
        #why do we do this loop
        while len(stk) > 0:
            node = stk[-1]
            del stk[-1]
            orderCourses.append(node)
            for i in outDegree[node]:
                inDegree[i].remove(node)
                if len(inDegree[i]) == 0:
                    stk.append(i)
                    del inDegree[i]
            del outDegree[node]
    

        return orderCourses if len(inDegree) == 0 and len(outDegree) == 0 else []
