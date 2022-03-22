'''
A valid number can be split up into these components (in order):

A decimal number or an integer.
(Optional) An 'e' or 'E', followed by an integer.
A decimal number can be split up into these components (in order):

(Optional) A sign character (either '+' or '-').
One of the following formats:
One or more digits, followed by a dot '.'.
One or more digits, followed by a dot '.', followed by one or more digits.
A dot '.', followed by one or more digits.
An integer can be split up into these components (in order):

(Optional) A sign character (either '+' or '-').
One or more digits.
For example, all the following are valid numbers: 
["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"]
while the following are not valid numbers: ["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"].

Given a string s, return true if s is a valid number.

 

Example 1:

Input: s = "0"

Example 2:
Inpit: s ="1E9"


'''

'''
TC:- O(N)
SC:- O(1)
N is the length of string
'''
class Solution:
    def isNumber(self, s: str) -> bool:
        #define a DFA
        state = [{}, 
              {'blank': 1, 'sign': 2, 'digit':3, '.':4}, 
              {'digit':3, '.':4},
              {'digit':3, '.':5, 'exponent':6,},
              {'digit':5},
              {'digit':5, 'exponent':6,},
              {'sign':7, 'digit':8},
              {'digit':8},
              {'digit':8}
                ]
        currentState = 1
        for c in s:
            if c >= '0' and c <= '9':
                c = 'digit'
            if c == ' ':
                c = 'blank'
            if c in ['+', '-']:
                c = 'sign'
            if c in ["e","E"]:
                c = 'exponent'
            if c not in state[currentState].keys():
                return False
            currentState = state[currentState][c]
        if currentState not in [3,5,8,9]:
            return False
