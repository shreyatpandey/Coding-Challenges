from collections import defaultdict
def noOfConnectedComponents(n,edges):
    graph = defaultdict(set)
    for edg in edges:
        graph[edg[0]].add(edg[1])
        graph[edg[1]].add(edg[0])
    
    seen= [0 for i in range(n)]
    queue = []
    noOfConnectedComponents = 0
    for i in range(0,n):
        if seen[i] == 0:
            noOfConnectedComponents += 1
            queue.append(i)
            seen[i] == 1
            while len(queue) != 0:
                current = queue[0]
                del queue[0]
                seen[current] = 1
                for edg in graph[current]:
                    if seen[edg] == 0:
                        queue.append(edg)
    
    return noOfConnectedComponents

if __name__ == '__main__':
    edges = [[0,1],[1,2],[2,3],[3,4]]
    print(noOfConnectedComponents(5,edges))
    edges = [[0,1],[1,2],[3,4]]
    print(noOfConnectedComponents(5,edges))
