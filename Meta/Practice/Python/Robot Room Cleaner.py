'''
You are controlling a robot that is located somewhere in a room. 
The room is modeled as an m x n binary grid where 0 represents a wall and 1 represents an empty slot.

The robot starts at an unknown location in the room that is guaranteed to be empty, 
and you do not have access to the grid, but you can move the robot using the given API Robot.

You are tasked to use the robot to clean the entire room (i.e., clean every empty cell in the room). 
The robot with the four given APIs can move forward, turn left, or turn right. Each turn is 90 degrees.

When the robot tries to move into a wall cell, its bumper sensor detects the obstacle, and it stays on the current cell.

Design an algorithm to clean the entire room using the following APIs:

interface Robot {
  // returns true if next cell is open and robot moves into the cell.
  // returns false if next cell is obstacle and robot stays on the current cell.
  boolean move();

  // Robot will stay on the same cell after calling turnLeft/turnRight.
  // Each turn will be 90 degrees.
  void turnLeft();
  void turnRight();

  // Clean the current cell.
  void clean();
  
Constraints:
m == room.length
n == room[i].length
1 <= m <= 100
1 <= n <= 200
room[i][j] is either 0 or 1.
0 <= row < m
0 <= col < n
room[row][col] == 1
All the empty cells can be visited from the starting position.
}
'''
# """
# This is the robot's control interface.
# You should not implement it, or speculate about its implementation
# """
#class Robot:
#    def move(self):
#        """
#        Returns true if the cell in front is open and robot moves into the cell.
#        Returns false if the cell in front is blocked and robot stays in the current cell.
#        :rtype bool
#        """
#
#    def turnLeft(self):
#        """
#        Robot will stay in the same cell after calling turnLeft/turnRight.
#        Each turn will be 90 degrees.
#        :rtype void
#        """
#
#    def turnRight(self):
#        """
#        Robot will stay in the same cell after calling turnLeft/turnRight.
#        Each turn will be 90 degrees.
#        :rtype void
#        """
#
#    def clean(self):
#        """
#        Clean the current cell.
#        :rtype void
#        """
'''
Complexity:-
TC:- At each cell we do 4 direction check 
SC:- O(N) for the recursion stack for backtracking

'''
'''
Wording:-
In goBack()
->Either turnLeft() or turnRight() could be used? But it should be done twice to change the direction through 180 degree
->We are rotating robot clockwise the direction[coordinates] of directions would matter
'''
class Solution:
    def cleanRoom(self, robot):
        """
        :type robot: Robot
        :rtype: None
        """
        def go_back():
            robot.turnLeft()
            robot.turnLeft()
            #Robot will turn twice why?
            #to get back to the original directions
            robot.move()
            robot.turnLeft()
            robot.turnLeft()
            
        def backtrack(cell, d):
            robot.clean()
            # going clockwise : 0: 'up', 1: 'right', 2: 'down', 3: 'left'
            for i in range(4):
                new_d = (d + i) % 4 #why %4 , to make robot in the range of [0,3]
                new_cell = (cell[0] + directions[new_d][0], 
                            cell[1] + directions[new_d][1])
                
                if not new_cell in visited and robot.move(): #why robot.move() because it helps check the boundaries of the coordinate
                    visited.add(new_cell)
                    backtrack(new_cell, new_d)
                    go_back() #if we dont do go_back() say if the robot is at the edge/boundary then it needs to come back and then try different direction
                # turn the robot following chosen direction : clockwise
                robot.turnLeft()
    
        # going clockwise : 0: 'up', 1: 'right', 2: 'down', 3: 'left'
        directions = [(-1, 0), (0, 1), (1, 0), (0, -1)] # the sequence of the directions does matter
        visited = set() #record the cell which has been visited
        initialCor = (0,0) #starting point does really matter, for our own convenience we choose (0,0)
        distance = 0
        visited.add(initialCor)
        backtrack(initialCor,distance)
