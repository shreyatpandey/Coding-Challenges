'''
Given two integer arrays nums1 and nums2, return an array of their intersection. 
Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
'''
'''
Constraints:
1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
'''
''''
 Approach 1: HashMap

Using HashMap to store occurrences of elements in the nums1 array.
Iterate x in nums2 array, check if cnt[x] > 0 then append x to our answer and decrease cnt[x] by one.
To optimize the space, we ensure len(nums1) <= len(nums2) by swapping nums1 with nums2 if len(nums1) > len(nums2).
'''
from collections import Counter
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        if len(nums1) > len(nums2): return self.intersect(nums2, nums1)
            
        cnt = Counter(nums1)
        ans = []
        for x in nums2:
            if cnt[x] > 0:
                ans.append(x)
                cnt[x] -= 1
        return ans
''''
Complexity:

Time: O(M + N), where M <= 1000 is length of nums1 array, N <= 1000 is length of nums2 array.
Space: O(min(M, N))
'''
'''
✔️ Approach 2: Sort then Two Pointers
'''

class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1.sort()
        nums2.sort()
        
        ans = []
        i = j = 0
        while i < len(nums1) and j < len(nums2):
            if nums1[i] < nums2[j]:
                i += 1
            elif nums1[i] > nums2[j]:
                j += 1
            else:
                ans.append(nums1[i])
                i += 1
                j += 1
        return ans

'''
Complexity:

Time: O(MlogM + NlogN), where M <= 1000 is length of nums1 array, N <= 1000 is length of nums2 array.
Extra Space (without counting output as space): O(sorting)
'''
'''
✔️ Follow-up Question 1: What if the given array is already sorted? How would you optimize your algorithm?

Approach 2 is the best choice since we skip the cost of sorting.
So time complexity is O(M+N) and the space complexity is O(1).
✔️ Follow-up Question 2: What if nums1's size is small compared to nums2's size? Which algorithm is better?

Approach 1 is the best choice.
Time complexity is O(M+N) and the space complexity is O(M), where M is length of nums1, N is length of nums2.
✔️ Follow-up Question 3: 
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

If nums1 fits into the memory, we can use Approach 1 which stores all elements of nums1 in the HashMap. 
Then, we can sequentially load and process nums2.
If neither nums1 nor nums2 fits into the memory, we split the numeric range into numeric sub-ranges that fit into the memory.
We modify Approach 1 to count only elements which belong to the given numeric sub-range.
We process each numeric sub-ranges one by one, util we process all numeric sub-ranges.
For example:
Input constraint:
1 <= nums1.length, nums2.length <= 10^10.
0 <= nums1[i], nums2[i] < 10^5
Our memory can store up to 1000 elements.
Then we split numeric range into numeric sub-ranges [0...999], [1000...1999], ..., [99000...99999],
then call Approach 1 to process 100 numeric sub-ranges.
'''