'''
There is a brick wall in front of you. The wall is rectangular and has several rows of bricks. 
The bricks have the same height but different width. 
You want to draw a vertical line from the top to the bottom and cross the least bricks.
The brick wall is represented by a list of rows. Each row is a list of integers representing the width of each brick in this row from left to right.
If your line go through the edge of a brick, then the brick is not considered as crossed. 
You need to find out how to draw the line to cross the least bricks and return the number of crossed bricks.
'''
class Solution(object):
    def leastBricks(self, wall):
        """
        :type wall: List[List[int]]
        :rtype: int
        """
        BrickHashTable = {}
        for row in range(0,len(wall)) :
            SumWidth = 0
            for col in range(0,len(wall[row])-1) :
                SumWidth += wall[row][col] 
                if SumWidth in BrickHashTable :
                    BrickHashTable[SumWidth] = BrickHashTable[SumWidth] + 1
                else:
                    BrickHashTable[SumWidth] = 1
        result = len(wall)
        for keys,values in BrickHashTable.items() :
            result = min(result,len(wall) - values) ;
        
        return result
            
        
        
