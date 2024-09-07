'''
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
'''
'''
Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.
'''
'''
How is Matrix built :
The matrix is built iteratively using the following recurrence relation:
If word1[i-1] == word2[j-1], then dp[i][j] = dp[i-1][j-1]. 
That is, no operation is required because the characters at positions i-1 and j-1 are already the same.

Otherwise, dp[i][j] is the minimum of the following three values:
dp[i-1][j-1] + 1: replace the character at position i-1 in word1 with the character at position j-1 in word2.
dp[i-1][j] + 1: delete the character at position i-1 in word1.
dp[i][j-1] + 1: insert the character at position j-1 in word2 into word1 at position i.
The base cases are:
dp[i][0] = i: transforming word1[0...i-1] into an empty string requires i deletions.
dp[0][j] = j: transforming an empty string into word2[0...j-1] requires j insertions.
Final Step :
Finally, return dp[m][n], which represents the 
minimum number of operations required to transform word1 into word2, where m is the length of word1 and n is the length of word2.

'''

'''
Approach:- Bottom-Up
TC:-O(m*n)
SC:- O(m*n)
'''
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m = len(word1)
        n = len(word2)
        # dp[i][j] := min # Of operations to convert word1[0..i) to word2[0..j)
        dp = [[0] * (n + 1) for _ in range(m + 1)]

        for i in range(1, m + 1):
            dp[i][0] = i

        for j in range(1, n + 1):
            dp[0][j] = j

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if word1[i - 1] == word2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
                else:
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1

        return dp[m][n]
            
