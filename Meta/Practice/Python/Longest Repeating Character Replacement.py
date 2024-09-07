'''
You are given a string s and an integer k. 
You can choose any character of the string and change it to any other uppercase English character. 
You can perform this operation at most k times.
Return the length of the longest substring containing the same letter you can get after performing the above operations.

Example 1:
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
'''
'''
Constraints:
1 <= s.length <= 10^5
s consists of only uppercase English letters.
0 <= k <= s.length
'''
'''
Blind-75
Basically choose any character in the string and change it upper case character
with at most k different replacement
ABAB, k = 2
Either replace B with A or replace A with B
We can solve in O(n)
Basically it would be O(26.n) as there are 26 characters

Brute Force:- 
Check every substring and then find the substring it would be O(n^2)
Even if we are getting substring, what are we looking at?
We are looking at the sliding window
Replace the character which are less frequent
Match character most common in that window
ABABBA = A-3, B-3
Take windowlen , represents the number of characters that need to be 
replaced
windowLen - Count[B]
How do we know if we have enough characters to replace?
Take current window size = BABB, 
In this window size, B - 3 and A-1
windowlen = 4
count[B] = 3, most frequenct characeter
Main Formula:-
1. MaxFrequency = Max frequency of character at any given time
2. **windowLen - count[B] = 1 or windowLen - CountOfMostFrequentCharacter**
3. Then check if this difference is less than k
4. Then update the answer with max size
Left pointer at the beginning
Initial left pointer would be 0
'''
'''
Complexity:-
TC:- O(26.n) as the max characters in the string is 26 or
O(n)
SC:- O(n) for the window
'''
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        count = {} #hash map to count frequency of each character
        result, left = 0,0
        maxFrequency = 0
        for right in range(len(s)):
            count[s[right]] = count.get(s[right],0) + 1
            maxFrequency = max(maxFrequency,count[s[right]]) #O(1)
            while (right-left+1) - maxFrequency> k:
                count[s[left]] -= 1
                left += 1
            result= max(result,right-left+1)
        return result
