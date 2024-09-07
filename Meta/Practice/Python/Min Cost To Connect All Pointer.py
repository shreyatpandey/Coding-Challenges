'''
You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: 
|xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.
'''
'''
Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation: 
'''
'''
Constraints:
1 <= points.length <= 1000
-10^6 <= xi, yi <= 10^6
All pairs (xi, yi) are distinct.
'''
'''
What is Prim's Algorithm?
Prim's Algorithm is another method for finding the Minimum Spanning Tree. 
It starts from an arbitrary node and greedily chooses the edge with the smallest weight that connects a visited and an unvisited node.

The Mechanics of Prim's Algorithm in "Min Cost to Connect All Points"
1. Initialize Priority Queue:
Start from an arbitrary point and initialize a minimum priority queue with its edges.
2. Visited Nodes Tracking:
Keep track of visited nodes to ensure that each node is visited exactly once.

3.Iterate and Add to MST:

Pop the edge with the smallest weight from the priority queue. If the edge leads to an unvisited node, add the edge's weight to the total MST weight, and insert all edges from that node into the priority queue.

4.Completion Check:
Continue this process until all nodes have been visited.
'''
'''
Approach:- Prim's Algorithm
TC:- O(n^2*log(n)), due to Priority Queue Operation
SC:- O(n), for storing the priority queue and visited nodes
'''
def manhattan_distance(p1: List[int], p2: List[int]) -> int:
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])

class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        visited = [False] * n
        heap_dict = {0: 0}  
        min_heap = [(0, 0)]
        
        mst_weight = 0
        
        while min_heap:
            w, u = heappop(min_heap)
            
            if visited[u] or heap_dict.get(u, float('inf')) < w:
                continue
            
            visited[u] = True
            mst_weight += w
            
            for v in range(n):
                if not visited[v]:
                    new_distance = manhattan_distance(points[u], points[v])
      
                    if new_distance < heap_dict.get(v, float('inf')):
                        heap_dict[v] = new_distance
                        heappush(min_heap, (new_distance, v))
        
        return mst_weight
'''
Kruskal's Algorithm is an algorithm to find the Minimum Spanning Tree of a graph. 
It sorts all the edges by weight and adds them one by one, checking that the addition of each edge doesn't form a cycle.

The Essence of Kruskal's Algorithm in "Min Cost to Connect All Points"
Initialize Edge List:
Calculate the Manhattan distance between all pairs of points to form an edge list.
Each edge is represented by a tuple (w, u, v), where w is the weight (Manhattan distance) and u and v are the nodes (points).

Sort the Edges:
Sort all edges by their weights. 
This helps us ensure that we're considering the smallest weight first, adhering to the "minimum" in Minimum Spanning Tree.

Union-Find for Connectivity:
Use a Union-Find data structure to keep track of connected components. 
This is crucial for efficiently checking whether adding a new edge would create a cycle.

Iterate and Add to MST:
Iterate through the sorted edge list, adding each edge to the Minimum Spanning Tree if it doesn't form a cycle.
Keep a counter of the number of edges added, and stop when you've added n−1n-1n−1 edges, where nnn is the number of nodes.
'''
'''
Approach:- Kruskal Algorithm
TC:- O(n^2*log(n)) , mainly due to sorting of edge list
SC:- O(n^2) , for sorting the edge-list and Union-Find data structure
'''
def manhattan_distance(p1: List[int], p2: List[int]) -> int:
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])

class UnionFind:
    def __init__(self, n):
        self.parent = [i for i in range(n)]
        self.rank = [0 for _ in range(n)]
        
    def find(self, u):
        if self.parent[u] == u:
            return u
        self.parent[u] = self.find(self.parent[u])
        return self.parent[u]
    
    def union(self, u, v):
        u = self.find(u)
        v = self.find(v)
        
        if u == v:
            return False
        
        if self.rank[u] > self.rank[v]:
            u, v = v, u
            
        self.parent[u] = v
        
        if self.rank[u] == self.rank[v]:
            self.rank[v] += 1
        
        return True

class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        uf = UnionFind(n)
        
        edges = []
        
        for i in range(n):
            for j in range(i+1, n):
                distance = manhattan_distance(points[i], points[j])
                heappush(edges, (distance, i, j))
        
        mst_weight = 0
        mst_edges = 0
        
        while edges:
            w, u, v = heappop(edges)
            if uf.union(u, v):
                mst_weight += w
                mst_edges += 1
                if mst_edges == n - 1:
                    break
                    
        return mst_weight


        
