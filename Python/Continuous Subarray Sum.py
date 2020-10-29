class Solution(object):
    def checkSubarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        check_subarray_sum = {0:-1}
        sum_subarray = 0
        for i,num in enumerate(nums):
            if k:
                sum_subarray = (sum_subarray + num)%k
            else:
                sum_subarray += num
            if sum_subarray not in check_subarray_sum:
                check_subarray_sum[sum_subarray] = i
            else:
                if i - check_subarray_sum[sum_subarray] >= 2:
                    return True
        return False
        
        
        
