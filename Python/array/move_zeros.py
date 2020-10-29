'''Solution-1'''
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        count_number_of_zeros = 0
        list_answer = []
        for i in range(0,len(nums)):
            if nums[i] == 0 :
                count_number_of_zeros += 1
            else:
                list_answer.append(nums[i])
                
        while (count_number_of_zeros > 0):
            list_answer.append(0)
            count_number_of_zeros -= 1
        
        for i in range(0,len(list_answer)):
            nums[i] = list_answer[i]
'''Solution-2'''
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        non_zero_elements = 0
        for i in range(0,len(nums)):
            if nums[i] != 0:
                nums[non_zero_elements] = nums[i]
                non_zero_elements += 1
        for i in range(non_zero_elements,len(nums)):
            nums[i] = 0
'''Solution-3'''
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        original_length = len(nums)
        count_number_of_zeros = 0
        for i in range(0,len(nums)):
            if nums[i] == 0:
                count_number_of_zeros += 1
            else:
                nums.append(nums[i])
        del nums[0:original_length]
        for i in range(0,count_number_of_zeros):
            nums.append(0)
      
