

'''
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

If multiple answers are possible, return any of them.

It is guaranteed that the length of the answer string is less than 104 for all the given inputs.

 

Example 1:

Input: numerator = 1, denominator = 2
Output: "0.5"
Example 2:

Input: numerator = 2, denominator = 1
Output: "2"
Example 3:

Input: numerator = 4, denominator = 333
Output: "0.(012)"
'''
'''
Constraints:

-2^31 <= numerator, denominator <= 2^31 - 1
denominator != 0
'''


'''
Approach
This solution also handles the edge cases of a zero numerator and a zero denominator, 
and also checks for the negative sign at the beginning. 
It then calculates the integer part of the result by doing an integer division of the numerator by the denominator, 
and checks if there is a fractional part by checking if the remainder of this division is zero.
If there is a fractional part, it adds a decimal point to the result.

The main optimization in this solution is the use of a dictionary to store the position of each remainder in the result. 
This way, we can easily check if a remainder has already appeared in the result, and if it has, 
we know that we have found a repeating part. We can then insert the opening
and closing parentheses at the appropriate positions in the result.
'''
'''
Complexity:-
Tc:- O(|denominator|). 
In the while loop value of remainder is always [0,denominator-1] due to modulus operator.

Space Complexity: O(log(|numerator|)/log(|denominator) for hashMap
'''
class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        # Handle edge cases
        if numerator == 0:
            return "0"
        if denominator == 0:
            return ""

        # Initialize result and check for negative sign
        result = ""
        if (numerator < 0) ^ (denominator < 0):
            result += "-"
        numerator, denominator = abs(numerator), abs(denominator)

        # Integer part of the result
        result += str(numerator // denominator)

        # Check if there is a fractional part
        if numerator % denominator == 0:
            return result

        result += "."

        # Use a dictionary to store the position of each remainder
        remainder_dict = {}
        remainder = numerator % denominator

        # Keep adding the remainder to the result until it repeats or the remainder becomes 0
        while remainder != 0 and remainder not in remainder_dict:
            remainder_dict[remainder] = len(result)
            remainder *= 10
            result += str(remainder // denominator)
            remainder %= denominator

        # Check if there is a repeating part
        if remainder in remainder_dict:
            result = result[:remainder_dict[remainder]] + "(" + result[remainder_dict[remainder]:] + ")"

        return result
