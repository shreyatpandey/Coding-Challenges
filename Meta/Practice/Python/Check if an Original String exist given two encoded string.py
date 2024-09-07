'''
An original string, consisting of lowercase English letters, can be encoded by the following steps:

Arbitrarily split it into a sequence of some number of non-empty substrings.
Arbitrarily choose some elements (possibly none) of the sequence, and replace each with its length (as a numeric string).
Concatenate the sequence as the encoded string.
For example, one way to encode an original string "abcdefghijklmnop" might be:

Split it as a sequence: ["ab", "cdefghijklmn", "o", "p"].
Choose the second and third elements to be replaced by their lengths, respectively. The sequence becomes ["ab", "12", "1", "p"].
Concatenate the elements of the sequence to get the encoded string: "ab121p".
Given two encoded strings s1 and s2, consisting of lowercase English letters and digits 1-9 (inclusive), return true if there exists an original string that could be encoded as both s1 and s2. Otherwise, return false.

Note: The test cases are generated such that the number of consecutive digits in s1 and s2 does not exceed 3.
'''
'''
Steps:-
(1) For s1 and s2, divide each into a sequence of single alphabet strings and digital strings. 
The problem now becomes comparing if two sequences are equal.
(2) A single alphabet string has no variation, but a digital string has variations. 
For example: "124" can be interpreted as 1+2+4, 12+4, 1+24, and 124 wildcard characters
(3) There are four kinds of comparisons: a single alphabet vs another; 
a single alphabet vs a number, 
a number vs a single alphabet
a number vs another number. 
In the case of a number vs another (a single alphabet or a number), can you decrease the number by the min length of both?
'''
'''
Input: s1 = "internationalization", s2 = "i18n"
Output: true
Explanation: It is possible that "internationalization" was the original string.
- "internationalization" 
  -> Split:       ["internationalization"]
  -> Do not replace any element
  -> Concatenate:  "internationalization", which is s1.
- "internationalization"
  -> Split:       ["i", "nternationalizatio", "n"]
  -> Replace:     ["i", "18",                 "n"]
  -> Concatenate:  "i18n", which is s2
Input: s1 = "a5b", s2 = "c5b"
Output: false
Explanation: It is impossible.
- The original string encoded as s1 must start with the letter 'a'.
- The original string encoded as s2 must start with the letter 'c'.
'''
'''
TC:- O(N*M) where N is the length of s1 and M is the length of s2
SC:- O(NM) for memoization

'''
class Solution:
    def possiblyEquals(self, s1: str, s2: str) -> bool:
        def PossibleLength(s): 
            """Return possible length"""
            ans = [int(s)]
            if len(s) == 2: 
                if s[1] != '0': ans.append(int(s[0]) + int(s[1]))
                return ans
            elif len(s) == 3: 
                if s[1] != '0': ans.append(int(s[:1]) + int(s[1:]))
                if s[2] != '0': ans.append(int(s[:2]) + int(s[2:]))
                if s[1] != '0' and s[2] != '0': ans.append(int(s[0]) + int(s[1]) + int(s[2]))
            return ans 
        
        @cache
        def Helper(i, j, diff): 
            """Return True if s1[i:] matches s2[j:] with given differences."""
            if i == len(s1) and j == len(s2): return diff == 0
            if i < len(s1) and s1[i].isdigit(): 
                ii = i
                while ii < len(s1) and s1[ii].isdigit(): ii += 1
                for x in PossibleLength(s1[i:ii]): 
                    if Helper(ii, j, diff-x): return True 
            elif j < len(s2) and s2[j].isdigit(): 
                jj = j 
                while jj < len(s2) and s2[jj].isdigit(): jj += 1
                for x in PossibleLength(s2[j:jj]): 
                    if Helper(i, jj, diff+x): return True 
            elif diff == 0: 
                if i == len(s1) or j == len(s2) or s1[i] != s2[j]: return False 
                return Helper(i+1, j+1, 0)
            elif diff > 0: 
                if i == len(s1): return False 
                return Helper(i+1, j, diff-1)
            else: 
                if j == len(s2): return False 
                return Helper(i, j+1, diff+1)
            
        return Helper(0, 0, 0)
