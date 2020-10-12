/*
Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.

Note:

All letters in hexadecimal (a-f) must be in lowercase.
The hexadecimal string must not contain extra leading 0s. 
If the number is zero, it is represented by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
The given number is guaranteed to fit within the range of a 32-bit signed integer.

Input : -1
Output:- ffffffff
*/

class Solution {
public:
    string toHex(int num) {
        if  ( num == 0 )
            return "0";
        string result = "";
        long Value = num < 0 ? (1LL << 32) + num : num;
        while(Value)
        {
            int remainder = Value%16;
            Value /= 16;
            if ( remainder > 9)
            {
                result += remainder + 87; //(int)'a' - 10
            }
            else
            {
                 result +=  remainder + 48; //(int)'48'
            }
        }
        reverse(result.begin(),result.end());
        return result;
        
    }
};
