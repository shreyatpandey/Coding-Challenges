import heapq
class Solution(object):
    def minDeletions(self, s):
        """
        :type s: str
        :rtype: int
        """
        freqMap = {}
        maxheap = []
        ans = 0
        for char in s:
            if char not in freqMap : freqMap[char] = 1
            else : freqMap[char] += 1
        for key,val in freqMap.items():
            heapq.heappush(maxheap,-val)
        
        while len(maxheap)>0:
            currentFreq = heapq.heappop(maxheap)
            if len(maxheap) == 0: return ans
            if currentFreq  == maxheap[0]:
                if currentFreq + 1 < 0 :
                    heapq.heappush(maxheap,currentFreq+1)
                ans += 1
        return ans
