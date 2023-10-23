'''
A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into 
letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The test cases are generated so that the answer fits in a 32-bit integer.
'''
'''
Example 1:

Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).

Example 2:
Input: s = "06"
Output: 0
Explanation: "06" cannot be mapped to "F" because of the leading zero ("6" is different from "06").
'''
'''
Constraints:

1 <= s.length <= 100
s contains only digits and may contain leading zero(s).
'''
'''
Approach:- Top-Down
Tc:- O(N)
Sc:- O(N)
'''
'''
For a character s[i], we have 2 ways to decode:
Single digit: Require s[i] != '0' (decoded to 1..9)
Two digits: Require i + 1 < len(s) and (s[i] == 1 (decoded to 10..19) or s[i] == 2 and s[i+1] <= '6') (decoded to 20..26).
'''
class Solution:  
    def numDecodings(self, s: str) -> int:
        @lru_cache(None)
        def dp(i):
            if i == len(s): return 1
            ans = 0
            if s[i] != '0':  # Single digit
                ans += dp(i + 1)
            if i + 1 < len(s) and (s[i] == '1' or s[i] == '2' and s[i + 1] <= '6'):  # Two digits
                ans += dp(i + 2)
            return ans

        return dp(0)
'''
Approach:- Bottom-Up
Tc:- O(N)
Sc:- O(N)
'''
class Solution:  
    def numDecodings(self, s: str) -> int:
        n = len(s)
        dp = [0] * (n+1)
        dp[n] = 1
        for i in range(n-1, -1, -1):
            if s[i] != '0':  # Single digit
                dp[i] = dp[i+1]
            if i+1 < n and (s[i] == '1' or s[i] == '2' and s[i+1] <= '6'):  # Two digits
                dp[i] += dp[i+2]
        return dp[0]

'''
Approach:- Bottom-Up (Space Optimized)
Tc:- O(n)
Sc:- O(1)
'''
'''
Since our dp only need to keep up to 3 following states:
Current state, let name dp corresponding to dp[i]
Last state, let name dp1 corresponding to dp[i+1]
Last twice state, let name dp2 corresponding to dp[i+2]
'''
class Solution:  
    def numDecodings(self, s: str) -> int:
        dp, dp1, dp2, n = 0, 1, 0, len(s)
        for i in range(n-1, -1, -1):
            if s[i] != '0':  # Single digit
                dp += dp1
            if i+1 < n and (s[i] == '1' or s[i] == '2' and s[i+1] <= '6'):  # Two digits
                dp += dp2
            dp, dp1, dp2 = 0, dp, dp1
        return dp1
