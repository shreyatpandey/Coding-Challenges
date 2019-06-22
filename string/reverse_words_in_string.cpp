class Solution {
public:
    string reverseWords(string s) {
        // Reverse the whole string first.
        reverse(s.begin(), s.end());

        size_t begin = 0, end = 0, len = 0;
        while ((begin = s.find_first_not_of(" ", end)) != string::npos) {
            cout<<"begin_index:"<<begin<<endl;
            if ((end = s.find(" ", begin)) == string::npos) 
            {
                cout<<"this is last:"<<end<<endl;
                end = s.length();
                cout<<"end_index_after:"<<end<<endl;
            }
            cout<<"end_index_not_if_condition:"<<end<<endl;
            // Reverse each word in the string.
            reverse(s.begin() + begin, s.begin() + end);

            // Shift the word to avoid extra space.
            move(s.begin() + begin, s.begin() + end, s.begin() + len);
            len += end - begin;
            cout<<"len:"<<len<<endl;
            s[len++] = ' ';
        }
        s.resize(len ? len - 1 : 0); /*test case of " hello world! " fails */
        cout<<"s:"<<s<<endl;
        string ret_str = s;
        return ret_str;
    }
  
