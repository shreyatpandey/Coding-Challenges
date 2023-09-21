'''
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.
Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
'''
'''
Constraints:

0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
'''
'''
Complexity:-
TC:- O(n)
Although the time complexity appears to be quadratic due to the while
loop nested within the for loop, closer inspection reveals it to be
linear. Because the while loop is reached only when currentNum marks
the beginning of a sequence (i.e. currentNum-1 is not present in
nums)
SC:- O(n) allocation for hash table to store O(n) numbers in nums
'''
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        longest_streak = 0
        num_set = set(nums)

        for num in num_set:
            if num - 1 not in num_set:
                current_num = num
                current_streak = 1

                while current_num + 1 in num_set:
                    current_num += 1
                    current_streak += 1

                longest_streak = max(longest_streak, current_streak)

        return longest_streak
