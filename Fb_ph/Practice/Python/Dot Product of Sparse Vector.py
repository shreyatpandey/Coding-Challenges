'''
TC:- O(Len(Dictionary))
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
