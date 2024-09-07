'''
You have a graph of n nodes labeled from 0 to n - 1. You are given an integer n and a list of edges where edges[i] = [ai, bi] 
indicates that there is an undirected edge between nodes ai and bi in the graph.

Return true if the edges of the given graph make up a valid tree, and false otherwise.
 '''
'''
Input: n = 5, edges = [[0,1],[0,2],[0,3],[1,4]]
Output: true
'''
'''
## TIME COMPLEXITY : O(N) ##
## SPACE COMPLEXITY : O(N) ##
'''
class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
         ## RC ##
        ## APPROACH : GRAPH / DFS ##
        # Detect cycle in UN-DIRECTED Graph ##
		
        def detect_cycle(node, visited, parent):
            visited.add(node)
            for child in graph[node]:
                if(child == parent): continue
                if(child in visited or detect_cycle(child, visited, node)):         # Current node is now parent
                        return True
            return False       
        
        if(n <= 0 or len(edges) != n - 1): return False
        graph = collections.defaultdict(list)
        for u, v in edges:
            graph[u].append(v)              
            graph[v].append(u)           
        visited = set()
        if(detect_cycle(0, visited, -1)):      # Initially starting with parent -1
            return False                       # If cycle is detected directly return False
        return len(visited) == n               # No Cycle and all edges are in the graoh, then it is tree.
