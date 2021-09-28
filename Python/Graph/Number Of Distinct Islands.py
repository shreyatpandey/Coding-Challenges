'''
TC:- O(m*n)
SC:- O(N)
Faster than 98.94% for Python Solution
Approach:- BFS
'''

def NumberOfDistinctIslands(grid):
    rowLength = len(grid)
    colLength = len(grid[0])
    
    seen = set()
    unique_island = set()
    for row in range(0,rowLength):
        for col in range(0,colLength):
            if grid[row][col] == 1 and (row,col) not in seen: 
                rowOrigin = row
                colOrigin = col

                queue = []
                queue.append((row,col))
                seen.add((row,col))
                current_islands = set()
                while len(queue):
                    coordinates = queue[0]
                    del queue[0]
                    x_ = coordinates[0]
                    y_ = coordinates[1]
                    
                    current_islands.add((x_-rowOrigin,y_-colOrigin))
                    
                    if x_+1<rowLength and grid[x_+1][y_]==1 and (x_+1,y_) not in seen:
                        queue.append((x_+1,y_))
                        seen.add((x_+1,y_))
                    
                    if x_>0 and grid[x_-1][y_] == 1 and (x_-1,y_) not in seen:
                        queue.append((x_-1,y_))
                        seen.add((x_-1,y_))
                    
                    if y_+1<colLength and grid[x_][y_+1] == 1 and (x_,y_+1) not in seen:
                        queue.append((x_,y_+1))
                        seen.add((x_,y_+1))
                    
                    if y_>0 and grid[x_][y_-1] == 1 and (x_,y_-1) not in seen:
                        queue.append((x_,y_-1))
                        seen.add((x_,y_-1))
                if current_islands :
                    unique_island.add(frozenset(current_islands))
    
    return len(unique_island)
