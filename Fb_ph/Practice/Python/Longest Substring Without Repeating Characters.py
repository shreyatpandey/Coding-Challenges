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
        charSet = set()
        left = 0
        result= 0
        for right in range(len(s)):
            while s[right] in charSet: # found a duplicate , remove it from set 
                charSet.remove(s[left])
                left += 1
            charSet.add(s[right])
            result = max(result,right-left+1)
        return result
