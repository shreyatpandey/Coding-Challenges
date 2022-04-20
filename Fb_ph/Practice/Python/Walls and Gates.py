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
   '''
  class Solution(object):
    def wallsAndGates(self, rooms):
        """
        :type rooms: List[List[int]]
        :rtype: None Do not return anything, modify rooms in-place instead.
        """
        if not rooms:
            return
        
        h = len(rooms)
        w = len(rooms[0])
        
        q = []
        for i in range(h):
            for j in range(w):
                if rooms[i][j] == 0:
                    q.append((i,j))
        
        for row, col in q:
            dist = rooms[row][col] + 1
            for dy, dx in (-1, 0), (1, 0), (0, -1), (0, 1):
                r = row + dy
                c = col + dx
                if 0 <= r < h and 0 <= c < w and rooms[r][c] == 2147483647:
                    rooms[r][c] = dist
                    q.append((r,c))
