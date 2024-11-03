'''
The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the run-length encoding of countAndSay(n - 1).

Given a positive integer n, return the nth element of the count-and-say sequence.
'''
'''
Example 1:

Input: n = 4

Output: "1211"

Explanation:

countAndSay(1) = "1"
countAndSay(2) = RLE of "1" = "11"
countAndSay(3) = RLE of "11" = "21"
countAndSay(4) = RLE of "21" = "1211"

Example 2:

Input: n = 1

Output: "1"

Explanation:

This is the base case.
'''
'''
Constraints:
1 <= n <= 30
'''
'''
TC:- O(n^2)
SC:- O(n)
'''

class Solution:
    def countAndSay(self, n: int) -> str:
        ret = "1"
        for i in range(n-1):
            ret = self.nextStep(ret)
        return ret
    
    def nextStep(self, s):
        i, ret = 0, ""
        while i < len(s):
            count = 1
            while i+1 < len(s) and s[i+1] == s[i]:
                count += 1
                i += 1
            ret += str(count) + s[i]
            i += 1
        return ret
