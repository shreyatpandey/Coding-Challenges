'''
Approach-1:
TC:- O(Len(Dictionary))
SC:- O(Dictionary)
More memory efficient as we are storing non zero values
What if hash function sucks/bad?
This isnt also the best solution
'''
class SparseVector:
    def __init__(self, nums: List[int]):
        self.nums = {i: n for i, n in enumerate(nums) if n}

    def dotProduct(self, vec: 'SparseVector') -> int:
        result = 0
        if len(self.nums) < len(vec.nums):
            for key in self.nums.keys():
                if key in vec.nums:
                    result += self.nums[key] * vec.nums[key]
        else:
            for key in vec.nums.keys():
                if key in self.nums:
                    result += self.nums[key] * vec.nums[key]
                    
        return result

    '''
    Approach-2:
    Without HashMap
    FB interview accept this solution
    -Just going by the formula and without doing any prepocessing like whether elements are 0 or not
    TC:- O(n) for the result of calculating dot product or vector
    SC:- O(1) 
    '''
    class SparseVector:
        def __init__(self, nums):
            self.array = nums

        def dotProduct(self, vec):
            result = 0
            for num1, num2 in zip(self.array, vec.array):
                result += num1 * num2
            return result
     
'''
Approach-3:
Most Optimal Way
Tuple Solution
Its combination of Approach 1 + 2
We need to use Hash Map along with Tuple
When we are calculating dot product we would use two pointer 
TC:- O(n)
SC:- O(n)
'''
class Solution(object):
    def __init__(self,nums):
        self.nums = []
        for i,num in enumerate(nums):
            if num:
                self.nums.append((i,num))
    def dotProdut(Self,vec):
        DotProduct = 0
        i,j = 0,0
        while i<len(self.nums) and j<len(vec.nums):
            i_idx,i_num = self.nums[i]
            j_idx,j_num = vec.nums[j]
            if i_idx == j_idx:
                DotProduct += (i_num*j_num)
                i += 1
                j += 1
            elif i_idx > j_idx:
                j += 1
            else:
                i += 1
        return DotProduct
     
