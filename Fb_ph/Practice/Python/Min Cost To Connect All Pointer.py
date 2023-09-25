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

        
