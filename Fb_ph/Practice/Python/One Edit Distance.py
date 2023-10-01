'''
Given two strings s and t, return true if they are both one edit distance apart, otherwise return false.

A string s is said to be one distance apart from a string t if you can:

Insert exactly one character into s to get t.
Delete exactly one character from s to get t.
Replace exactly one character of s with a different character to get t.
 

Example 1:

Input: s = "ab", t = "acb"
Output: true
Explanation: We can insert 'c' into s to get t.
Example 2:

Input: s = "", t = ""
Output: false
Explanation: We cannot get t from s by only one step.
'''
'''
Constraints:-
0 <= s.length, t.length <= 104
s and t consist of lowercase letters, uppercase letters, and digits.
'''
class Solution:
    def isOneEditDistance(self, s: str, t: str) -> bool:
        if abs(len(s) - len(t)) > 1:
            # If length of the two strings differs by more than one character,
            # then the two strings cannot be one edit distance apart
            return False
        
        i = j = edits = 0
        while i < len(s) and j < len(t):
            if s[i] == t[j]:
                # Characters match, move both i and j forward and continue the while loop
                i, j = i + 1, j + 1
                continue
                
            # We reach here only when there is a mismatch
            # Increment edits and return early if edits > 1
            edits += 1
            if edits > 1:
                return False
            
            # This reflects the three types of edits
            if len(s) == len(t):
                # Replace character in s
                i, j = i + 1, j + 1
            else:
                if len(s) > len(t):
                    # Delete character from s
                    i += 1
                else:
                    # Add character to s
                    j += 1
                    
        if i < len(s) or j < len(t):
            # Any left over characters (maximum of 1) will have to be deleted
            edits += 1
            
        # Return if input strings are exactly one edit distance away from each other
        return edits == 1

if __name__ == '__main__':
    s = "ab"
    t = "acb"
    s1 = Solution()
    print("One Edit Distance:", s1.isOneEditDistance(s,t))
    
    
