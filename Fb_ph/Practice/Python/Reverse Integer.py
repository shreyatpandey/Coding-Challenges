'''
Given a signed 32-bit integer x, return x with its digits reversed. 
If reversing x causes the value to go outside the signed 32-bit integer range [-2**31, 2**31 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
'''
'''
Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
'''

def reverse_v1(self, x: int) -> int:
  reverse = 0
  max_int = pow(2, 31)-1
  min_int = pow(-2, 31)
  
  while x != 0:   
      # Python modulo does not work the same as c or java. It always returns the same
      # sign as the divisor and rounds towards negative infinit. Also // rounds towards negative infinity not 0 as in C so this also
      # behaves differently. Python 3.7 added a math.remainder(), but leet code is
      # running a python version prior to this (at least at the time of writing). Since the C 'remainder' behavior is desirable for
      # this problem, the following code emulates it. 
      #
      # See https://stackoverflow.com/questions/1907565/c-and-python-different-behaviour-of-the-modulo-operation and
  # http://python-history.blogspot.com/2010/08/why-pythons-integer-division-floors.html
      pop = x % 10 if x >= 0 else (abs(x) % 10)*-1
      x = x // 10 if x >=0 else math.ceil(x / 10)
  
      if (reverse > max_int//10) or (reverse == max_int // 10 and pop > 7):
          return 0
      
      if (reverse < math.ceil(min_int / 10)) or (reverse == math.ceil(min_int / 10) and pop < -8):
          return 0
      
      reverse = reverse * 10 + pop
  
  return reverse
