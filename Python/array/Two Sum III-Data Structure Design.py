'''
Approach-1:- Using Set , not hash map as we have to return values not Indices
Time-Complexity:- O(N)
Space-Complexity:- O(N) for Set
'''
class TwoSum(object):

    def __init__(self):
        self.list = []
        
        

    def add(self, number):
        """
        :type number: int
        :rtype: None
        """
        self.list.append(number)
        

    def find(self, value):
        """
        :type value: int
        :rtype: bool
        """
        Set = set()
        for index,val in enumerate(self.list):
            if  value - val in Set:
                return True
            Set.add(val)
        return False
    
    '''
    Approach-2:- Sorting, as we have to return values and not indices 
    Time-Complexity:- O(nlog(n))
    Space-Complexity:- O(1)
    '''
    class TwoSum(object):

    def __init__(self):
        self.list = []
        
        

    def add(self, number):
        """
        :type number: int
        :rtype: None
        """
        self.list.append(number)
        

    def find(self, value):
        """
        :type value: int
        :rtype: bool
        """
        #Set = set()
        '''
        for index,val in enumerate(self.list):
            if  value - val in Set:
                return True
            Set.add(val)
        '''
        self.list.sort()
        startIndex = 0
        finalIndex = len(self.list)-1
        while startIndex < finalIndex:
            if self.list[startIndex] + self.list[finalIndex] == value :
                return True
            elif self.list[startIndex] + self.list[finalIndex] < value :
                startIndex += 1
            else:
                finalIndex -= 1
        
        return False
        


# Your TwoSum object will be instantiated and called as such:
# obj = TwoSum()
# obj.add(number)
# param_2 = obj.find(value)
