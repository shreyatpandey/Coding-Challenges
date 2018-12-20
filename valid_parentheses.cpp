class Solution {
public:
    bool isValid(string s) {
        if(s.length() == 1|| s.length()%2!=0)
        {
            return false;
        }
        if(s.length() == 0)
            return true;
        vector<char>count;
        vector<char>closing_bracket = {'}',')',']'};
        int flag = 1;
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == '{' || s[i] == '(' || s[i] == '[')
                count.push_back(s[i]);
            if(count.empty())
                return false;
            if(s[i] == closing_bracket[0])
            {
                char temp_store = count.back();
                count.pop_back();
                if(temp_store == '(' || temp_store == '[')
                    flag = 0;
            }
            if(s[i] == closing_bracket[1])
            {
                char temp_store = count.back();
                count.pop_back();
                if(temp_store == '{'|| temp_store == '[')
                    flag = 0;
            }
            if(s[i] == closing_bracket[2])
            {
                char temp_store = count.back();
                count.pop_back();
                if(temp_store == '('|| temp_store == '{')
                    flag = 0;   
            }       
        }
        
        if(count.size()!=0 || flag != 1)
            return false;
        else
            return true;
    }
};