'''
You are given an integer num. You can swap two digits at most once to get the maximum valued number.

Return the maximum valued number you can get.

Example 1:

Input: num = 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
Example 2:

Input: num = 9973
Output: 9973
Explanation: No swap.

0 <= num <= 108
'''
'''
Clarifying questions:-
What if num < 10 ? Return the num
are the numbers negative?
'''
'''
Wording:-
Do a linear traversal and find that index where the s[index] < s[index+1] indicating there is a chance of flip let say its flip index
Of course if the nums are monotically decreasing , then return that num
Once we find that index, do linear from that flip index to get that index which has ,maximum value lets say MaxIndex
#left traversal 
When I say left traversal , start traversing from flip index in reverse order and the find that index which is less that MaxVal obtained from maxIndex
Just swap the value after flip-index and most left less tham MaxIndex

'''
'''
Approach:- Greedy/Math
TC:- O(N)
SC:- O(N) for list of string num
'''
class Solution:
    def maximumSwap(self, num: int) -> int:
        s = list(str(num))
        n = len(s)
        i = 0
        while i < n-1:                                    # find index where s[i] < s[i+1], meaning a chance to flip
            if s[i] < s[i+1]: 
                break
            i += 1
        if i == n-1:
            return num                                      # if nothing find, return num
        max_idx, max_val = i+1, s[i+1]                      # keep going right, find the maximum value index
        for j in range(i+1, n):
            if max_val <= s[j]: max_idx, max_val = j, s[j]
        left_idx = i                                        # going right from i, find most left value that is less than max_val
        for j in range(i, -1, -1):    
            if s[j] < max_val: left_idx = j
        s[max_idx], s[left_idx] = s[left_idx], s[max_idx]   # swap maximum after i and most left less than max
        return int(''.join(s))                              # re-create the integer
