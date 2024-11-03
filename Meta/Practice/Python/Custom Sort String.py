'''
Question:-
You are given two strings order and s. 
All the words of order are unique and were sorted in some custom order previously.

Permute the characters of s so that they match the order that order was sorted. 
More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.

Return any permutation of s that satisfies this property.
'''
'''
Example 1:

Input: order = "cba", s = "abcd"
Output: "cbad"
Explanation: 
"a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a". 
Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.

Example 2:
Input: order = "cbafg", s = "abcd"
Output: "cbad"
'''
'''
Question to ask?
Are there any duplicates in order string? Mostly they are unique
Will input have null string?
Whether the characters are in uppper case or lowercase?
'''

'''
Time:- 45 ms
'''
class Solution:
    def customSortString(self, order: str, s: str) -> str:
        result  = []
        for char in order:
            getCount = s.count(char)
            result.append(char*getCount)
        stringResult = "".join(result)
        for char in s:
            if char not in stringResult:
                getCount = s.count(char)
                stringResult += (char*getCount)
                
        return stringResult

'''
 Approach:- 1
 Keep Track of Count and then write
 Get the frequency of each character in s 
 
 TC:- O(len(order) + O(len(s))
 SC:- O(len(s)) for the frequency count 
 Time:- 43 ms
'''
from collections import Counter
class Solution:
    def customSortString(self, order: str, s: str) -> str:
        
        countCharacters = Counter(s)
        result  = []
        for char in order:
            result.append(char*countCharacters[char])
            countCharacters[char] = 0
        
        for char in countCharacters:
            result.append(char*countCharacters[char])
            
        return "".join(result)
