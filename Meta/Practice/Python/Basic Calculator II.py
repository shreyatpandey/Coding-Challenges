'''
Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "3+2*2"
Output: 7
Example 2:

Input: s = " 3/2 "
Output: 1

There is no bracket which were involved

'''

'''
Approach-1:
TC:- O(n)
SC:- O(n) for the stack
'''
class Solution:
    def calculate(self, s: str) -> int:
        if not s:
            return "0"
        stack, num, sign = [], 0, "+"
        for i in range(len(s)):
            if s[i].isdigit():
                num = num*10+ord(s[i])-ord("0")
            if (not s[i].isdigit() and not s[i].isspace()) or i == len(s)-1:
                if sign == "-":
                    stack.append(-num)
                elif sign == "+":
                    stack.append(num)
                elif sign == "*":
                    stack.append(stack.pop()*num)
                else:
                    tmp = stack.pop()
                    if tmp//num < 0 and tmp%num != 0:
                        stack.append(tmp//num+1)
                    else:
                        stack.append(tmp//num)
                sign = s[i]
                num = 0
        return sum(stack)

'''
Approach-2:
TC:- O(n)
SC:- O(1) without using stack
'''
class Solution:
    def calculate(self, s: str) -> int:
        curr_res = 0
        res = 0
        num = 0
        op = "+"  # keep the last operator we have seen
        
		    # append a "+" sign at the end because we can catch the very last item
        for ch in s + "+":
            if ch.isdigit():
                num = 10 * num + int(ch)

            # if we have a symbol, we would start to calculate the previous part.
            # note that we have to catch the last chracter since there will no sign afterwards to trigger calculation
            if ch in ("+", "-", "*", "/"):
                if op == "+":
                    curr_res += num
                elif op == "-":
                    curr_res -= num
                elif op == "*":
                    curr_res *= num
                elif op == "/":
                    # in python if there is a negative number, we should alway use int() instead of //
                    curr_res = int(curr_res / num)
                
                # if the chracter is "+" or "-", we do not need to worry about
                # the priority so that we can add the curr_res to the eventual res
                if ch in ("+", "-"):
                    res += curr_res
                    curr_res = 0
                
                op = ch
                num = 0
        
        return res
