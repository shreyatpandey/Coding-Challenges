'''
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. 
Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
'''
'''
Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9']
'''
'''
Approach:- BackTracking
Tc:- O(4^N.N)
N is the length of digits
Why 4? Let's say the worst case is when digits consists only of 7's and 9's.
In that case, traversal would require 4 possible steps.
So constructing decision tree, for 7's and 4's there would be possible choices for each N characters
so N.4^N
Sc:- O(N)
For recursion stack space
'''
class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        phone_dictionary = {'1':'','2':'abc','3':'def','4':'ghi','5':'jkl','6':'mno',
                            '7':'pqrs','8':'tuv','9':'wxyz'
                            }
        def backtrace_phone(combinationstring,digitsiterate):
            if len(digitsiterate) == 0:
                output_list.append(combinationstring)
            else:
                for letter in phone_dictionary[digitsiterate[0]]:
                    backtrace_phone(combinationstring+letter,digitsiterate[1:])
        
        output_list = []
        if digits:
            backtrace_phone("",digits)
        return output_list

'''
Approach:- Iterative
Tc:- O(N.4^N)
Sc:- O(N)
'''
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []

        phone_map = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz'
        }
        combinations = [""]

        for digit in digits:
            new_combinations = []
            for combination in combinations:
                for letter in phone_map[digit]:
                    new_combinations.append(combination + letter)
            combinations = new_combinations

        return combinations
