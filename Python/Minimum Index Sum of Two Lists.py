'''
Approach-1 : Without Using Hash-Map
'''

class Solution(object):
    def findRestaurant(self, list1, list2):
        """
        :type list1: List[str]
        :type list2: List[str]
        :rtype: List[str]
        """
        CommonHotel = []
        LeastIndexSum = float('inf')
        for hotel in range(0,len(list1)):
            index = 0
            if list1[hotel] in list2 :
                index = list2.index(list1[hotel])
                if index+hotel <= LeastIndexSum :
                    LeastIndexSum = index+hotel
                    CommonHotel.append(list1[hotel])
        
        return CommonHotel
