'''
Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
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
