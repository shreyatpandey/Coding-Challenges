'''
Given two strings ransomNote and magazine, 
return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.
Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
'''
'''
Constraints:
1 <= ransomNote.length, magazine.length <= 10^5
ransomNote and magazine consist of lowercase English letters.
'''

'''
Approach-1:- Failed 
Two Pointer
'''
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        length1, length2 = len(ransomNote), len(magazine)
        if length1 > length2:
            return False
        index1, index2 = 0,0
        while index1<length1 and index2<length2:
            if ransomNote[index1] != magazine[index2]:
                return False
            index1 += 1
            index2 += 1
        return True
if __name__ == '__main__':
    s = Solution()
    print("Test-Case Failure")
    print(s.canConstruct("aab","baa"))
    #it should be true
    
'''
Approach-2:- One HashMap
TC:- O(m) where m is the size of magazine
SC:- O(k) or O(1) as only 26 letter are present, so counter would consists of 26 letter at the most
'''
from collections import Counter
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        length1, length2 = len(ransomNote), len(magazine)
        if length1 > length2:
            return False
        magazineCounter = Counter(magazine)
        for char in ransomNote:
            if magazineCounter[char] == 0:
                return False
            magazineCounter[char] -= 1
        return True
    
