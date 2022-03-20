'''
Description
Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). 
You must also not convert the inputs to integers directly.

Example 1:

Input: num1 = "11", num2 = "123"
Output: "134"
'''

'''
TC:- O(max(len(num1),len(num2)))
SC:- O(max(len(num1),len(num2)))
'''
class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        res = []

        carry = 0
        p1 = len(num1) - 1
        p2 = len(num2) - 1
        while p1 >= 0 or p2 >= 0:
            x1 = ord(num1[p1]) - ord('0') if p1 >= 0 else 0
            x2 = ord(num2[p2]) - ord('0') if p2 >= 0 else 0
            value = (x1 + x2 + carry) % 10
            carry = (x1 + x2 + carry) // 10
            res.append(value)
            p1 -= 1
            p2 -= 1
        
        if carry:
            res.append(carry)
        res.reverse()        
        return ''.join(str(x) for x in res)
'''
Along the lines of Add Binary
Faster than 90.58%
'''
class Solution:
    def addStrings(self, strA: str, strB: str) -> str:
        maxLen = max(len(strA),len(strB))
        carry = 0
        Result = []
        strA = strA.zfill(maxLen)
        strB = strB.zfill(maxLen)
        for i in range(maxLen-1,-1,-1):
            numA,numB  = 0,0
            numA = ord(strA[i]) - ord('0')
            numB = ord(strB[i]) - ord('0')

            total = numA + numB + carry
            rem = total%10
            carry = total//10
            Result.append(rem)
        if carry:
            Result.append(carry)
        Result.reverse()
        return ''.join(str(x) for x in Result)
        
