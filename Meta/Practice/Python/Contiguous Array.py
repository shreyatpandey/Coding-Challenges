'''
Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.
Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
'''
'''
Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
'''
'''
Verbatim explanation:- 
1.we are going to use hash map  to store the count of 0 and 1
2.we are going to declare a variable max_len and count assign it to 0
3.we are going to use a for loop to iterate through the array
4.if the current number is 0 then we will decrement the count by 1
5.if the current number is 1 then we will increment the count by 1
6. we are going to check that our count is equal to 0  are not if it 0 then we will make our max_len equal to i+1 .
let me explain you why so keep following the logic.
7. we are going to update our count to our hash .if it was already in the hash we will compare the value of the hash with max_len and if it is greater than max_len then we will update max_len to the value of the hash
if it was not there we will add the count to the hash
  key --> count
  value --> index
8. we are going to return max_len
'''

'''
Complexity
Tc:- O(n)
Sc:- O(n)
for the hash Map
'''
class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        max_length =0
        hash={}
        count=0
        for i in range(len(nums)):
            current=nums[i]
            if current==0:
                count-=1 # decrement our count if our current element is 0
            else:
                # increment our count if current element is 1
             count+=1

            if count==0:
                # if count is 0, we have a new subarray with length+1
                max_length=i+1
            if count in hash:
                max_length=max(max_length,i-hash[count]) 
            else:
                hash[count]=i
        return max_length
