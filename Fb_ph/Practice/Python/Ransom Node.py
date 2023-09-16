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
    
