
# Solution in 0(n^2)
class Solution(object):
	def twoSum(self,nums,target):
		length = len(nums)
		for i in range(0,length):
			for j in range(i+1,length):
				if (nums[j] == (target - nums[i])):
					return [nums[i],nums[j]];

solution1 = Solution()
# since the function is returning multiple values use a list
list = solution1.twoSum([2,7,11,15],9)
print(list)

 
