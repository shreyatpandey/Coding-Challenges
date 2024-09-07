'''
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-'
before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.
'''
'''
Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
Example 2:

Input: nums = [1], target = 1
Output: 1
'''
'''
Constraints:
1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000
'''
'''
TC:- O(2^n)
SC:-O(2^n)
'''
'''
Complexity:-
TC:- O(s.n)
SC:- O(s.n)
where s is the sum of the arrays and n is the length of the arrays
'''
class Solution(object):
    def findTargetSumWays(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        TotalSums = sum(nums)
        Memory= [[float('-inf') for i in range(2*TotalSums+1)]for j in range(len(nums))]
        
        def PartResult(index,partial_result):
            if index == len(nums):
                if partial_result == target:
                    return 1
                return 0
            
            if Memory[index][partial_result + TotalSums] != float('-inf') :
                return Memory[index][partial_result + TotalSums]
            
            count_add = PartResult(index+1,partial_result+nums[index])
            count_sub = PartResult(index+1,partial_result - nums[index])
            Memory[index][partial_result + TotalSums] = count_add + count_sub
            return Memory[index][partial_result + TotalSums]
        
        firstindex = 0
        partial_result = 0
        return PartResult(firstindex,partial_result)
