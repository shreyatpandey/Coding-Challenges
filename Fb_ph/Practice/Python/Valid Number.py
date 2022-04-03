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
Rules:-
    Digits (one of ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"])

    Both decimal numbers and integers must contain at least one digit.
        A sign ("+" or "-")

    Sign characters are optional for both decimal numbers and integers, but if one is present, it will always be the first character. Note, this means that a sign character can also appear immediately after an exponent.
    An exponent ("e" or "E")

    Exponents are also optional, but if the string contains one then it must be after a decimal number or an integer.
    An integer must follow the exponent.
    A dot (".")

    A decimal number should only contain one dot. Integers cannot contain dots.
    Anything else

    There will never be anything else in a valid number.

'''
'''
The first step is to design our DFA. 
Picture the DFA as a directed graph, where each node is a state, 
and each edge is a transition labeled with a character group (digit, exponent, sign, or dot). 
There are two key steps to designing it.

Identify all valid combinations that the aforementioned boolean variables can be in. 
Each combination is a state. Draw a circle for each state, and label what it means.
For each state, consider what a character from each group would mean in the context of that state. 
Each group will either cause a transition into another state, or it will signify that the string is invalid. 
For each valid transition, draw a directed arrow between the two states and write the group next to the arrow.

'''

'''
Example 1:

Input: s = "0"
Output:- True

Example 2:
Input: s ="1E9"
Output:- True

Example 3:
Input:- s = "."
Output:- False
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
''''
Follow this approach
Without the need of blank
Clarify if the string has leading spaces

s consists of only English letters (both uppercase and lowercase), digits (0-9), plus '+', minus '-', or dot '.'.
'''
'''
TC:- O(N)
SC:- O(1)
'''
class Solution:
    def isNumber(self, s: str) -> bool:
        #define a DFA
        state = [{},
              {'sign': 2, 'digit':3, 'dot':4}, 
              {'digit':3, 'dot':4},
              {'digit':3, 'dot':5, 'exponent':6,},
              {'digit':5},
              {'digit':5, 'exponent':6,},
              {'sign':7, 'digit':8},
              {'digit':8},
              {'digit':8}
                ]
        currentState = 1
        for c in s:
            if c >= '0' and c<='9':
                c = 'digit'
            elif c in ['+', '-']:
                c = 'sign'
            elif c in ["e","E"]:
                c = 'exponent'
            elif c =='.':
                c = 'dot'
            if c not in state[currentState].keys():
                return False
            currentState = state[currentState][c]
        if currentState not in [3,5,8,9]:
            return False
        return True
