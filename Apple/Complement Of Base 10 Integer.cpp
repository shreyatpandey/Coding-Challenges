/*
The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
Given an integer n, return its complement.

 

Example 1:

Input: n = 5
Output: 2
Explanation: 5 is "101" in binary, with complement "010" in binary, which is 2 in base-10.
Example 2:

Input: n = 7
Output: 0
Explanation: 7 is "111" in binary, with complement "000" in binary, which is 0 in base-10.
*/

/*
TC:- O(log(N))
why log(N) because at every step we are multiplying by the power of 2
SC:- O(1)
*/

class Solution {
public:
    int bitwiseComplement(int N) { 
        int c = 1;
        while (c < N) 
        {
            c = (c << 1) + 1;
        }
        return N ^ c;
    }
};

/*
Naive solution
TC:- O(N)
SC:-O(N)
*/
class Solution
{
    public:
        int bitwiseComplement(int N)
        {
            vector<int>Temp;
            if ( N== 0)
                return 1;
            while(N)
            {
                Temp.emplace_back(N%2);
                N /= 2;
            }
            int result = 0;
            for(int size = Temp.size()-1;size>=0;size--)
            {
               if(Temp[size] == 1) Temp[size] = 0;
               else if (Temp[size] == 0) Temp[size] = 1;
               result += Temp[size]*pow(2,size);
            }
            return result;
        }
};
