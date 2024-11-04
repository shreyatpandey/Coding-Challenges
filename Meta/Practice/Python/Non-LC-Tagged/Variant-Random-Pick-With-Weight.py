'''
If you're given a list of countries and its corresponding population, write a function
that will return a random country but the higher the population of the country, the 
more likely it is to be picked at random.

string getRandomCountry(vector<pair<string,long>> populationperCountry);

e.g. ({USA,300m},{Russia,150m},{India,2B},{Spain,3B})

P(USA) = 2P(Russia)

P(India) = x*P(USA) where x= population of India/population of USA

'''
import random
class Solution:
    def __init__(self, input):
        """
        :type w: List[int]
        """
        self.input = input
        self.prefix_sums = []
	#this prefix_sums would be sorted, hence Binary Search could be applied
        prefix_sum = 0
        for weight in input:
            prefix_sum += weight[1]
            self.prefix_sums.append(prefix_sum)
        print("Sum :", self.prefix_sums)
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
        print("Country:", self.input[low][0])
        return low

if __name__ == '__main__' :
    print("T-1")
    input = [["USA",300],["Russia",15000000],["India",200000],["Spain",300000],["SriLanka",1000]]
    s = Solution(input)
    print(s.pickIndex())

'''
For every run , the output is the country with highest population
Usually Spain, or Russia as the population is increased
'''