/*
Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.
Example 2:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 3:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/
/*
Approach-1:- forward traversing
*/
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>RomToInt =
        {
         {'M',1000},
         {'D',500},
         {'C',100},
         {'L',50},
         {'X',10},
         {'V',5},
         {'I',1}
        };
        int Answer = 0;
        int PrevNum = 0;
        int i = 0;
        while(i<s.length())
        {
            auto Current = RomToInt[s[i]];
            if(PrevNum<Current)
            {
                Answer -= PrevNum;
                int Diff = Current - PrevNum;
                Answer += Diff;
            }
            else
            {
                Answer += Current;
            }
            PrevNum = Current;
            i += 1;
        }
         
        return Answer;
    }
};

/* Approach-2:- Backward Traversing */
class Solution {
public:
    int romanToInt(string s) {

    unordered_map<char, int> T = { { 'I' , 1 },
                                   { 'V' , 5 },
                                   { 'X' , 10 },
                                   { 'L' , 50 },
                                   { 'C' , 100 },
                                   { 'D' , 500 },
                                   { 'M' , 1000 } };
                                   
   int sum = T[s.back()];
   for (int i = s.length() - 2; i >= 0; --i) 
   {
       if (T[s[i]] < T[s[i + 1]])
       {
           sum -= T[s[i]];
       }
       else
       {
           sum += T[s[i]];
       }
   }
   
   return sum;
        
    }
};
