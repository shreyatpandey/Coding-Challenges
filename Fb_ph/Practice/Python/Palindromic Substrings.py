'''
Given a string s, return the number of palindromic substrings in it.
A string is a palindrome when it reads the same backward as forward.
A substring is a contiguous sequence of characters within the string.
Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Input = "bb"
Output = 3
'''
'''
Constraints:-
1 <= s.length <= 1000
s consists of lowercase English letters.
'''
'''
Approach:- Expansion about center
In total there would be n^2 substring
Finding palindrome is O(n)
S = "aaab"
Expand in both direction
Start in middle, expand left and right
Say "a", LR
Single character was a palindrome
Sub problem is not longer a palindrome
Last position "b"
LR for b it self is a palindrome
Then for "aa"
Left pointer initialized to a and right to a
check if the left is equal to right
'''
'''
Complexity:-
TC:- O(n^2)
The number of possible palindromic centers we process
How much time we spend processing each center
SC:- O(1)
'''
class Solution:
    def countSubstrings(self, s: str) -> int:
        count = 0
        def countPalindrome(s,left,right):
            result = 0
            while left>=0 and right < len(s) and s[left] == s[right]:
                result += 1
                left -= 1
                right += 1
            return result
    
        n = len(s)
        if n==0:return 0
        for i in range(n):
           left = right = i # odd length
           count += countPalindrome(s,left,right)

           left,right = i, i+1 #even length
           count += countPalindrome(s,left,right)
        return count

# Time:  O(n^2)
# Space: O(n^2)
# idea: dynamic programming, nearly the same solution as Longest Palindromic Substring
# dp[i, j] = 1                                   if i == j
#          = s[i] == s[j]                        if j = i + 1
#          = s[i] == s[j] && dp[i + 1][j - 1]    if j > i + 1     
class Solution:
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        cnt = 0
        memo = [[False for _ in range(len(s))] for __ in range(len(s))]
        for i in range(len(s)):
            for j in range(i):
                if i - j <= 2:
                    memo[j][i] = (s[j] == s[i])
                else:
                    memo[j][i] = (s[j] == s[i] and memo[j + 1][i - 1])
                if memo[j][i]:
                    cnt += 1
            memo[i][i] = True
            cnt += 1
            
        return cnt
        
