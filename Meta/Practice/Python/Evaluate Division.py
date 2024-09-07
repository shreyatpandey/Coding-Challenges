'''
We can treat each equation as an edge, variables as nodes and value as weight, and build a weighted graph. 
Then for each queries (x, y), we try to find a path from x to y. 
The answer is the product of all edges' weights. If either x or y is not in graph or x and y are not connected in graph, the answer doesn't exist.
We can use a defaultdict(dict) G to build a weighted graph and G[x][y] will be the weight of edge x->y which is the value of x / y

'''
'''
Complexity:
Given the number of variables N, and number of equations E,
building the graph takes O(E), each query takes O(N), space for graph takes O(E)

I think if we start to compress paths, the graph will grow to O(N^2), and we
can optimize the query to O(1)

'''
class Solution(object):
    def calcEquation(self, equations, values, queries):
        """
        :type equations: List[List[str]]
        :type values: List[float]
        :type queries: List[List[str]]
        :rtype: List[float]
        """
        graph = {}
        
        def build_graph(equations, values):
            def add_edge(f, t, value):
                if f in graph:
                    graph[f].append((t, value))
                else:
                    graph[f] = [(t, value)]
            
            for vertices, value in zip(equations, values):
                f, t = vertices
                add_edge(f, t, value)
                add_edge(t, f, 1/value)
        
        def find_path(query):
            b, e = query
            
            if b not in graph or e not in graph:
                return -1.0
                
            q = collections.deque([(b, 1.0)])
            visited = set()
            
            while q:
                front, cur_product = q.popleft()
                if front == e:
                    return cur_product
                visited.add(front)
                for neighbor, value in graph[front]:
                    if neighbor not in visited:
                        q.append((neighbor, cur_product*value))
            
            return -1.0
        
        build_graph(equations, values)
        return [find_path(q) for q in queries]
