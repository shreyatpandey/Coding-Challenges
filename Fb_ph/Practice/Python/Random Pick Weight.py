# used for random number generation
import random

class Solution:
    def __init__(self, w: List[int]):
        self.w = w
		# 1. calculate relative frequency
        denom = sum(self.w)
        for i in range(len(self.w)):
            self.w[i] = self.w[i] / denom
        # 2. put relative frequencies on the number line between 0 and 1
		# Note self.w[-1] = 1
        for i in range(1,len(self.w)):
            self.w[i] += self.w[i-1]
        
    def pickIndex(self) -> int:
		
		# this is where we pick the index
        N = random.uniform(0,1)
      
        flag = 1
        index = -1
        
		# test each region of the numberline to see if N falls in it, if it 
		# does not then go to the next index and check if N falls in it
		# this is gaurenteed to break because of previous normalization
        while flag:
            index +=1 
           
           
     
            if N <= self.w[index]:
                flag = 0
        
    
        return index


'''
Pseudocode
1. Initialize class
2. Get a list of all unique values
3. normalize weights
4. put weights on the number line
5. If a uniform varialbe falls in the range of a value that value is returned
'''

'''
Time-Complexity:- 
For init - O(N)
For pickindex - O(Log(N))
'''
class Solution:
    def __init__(self, w: List[int]):
        """
        :type w: List[int]
        """
        self.prefix_sums = []
	#this prefix_sums would be sorted, hence Binary Search could be applied
        prefix_sum = 0
        for weight in w:
            prefix_sum += weight
            self.prefix_sums.append(prefix_sum)
        self.total_sum = prefix_sum
	#why do we use totalSum? I know this

    def pickIndex(self) -> int:
        """
        :rtype: int
        """
        target = self.total_sum * random.random()
        # run a binary search to find the target zone
        low, high = 0, len(self.prefix_sums)
        while low < high:
            mid = low + (high - low) // 2
            if target > self.prefix_sums[mid]:
                low = mid + 1
            else:
                high = mid
        return low
