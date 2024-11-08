'''
Given a string s, return true if a permutation of the string could form a 
palindrome and false otherwise.

Example 1:

Input: s = "code"
Output: false
Example 2:

Input: s = "aab"
Output: true
Example 3:

Input: s = "carerac"
Output: true
 
Constraints:

1 <= s.length <= 5000
s consists of only lowercase English letters.
'''
'''
Approach-1 :- Using set and single pass
TC :- O(n)
Sc :- O(1) for set will not grow more than 26
'''
class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        map = {}
        count = 0
        for char in s:
            map[char] = map.get(char,0)+1
            if map[char] % 2 == 0:
                count -= 1
            else:
                count += 1
        return count <= 1

'''
Approach-2 :- Using map and single pass
TC :- O(n)
SC :- O(1)
'''
class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        map = {}
        count = 0
        for char in s:
            map[char] = map.get(char,0)+1
            if map[char] % 2 == 0:
                count -= 1
            else:
                count += 1
        return count <= 1