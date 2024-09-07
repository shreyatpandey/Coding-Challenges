'''
Given a string s, find the length of the longest 
substring without repeating characters.


Example 1:

Input: s = "abcabcbb"
Output: 3

Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
'''
'''
Constraints:

0 <= s.length <= 5 * 10^4
s consists of English letters, digits, symbols and spaces.
'''

'''
Brute Force:-
Check every substring then check if it has duplicates
We are checking every substring starting from start index

Sliding Window Optimize:-
Our window is not containing any duplicates
Removing from the left whenever we found duplicates
How do we instantly if there is any duplicate or not?
Use set

'''
'''
Approach-1:-
Leetcode Solution
TC:- O(n) where n is the length of string
SC:- O(n) for the map 
'''
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        
        map = {}
        answer = 0
        j = 0
        for i in range(len(s)):
            if s[i] in map:
                j = max(map[s[i]],j)
            answer = max(answer,i-j+1)
            map[s[i]] = i+1
        return answer
        
'''
Approach-2:- Neetcode
TC:- O(n) where n is the length of the string
SC:- O(n) for the set
'''
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        charSet = set() #this can at max grow to 26, O(26) which is constant
        left = 0
        result= 0
        for right in range(len(s)):
            while s[right] in charSet: # found a duplicate , remove it from set 
                charSet.remove(s[left])
                left += 1
            charSet.add(s[right])
            result = max(result,right-left+1)
        return result
