'''
Given a binary array nums, return the maximum number of consecutive 1's in the array if you can flip at most one 0.

Example 1:

Input: nums = [1,0,1,1,0]
Output: 4
Explanation: 
- If we flip the first zero, nums becomes [1,1,1,1,0] and we have 4 consecutive ones.
- If we flip the second zero, nums becomes [1,0,1,1,1] and we have 3 consecutive ones.
The max number of consecutive ones is 4.
'''
'''
Q] 
Follow up: What if the input numbers come in one by one as an infinite stream? 
In other words, you can't store all numbers coming from the stream as it's too large to hold in memory. 
Could you solve it efficiently?
Ans:- 
public int findMaxConsecutiveOnes(int[] nums) {
      int start = 0;
      int end = 0;
        
      int zeroIndex = -1;
      int result = 0;
      while (end < nums.length) {
          if (nums[end] == 0) {
              start = zeroIndex + 1;
              zeroIndex = end;
          }
            
          result = Math.max(result, end - start + 1);
          end++;
      }
  
      return result;
}
'''

'''
TC:- O(n)
SC:- O(1)
where n is the size of the inputNum
'''
'''
Complexity:-
Tc:- O(n)
SC:- O(1)
'''
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        maxx = 1
        withf = 0
        withoutf = 0
        for n in nums:
            if n:
                withf+=1
                withoutf+=1
            else:
                withf = withoutf + 1
                withoutf = 0
            if withf>maxx:
                maxx = withf
        return maxx

