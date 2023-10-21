'''
Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.
Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,4,7,5,3,6,8,9]
'''
'''
We also need to keep track of whether we're traversing top-right or bottom-left, and accordingly set the starting and ending cells in the addDiagonal function call.

The only tricky part is updating the boundaries after we've added a diagonal, but I think the code is self-explanatory.
'''

'''
Complexity:-
TC:- O(n*m)
SC:- O(n) for dict
'''
class Solution:
    def findDiagonalOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix or not matrix[0]:
            return []
        
        N= len(matrix)
        M= len(matrix[0])
        #res = [0]*(N*M)
        res = []
        Dict = OrderedDict() #here its Ordered and not UnOrdered as order for traverdsal has to be maintained
        for i in range(N):
            for j in range(M):
                Sum=i+j;
                if Sum not in Dict:
                    Dict[Sum] = []
                Dict[Sum].append(matrix[i][j])
        ctr=0
        for key,values in Dict.items():
            tempList = []
            if key%2 == 0:
                temp_list= values
                temp_list.reverse()
            else:
                temp_list = values
            for k in range(len(temp_list)):
                res.append(temp_list[k])
        
        return res

'''
Approach:- Simulation
Complexity:-
Tc:- O(n*m)
Sc:- O(1)
'''
class Solution:
    
    def findDiagonalOrder(self, matrix: List[List[int]]) -> List[int]:
        
        # Check for an empty matrix
        if not matrix or not matrix[0]:
            return []
        
        # The dimensions of the matrix
        N, M = len(matrix), len(matrix[0])
        
        # Incides that will help us progress through 
        # the matrix, one element at a time.
        row, column = 0, 0
        
        # As explained in the article, this is the variable
        # that helps us keep track of what direction we are
        # processing the current diaonal
        direction = 1
        
        # Final result array that will contain all the elements
        # of the matrix
        result = []
        
        # The uber while loop which will help us iterate over all
        # the elements in the array.
        while row < N and column < M:
            
            # First and foremost, add the current element to 
            # the result matrix. 
            result.append(matrix[row][column])
            
            # Move along in the current diagonal depending upon
            # the current direction.[i, j] -> [i - 1, j + 1] if 
            # going up and [i, j] -> [i + 1][j - 1] if going down.
            new_row = row + (-1 if direction == 1 else 1)
            new_column = column + (1 if direction == 1 else -1)
            
            # Checking if the next element in the diagonal is within the
            # bounds of the matrix or not. If it's not within the bounds,
            # we have to find the next head. 
            if new_row < 0 or new_row == N or new_column < 0 or new_column == M:
                
                # If the current diagonal was going in the upwards
                # direction.
                if direction:
                    
                    # For an upwards going diagonal having [i, j] as its tail
                    # If [i, j + 1] is within bounds, then it becomes
                    # the next head. Otherwise, the element directly below
                    # i.e. the element [i + 1, j] becomes the next head
                    row += (column == M - 1)
                    column += (column < M - 1)
                else:
                    
                    # For a downwards going diagonal having [i, j] as its tail
                    # if [i + 1, j] is within bounds, then it becomes
                    # the next head. Otherwise, the element directly below
                    # i.e. the element [i, j + 1] becomes the next head
                    column += (row == N - 1)
                    row += (row < N - 1)
                    
                # Flip the direction
                direction = 1 - direction        
            else:
                row = new_row
                column = new_column
                        
        return result                 
