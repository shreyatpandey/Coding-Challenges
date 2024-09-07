'''
This question is about implementing a basic elimination algorithm for Candy Crush.

Given an m x n integer array board representing the grid of candy where board[i][j] represents the type of candy. 
A value of board[i][j] == 0 represents that the cell is empty.

The given board represents the state of the game following the player's move. 
Now, you need to restore the board to a stable state by crushing candies according to the following rules:
  If three or more candies of the same type are adjacent vertically or horizontally, crush them all at the same time - these positions become empty.
  After crushing all candies simultaneously, if an empty space on the board has candies on top of itself, 
  then these candies will drop until they hit a candy or bottom at the same time. No new candies will drop outside the top boundary.
  After the above steps, there may exist more candies that can be crushed. If so, you need to repeat the above steps.
  If there does not exist more candies that can be crushed (i.e., the board is stable), then return the current board.

You need to perform the above rules until the board becomes stable, then return the stable board.

'''
'''
For each round, we should detect candies to crush first, crush them, and drop candies to restore the board

Three steps:

getCandiesToCrush() helps build List<int[]> candyToCrush which saves coordinates of candies to crush in the current round.
we elimate candies to crush together using eliminateCandies().
we restore the board to a stable state by dropCandies().
We follow the pattern described above round by round until candyToCrush is empty.

Within dropCandies, we drop candies column by column with two pointers top, bottom .
They start at board.length - 1 initially.
top keeps going up until find a candy to drop, and then we drop the candy to bottom and increase bottom, top keeps going up ...
'''
'''
Complexity:-
TC:- O((R*C)^2) , 
SC:- O(1) , we edit the board in place
'''

class Solution(object):
    def candyCrush(self, board):
        """
        :type board: List[List[int]]
        :rtype: List[List[int]]
        """
        m, n = len(board) , len(board[0])
        candyToCrush = []
        
        def eliminatesCandies():
            for entries in candyToCrush:
                board[entries[0]][entries[1]] = 0
        
        
        def dropCandies():
            for j in range(n):
                top = bottom = m-1
                while top>=0:
                    if board[top][j] != 0:
                        board[bottom][j] = board[top][j]
                        bottom -= 1
                    top -= 1
                while bottom >=0 :
                    board[bottom][j] = 0
                    bottom -= 1
        
        def getCandiesToCrush(row,col,index):
            if row + 2 < m and index == board[row + 1][col] and index == board[row + 2][col]:
                candyToCrush.append((row,col))
                candyToCrush.append((row + 1, col))
                candyToCrush.append((row + 2, col))
        
            if col + 2 < n and index == board[row][col + 1] and index == board[row][col + 2] :
                candyToCrush.append((row,col))
                candyToCrush.append((row, col + 1))
                candyToCrush.append((row, col + 2))
        
        
        
        for row in range(0,m):
            for col in range(0,n):
                if board[row][col] != 0:
                    getCandiesToCrush(row,col,board[row][col])
        
        if not candyToCrush:
            return board
        
        eliminatesCandies()
        dropCandies()
        
        return self.candyCrush(board)
    
        
