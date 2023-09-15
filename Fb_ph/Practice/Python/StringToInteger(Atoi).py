'''
Input-1:- s = "   -42"
Output: -42
Explanation:
Step 1: "   -42" (leading whitespace is read and ignored)
            ^
Step 2: "   -42" ('-' is read, so the result should be negative)
             ^
Step 3: "   -42" ("42" is read in)
               ^
The parsed integer is -42.
Since -42 is in the range [-231, 231 - 1], the final result is -42.

Input-2:-
Input: s = "4193 with words"
Output: 4193
Explanation:
Step 1: "4193 with words" (no characters read because there is no leading whitespace)
         ^
Step 2: "4193 with words" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "4193 with words" ("4193" is read in; reading stops because the next character is a non-digit)
             ^
The parsed integer is 4193.
Since 4193 is in the range [-231, 231 - 1], the final result is 4193.

'''


'''
Constraints:-
0 <= s.length <= 200
s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.
'''
'''
TC:- O(N)
SC:- O(1)
'''
class Solution(object):
    def myAtoi(self, s):
        """
        :type s: str
        :rtype: int
        """
        negative = 1
        digit = ''
        s = s.lstrip()
        sign = ['+','-']
        for index,char in enumerate(s):
            if char in sign and index == 0:
                digit += char
                continue
            if char.isdigit():
                digit += char
            else:
                break
        
        #special case for 0.314 and no digit is found or for +-12
        if not digit or digit in sign:
            return 0
        if digit[0] in sign:
            if digit[0] == '-':
                negative = -1
            digit = digit[1:len(digit)]
        digitLen = len(digit) - 1
        result = 0
        for char in digit:
            digit1 = ord(char) -  ord('0')
            result += (digit1*pow(10,digitLen))
            digitLen -= 1
        result = result*negative
        if result > 2**31-1:
            result = 2**31 -1
        elif result < -2**31:
            result = -2**31 
        
        return  result
