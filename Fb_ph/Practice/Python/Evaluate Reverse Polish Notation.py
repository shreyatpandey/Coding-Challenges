'''
You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.
 

Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

'''
'''
Approach:- Use Stack
Tc:- O(n)
Sc:- O(n)
'''
def evalRPN(self, tokens):
    
    stack = []
    
    for token in tokens:
        
        if token not in "+-/*":
            stack.append(int(token))
            continue
    
        number_2 = stack.pop()
        number_1 = stack.pop()
        
        result = 0
        if token == "+":
            result = number_1 + number_2
        elif token == "-":
            result = number_1 - number_2
        elif token == "*":
            result = number_1 * number_2
        else:
            result = int(number_1 / number_2)
            
        stack.append(result)

    return stack.pop()
