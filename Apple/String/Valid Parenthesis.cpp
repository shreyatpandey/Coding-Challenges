class Solution {
public:
    bool isValid(string s) {
        if(s.length() == 1|| s.length()%2!=0)
        {
            return false;
        }
        if(s.length() == 0)
            return true;
        stack<char>st;
        int i = 0;
        int flag = 0;
        while(i<s.length())
        {
            if(s[i] == '('||s[i] == '[' || s[i] == '{')
            {st.push(s[i]);}
            if(st.size() == 0)
            {
                return false;
            }
            if(s[i] == ')')
            {
                char temp = st.top();
                st.pop();
                if(temp != '(')
                {
                    flag = 1;
                    break;
                }
                
            }
             if(s[i] == ']')
            {
                char temp = st.top();
                st.pop();
                if(temp != '[')
                {
                    flag = 1;
                    break;
                }
                
            }
              if(s[i] == '}')
            {
                char temp = st.top();
                st.pop();
                if(temp != '{')
                {
                    flag = 1;
                    break;
                }
                
            }
            i += 1;
            
            
        }
        if (st.size() != 0 || flag == 1)
            return false;
        
        return true; 
    }
       
};
