'''
You are given a nested list of integers nestedList. Each element is either an integer or a list whose elements may also be integers or other lists.

The depth of an integer is the number of lists that it is inside of. 
For example, the nested list [1,[2,2],[[3],2],1] has each integer's value set to its depth. Let maxDepth be the maximum depth of any integer.

The weight of an integer is maxDepth - (the depth of the integer) + 1.

Return the sum of each integer in nestedList multiplied by its weight.
'''
'''
Here the max depth is obtained by the formula:- maxDepth = Depth - 1

'''
'''
Input: nestedList = [1,[4,[6]]]
Output: 17
Explanation: One 1 at depth 3, one 4 at depth 2, and one 6 at depth 1.
1*3 + 4*2 + 6*1 = 17
'''
'''
Double Pass BFS

'''
class Solution:
    def depthSumInverse(self, nestedList: List[NestedInteger]) -> int:
        queue = deque(nestedList)
        maxWeight = 0
        Depth = 1
        maxDepth = 0
        while len(queue)>0:
            Length = len(queue)
            for i in range(Length):
                nested = queue.pop()
                if nested.isInteger() == False:
                    queue.extendleft(nested.getList())
            Depth += 1
        
        maxDepth = Depth-1
        #print(maxDepth)
        queue = deque(nestedList)
        Depth = 1
        totalSum = 0
        while len(queue)>0:
            Length = len(queue)
            for i in range(Length):
                nested = queue.pop()
                if nested.isInteger() :
                    diff = maxDepth - (Depth)+1
                    totalSum += diff*nested.getInteger()
                else:
                    queue.extendleft(nested.getList())
            Depth += 1
        
        return totalSum
