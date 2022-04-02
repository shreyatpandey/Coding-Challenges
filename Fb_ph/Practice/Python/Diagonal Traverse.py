'''
We also need to keep track of whether we're traversing top-right or bottom-left, 
and accordingly set the starting and ending cells in the addDiagonal function call.

The only tricky part is updating the boundaries after we've added a diagonal, but I think the code is self-explanatory.
'''

'''
TC:- O(n*m)
SC:- O(1)
'''

class Solution:
    def findDiagonalOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix or not matrix[0]:
            return []

        result = []
        row, col, d = 0, 0, 0
        dirs = [(-1, 1), (1, -1)]

        for i in range(len(matrix) * len(matrix[0])):
            result.append(matrix[row][col])
            row += dirs[d][0]
            col += dirs[d][1]

            if row >= len(matrix):
                row = len(matrix) - 1
                col += 2
                d = 1 - d
            elif col >= len(matrix[0]):
                col = len(matrix[0]) - 1
                row += 2
                d = 1 - d
            elif row < 0:
                row = 0
                d = 1 - d
            elif col < 0:
                col = 0
                d = 1 - d

        return result
    
 '''
 Approach-2: Using Map
 TC:- O(n*m)
 SC:- O(n) for the map
 '''
class Solution:
    def findDiagonalOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix or not matrix[0]:
            return []
        
        N= len(matrix)
        M= len(matrix[0])
        res = []
        Dict = OrderedDict() #here its Ordered and not UnOrdered as order for traverdsal has to be maintained
        for i in range(N):
            for j in range(M):
                Sum=i+j;
                if Sum not in Dict:
                    Dict[Sum] = []
                Dict[Sum].append(matrix[i][j])
     
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
