'''
Given a 2D integer array nums where nums[i] is a non-empty array of distinct positive integers, 
return the list of integers that are present in each array of nums sorted in ascending order.
 
Example 1:

Input: nums = [[3,1,2,4,5],[1,2,3,4],[3,4,5,6]]
Output: [3,4]
Explanation: 
The only integers present in each of nums[0] = [3,1,2,4,5], nums[1] = [1,2,3,4], and nums[2] = [3,4,5,6] are 3 and 4, so we return [3,4].
'''
'''
Constraints:

1 <= nums.length <= 1000
1 <= sum(nums[i].length) <= 1000
1 <= nums[i][j] <= 1000
All the values of nums[i] are unique.
'''

'''
Complexity:-
TC:- O(nlog(n)) to return sorted array
SC:- O(n) for frequencyCounter Map
'''
class Solution:
    def intersection(self, nums: List[List[int]]) -> List[int]:
        countFreq = {}
        Result =[]
        for listNumber in nums:
            for num in listNumber:
                countFreq[num] = countFreq.get(num,0) + 1
        for keys,values in countFreq.items():
            if values == len(nums):
                Result.append(keys)

        return sorted(Result)
