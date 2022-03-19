'''
TC:- O(Len(Dictionary))
SC:- O(Dictionary)
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
    Without HashMap
    FB interview accept this solution
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
