'''
Given an integer array nums and an integer k,
return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
'''
'''
Constraints:
1 <= nums.length <= 10^5
-109 <= nums[i] <= 10^9
0 <= k <= 10^5
'''
'''
TC:- O(n)
SC:- O(min(n,k))
the extra space depends on the number of items sorted in the hash table
which is the size of sliding window <=> min(n,k)
'''
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        hashSet = set()
        for index in range(len(nums)):
            if nums[index] in hashSet:
                return True
            hashSet.add(nums[index])
            if len(hashSet) > k:
                hashSet.remove(nums[index-k])
        return False

class Solution:
    def containsNearbyDuplicate(self, nums, k):
        hashSet = set()
        for index in range(len(nums)):
            if nums[index] in hashSet:
                return True
            hashSet.add(nums[index])
            if len(hashSet) > k:
                hashSet.remove(nums[index-k])
        return False

if __name__ == '__main__':
    print("Test Case - 1")
    nums = [1,2,3,1]
    k = 3
    s = Solution()
    print("1:",s.containsNearbyDuplicate(nums,k))
    nums = [1,2,3,4,1]
    k = 3
    print("2:", s.containsNearbyDuplicate(nums,k))
    nums = [1,2,3]
    k = 2
    print("3:", s.containsNearbyDuplicate(nums,k))
