'''
Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.
For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
 

Example 1:

Input: columnNumber = 1
Output: "A"

'''
'''
Constraints:
1 <= columnNumber <= 2^31 - 1
'''

'''
Approach-1:- Iterative
TC:- O(log26(n))
SC:- O(log26(n)
'''
class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        result = []
        while columnNumber:
            columnNumber, remainder = divmod(columnNumber - 1, 26)
            result.append(chr(65 + remainder))
        return ''.join(reversed(result))
'''
Approach-2:- Recursive
TC:- O(log26(n))
SC:- O(log26(n)
'''
class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        if not columnNumber:
            return ""
        columnNumber, remainder = divmod(columnNumber - 1, 26)
        return self.convertToTitle(columnNumber) + chr(65 + remainder)
