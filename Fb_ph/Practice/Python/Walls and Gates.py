'''
You are given an m x n grid rooms initialized with these three possible values.

-1 A wall or an obstacle.
0 A gate.
INF Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. 
If it is impossible to reach a gate, it should be filled with INF.

'''
'''
Constraints:
m == rooms.length
n == rooms[i].length
1 <= m, n <= 250
rooms[i][j] is -1, 0, or 231 - 1.
'''


'''
This Approach is not working, this might be correct
Approach:- BFS
TC:- O(m+n)
SC:- O(n) for the queue
'''
class Solution(object):
    def wallsAndGates(self, rooms):
        rowLen = len(rooms)
        colLen = len(rooms[0])
        if not rooms:
            return
        Queue = deque()
        dirs = [(-1,0),(0,1),(0,-1),(1,0)] #reason for not including {-1,-1} or {1,1} is that diagonal traversal is not allowed
        for row in range(rowLen):
            for col in range(colLen):
                if rooms[row][col] == 0: #reason for starting with Gate
                    #BFS - Traversal
                    Queue.append((row,col))
            
        while Queue:
            x_,y_ = Queue.popleft()
            for i,j in dirs:
                xcor_ = x_ + i
                ycor_ = y_ + j
                #Boundary-Check
                if xcor_ < 0 or xcor_ >=rowLen or ycor_ < 0 or ycor_ >=colLen or rooms[xcor_][ycor_] != float('inf'):
                    continue
                #if 0<=xcor_<rowLen and 0<=ycor_<colLen and rooms[xcor_][ycor_] == float('inf'):
                rooms[xcor_][ycor_] = rooms[x_][y_] + 1
                Queue.append((xcor_,ycor_))
'''
This Approach is working instead of deque
TC:- O(mn)
he breadth-first search takes at most m \times nm×n steps to reach all rooms, therefore the time complexity is O(mn)O(mn). 
But what if you are doing breadth-first search from kk gates?

Once we set a room's distance, we are basically marking it as visited, which means each room is visited at most once. 
Therefore, the time complexity does not depend on the number of gates and is O(mn)
SC:- O(mn) for the queue 
'''
  class Solution(object):
    def wallsAndGates(self, rooms):
        """
        :type rooms: List[List[int]]
        :rtype: None Do not return anything, modify rooms in-place instead.
        """
        if not rooms:
            return
        
        rowLen = len(rooms)
        colLen = len(rooms[0])
        dirs = [(-1,0),(1,0),(0,-1),(0,1)]
        Queue = []
        for i in range(rowLen):
            for j in range(colLen):
                if rooms[i][j] == 0:
                    Queue.append((i,j))
        
        for row, col in Queue:
            dist = rooms[row][col] + 1
            for dy, dx in dirs:
                r = row + dy
                c = col + dx
                if 0 <= r < rowLen and 0 <= c<colLen and rooms[r][c] == 2147483647:
                    rooms[r][c] = dist
                    Queue.append((r,c))
