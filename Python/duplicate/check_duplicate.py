'''Solution-1'''
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        dict_duplicates ={}
        for i in range(0,len(nums)):
            if nums[i] in dict_duplicates:
                return True;
            else:
                dict_duplicates[nums[i]] = 1
        
        return False;

'''Solution-2'''
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        return True if len(nums)>len(set(nums)) else False
        
