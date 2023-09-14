'''
You are given a 0-indexed array of positive integers w where w[i] describes the weight of the ith index.

You need to implement the function pickIndex(), 
which randomly picks an index in the range [0, w.length - 1] (inclusive) and returns it. 
The probability of picking an index i is w[i] / sum(w).

For example, if w = [1, 3], the probability of picking index 0 is 1 / (1 + 3) = 0.25 (i.e., 25%), and 
the probability of picking index 1 is 3 / (1 + 3) = 0.75 (i.e., 75%).
 

Example 1:

Input
["Solution","pickIndex"]
[[[1]],[]]
Output
[null,0]

Explanation
Solution solution = new Solution([1]);
solution.pickIndex(); // return 0. The only option is to return 0 since there is only one element in w.
'''

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
Prefix Sum - Key Word that needs to be maintained and then we can perform Binary Search on them
Take small example like:- [1,3]
Selecting 1 <-> 1/4 = 25 %
Selecting 3 <-> 3/4 = 75%
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
