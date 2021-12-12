class Solution(object):
    def waysToSplit(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        lenNum = len(nums)
        prefixSum = [0 * i for i in range(0,len(nums))]
        prefixSum[0] = nums[0]
        modulo = int(1e9+7)
        for i in range(1,len(nums)):
            prefixSum[i] = prefixSum[i-1] + nums[i]

        answer = 0
        for i in range(0,lenNum):
            prev = prefixSum[i]
            if prev*3 > prefixSum[-1]:
                break;
            
            leftIndex = bisect.bisect_left(prefixSum,prev*2,i+1,lenNum)
            middle = (prev + prefixSum[-1])//2
            rightIndex = bisect.bisect_right(prefixSum,middle,leftIndex+1,lenNum)
            
            if rightIndex-1>=lenNum or prefixSum[rightIndex-1]> middle:
                continue;
            answer = (answer + min(rightIndex,lenNum-1)-leftIndex)%modulo
            
        
        return answer
