//Time-Complexity:- O(n)
//Space-Complexity:- O(1)
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
        
        
        #special case for 0.314 or no digit is found or for +-12
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
        #this is problem description handling of edge case
        if result > 2**31-1:
            result = 2**31 -1
        elif result < -2**31:
            result = -2**31 
        
        
        return  result
