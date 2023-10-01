'''
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
'''
'''
Constraints:
0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
'''
'''
Wording
here exists an obvious solution with sorting
And then correspondingly check the first four numbers
So [100,4,200,1,3,2] <-> [1,2,3,4,100,200]
And just check if the next integer is previous sum + 1
TC:- O(nlog(n))

Approach:-2
Most important to note that there is sequence
How can we start at the sequence?
What would be the start value of the sequence?
One way to check if the first value of the sequence has a left neighbor or not
So we need to figure which has left neighbor or not
Easiest way is to get the initial array and converting it into set
For 100, check if it has the left neighbor , so this becomes the
First element of the sequence
Count how many consecutive number come after 100
How can we check efficiently with the code?
1,2,3,4 100 200
100,4,200,1,3,2
100-> length 1
200->length 2
1 does not have left neighbor
1->2->3->4->length 4
Is 3 the start of sequence ? No

Just iterate through the initial array.
Just check if the first element of the sequence has left 
'''
'''
Complexity:
TC:- O(n)
SC:- O(n) 
where n is the length of input array
'''
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        numSet = set(nums)
        longest = 0
        for n in nums:
        # check if its start of a sequence
            if (n-1) not in numSet:
	            length = 0
	            while(n+length) in numSet: #Set is implemented as hashtable in python, lookup/add/search is in O(1) time
		            length += 1
	            longest = max(length, longest)
        return longest
