//TC:- O(N^2)
//SC:- O(1)
//Weird - Problem
//Input:-
/*
Example 2:

Input: chars = ["a"]
Output: Return 1, and the first character of the input array should be: ["a"]
Explanation: The only group is "a", which remains uncompressed since it's a single character.
Example 3:

Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".
*/
class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char>StringCompressed ;
        int KeepTrack = 0;
        for(int Traverse=0;Traverse<chars.size();++Traverse)
        {
            int LoopWithSameChars = Traverse;
            int CountSimilarChar = 0;
            while ( LoopWithSameChars<chars.size() && chars[Traverse] == chars[LoopWithSameChars])
            {
                LoopWithSameChars += 1;
                CountSimilarChar += 1;
            }
            chars[KeepTrack++] = chars[Traverse] ;
            if ( CountSimilarChar > 1)
            {
                if ( CountSimilarChar > 9 )
            {
                while ( CountSimilarChar > 9 )
                {
                    int Quotient = CountSimilarChar / 10;
                    //char IntToChar = static_cast<char>(Quotient) ; static_Cast does not work here
                    
                    chars[KeepTrack++] =  Quotient + (int)'0';
                    CountSimilarChar %= 10 ;
                }
                chars[KeepTrack++] = CountSimilarChar + (int)'0' ;
            }
            else
                {
                    chars[KeepTrack++] = CountSimilarChar+(int)'0';
                }
            }
            Traverse = LoopWithSameChars - 1 ;
        }
        return KeepTrack ;
        
    }
};
