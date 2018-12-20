class Solution {
public:
    string reverseString_1(string s) {
        int total_length = s.length()-1;
        char temp_store;
        for(int i=0;i<(total_length/2);i++)
        {
            temp_store = s[total_length-i];
            s[total_length-i] = s[i];
            s[i] = temp_store;
        }
        return s;
    }
    string reversestring_2(string s)
    {
        int total_length = s.length()-1;
        char temp_store;

        for (int i=0, j=total_length; i<j; i++,j--) 
            swap(s[i],s[j]);

        return s;
    }
};