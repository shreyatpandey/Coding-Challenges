def shortest_path(graph):
    # go from top left to bottom right
    parents = [[0, 0]]
    result = [(0,0)]
    graph[0][0] = 1
    last_x = len(graph) - 1
    last_y = len(graph[0]) - 1
    n = len(graph)
    dirs = [(-1,-1),(-1,0),(0,-1),(1,0),(1,-1),(0,1),(-1,1),(1,1)]
    
    while parents:
        c = []
        best_diff = float('inf')
        add_to_result = None

        while parents:
            x, y = parents.pop()
            for row,col in dirs:
                x1 = x + row
                y1 = y + col
                
                if 0<= x1<n and 0<= y1<n and not graph[x1][y1]:
                    c.append([x1, y1])
                    graph[x1][y1] = 1
                    
                    diff = ((n-1) - x1) + ((n-1) - y1)
                    if diff < best_diff:
                        add_to_result = (x1,y1)
                        best_diff = diff

        parents.extend(c)
        if add_to_result:
            result.append(add_to_result)
    
    return result

test1 = [[0, 1], [1, 0]]
test2 = [[0, 0, 0], [1, 1, 0], [1, 1, 0]]
test3 = [[0, 0, 0], [1, 0, 0], [1, 1, 0]]

print(shortest_path(test1))
print(shortest_path(test2))
print(shortest_path(test3))