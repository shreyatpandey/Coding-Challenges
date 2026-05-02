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
        int index = 0;
        for(int i=0;i<chars.size();i++)
        {
            char temp = chars[i];
            int j = i+1;
            int count = 1;
            while(j < chars.size() && chars[j] == temp)
            {
                count += 1;
                j ++;
            }
            chars[index++] = temp;
            if (count >1)
            {
                if(count>9)
                {   
                    string result = to_string(count);
                    for(int i=0;i<result.size();i++)
                    {
                        chars[index++] = result[i];
                    }
                }
                else
                {
                    chars[index++] = count + (int)'0';
                }
            }
            i = j - 1;
        }
        return index;
    }
};
