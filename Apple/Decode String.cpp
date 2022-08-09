/*
Example 1:
Input: s = "3[a]2[bc]"
Output: "aaabcbc"
*/
/*
Given an encoded string, return its decoded string.
The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times.
Note that k is guaranteed to be a positive integer.
*/
class Solution {
public:
    string decodeString(string s) {
        stack<string>StringHolder;
        stack<int>Number;
        string result = "";
        int Index = 0;
        int FormDigit = 0;
        while(Index < s.length())
        {
            
            if(isdigit(s[Index]))
            {
                int temp = s[Index] - (int)'0';
                FormDigit = FormDigit*10 + temp;
            }
            else if ( s[Index] == '[')
            {
                StringHolder.push(result);
                result = "";
                Number.push(FormDigit);
                FormDigit = 0;
            }
            else if ( s[Index] == ']')
            {
                string temp ;
                int Count = Number.top();
                Number.pop();
                temp = StringHolder.top();
                StringHolder.pop();
                int i = 0;
                while( i < Count )
                {
                    temp += result;
                    i += 1;
                }
                result = temp;
            }
            else
            {
                result += s[Index];
                
            }                
            
            Index += 1;
        }
        return result;
    }
};
