'''
You have a graph of n nodes. You are given an integer n and an array edges where edges[i] = [ai, bi] 
indicates that there is an edge between ai and bi in the graph.

Return the number of connected components in the graph.

Example 1:
Input: n = 5, edges = [[0,1],[1,2],[3,4]]
Output: 2

Example 2:
Input: n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]
Output: 1
 
Constraints:
1 <= n <= 2000
1 <= edges.length <= 5000
edges[i].length == 2
0 <= ai <= bi < n
ai != bi
There are no repeated edges.

'''
'''
Complexity:-
TC :- O(V+E)
SC :- O(V+E)
'''
from collections import defaultdict
from collections import deque
def construct_graph(numList, edges):
    graph = defaultdict(set)
    for nums in numList:
        graph[nums[0]].add(nums[1])
        graph[nums[1]].add(nums[0])
    
    visited = [0*i for i in range(edges)]
    count = 0
    for i in range(edges):
        if visited[i] == 0:
            count += 1
            queue = deque()
            queue.append(i)
            while queue:
                index = queue.popleft()
                visited[index] = 1
                for nei in graph[index]:
                    if visited[nei] == 0:
                        queue.append(nei)
    return count

if __name__ == '__main__':
    print(construct_graph(numList=[[0,1],[1,2],[3,4]], edges = 5))
    print(construct_graph(numList = [[0,1],[1,2],[2,3],[3,4]], edges = 5))


