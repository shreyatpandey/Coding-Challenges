'''
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).
'''
'''
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
'''
'''
Constraints:

0 <= s.length, p.length <= 2000
s contains only lowercase English letters.
p contains only lowercase English letters, '?' or '*'.
'''
'''
Extra Test Cases
s: "bacd"
p: "ba*cd"
match: true
s: "bacde"
p: "ba*cd"
match: false
'''
'''
Appraoch:- Recursion with Memoization
Tc:- O(S.P(S+P))
Sc:- O(S.P)
The recursion call stack may exceed max(S, P) in cases such as (s, p) = (aaab, *a*b), however, it is bounded by O(S+P). 
Lastly, the hashmap requires O(S⋅P) space to memoize the result of each call to helper.
'''
from functools import lru_cache
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        # Init
        n = len(s)
        m = len(p)
       
        @lru_cache # memoization
        def match(s_idx, p_idx) -> bool:
            
            # Wait for pattern to be exhausted
            if p_idx == m:
                return s_idx == n # string must be exhausted if it matches the pattern
            
            elif s_idx > n: # if string is exhausted before pattern is exhausted, return False
                return False
            
            else: # for all other scenarios
                
                # see if string matches the current pattern
                matched = ((s_idx < n) and (s[s_idx] == p[p_idx])) or (p[p_idx] in ["*", "?"])
                
                # if nothing matches, return false
                if not matched:
                    return False
                
                else: # in case of a match
                    
                    # check if pattern has "*"
                    if p[p_idx] == "*":
                        return (match(s_idx+1, p_idx) or # increment string index and stay at same pattern index
                                match(s_idx+1,p_idx+1) or # increment both string and patter index
                                match(s_idx, p_idx+1)) # increment pattern index and stay at the same string index
                    
                    else: # if pattern doesn't have "*", then it either have "?" or same char as string
                        return match(s_idx+1, p_idx+1) # increment both string and pattern index
        
        return match(0,0)

'''
Approach:- DP
Tc:- O(S.P)
Sc:- O(S.P)
'''
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        s_len = len(s)
        p_len = len(p)
        
        # base cases
        if p == s or set(p) == {'*'}:
            return True
        if p == '' or s == '':
            return False
        
        # init all matrix except [0][0] element as False
        d = [[False] * (s_len + 1) for _ in range(p_len + 1)]
        d[0][0] = True
        
        # DP compute 
        for p_idx in range(1, p_len + 1):
            # the current character in the pattern is '*'
            if p[p_idx - 1] == '*':
                s_idx = 1
                                        
                # d[p_idx - 1][s_idx - 1] is a string-pattern match 
                # on the previous step, i.e. one character before.
                # Find the first idx in string with the previous math.
                while not d[p_idx - 1][s_idx - 1] and s_idx < s_len + 1:
                    s_idx += 1
    
                # If (string) matches (pattern), 
                # when (string) matches (pattern)* as well
                d[p_idx][s_idx - 1] = d[p_idx - 1][s_idx - 1]
    
                # If (string) matches (pattern), 
                # when (string)(whatever_characters) matches (pattern)* as well
                while s_idx < s_len + 1:
                    d[p_idx][s_idx] = True
                    s_idx += 1
                                   
            # the current character in the pattern is '?'
            elif p[p_idx - 1] == '?':
                for s_idx in range(1, s_len + 1): 
                    d[p_idx][s_idx] = d[p_idx - 1][s_idx - 1] 
                                   
            # the current character in the pattern is not '*' or '?'
            else:
                for s_idx in range(1, s_len + 1): 
                    # Match is possible if there is a previous match
                    # and current characters are the same
                    d[p_idx][s_idx] = d[p_idx - 1][s_idx - 1] and p[p_idx - 1] == s[s_idx - 1]  
                                                               
        return d[p_len][s_len]
        
