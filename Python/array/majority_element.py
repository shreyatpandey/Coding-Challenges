class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        dict_count = {}
        for i in range(0,len(nums)):
            if nums[i] in dict_count:
                dict_count[nums[i]] += 1
            else:
                dict_count[nums[i]] = 1
        for (key,values) in dict_count.items():
            if values >= len(nums)/2:
                return key
