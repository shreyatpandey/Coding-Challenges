class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int>hash_string;
        char temp;
        for(int i=0;i<s.length();i++)
        {
            hash_string[s[i]]++;
        }
        for(int i=0;i<t.length();i++)
        {
            hash_string[t[i]]--;
            if(hash_string[t[i]] == -1)
            {
                temp = t[i];
                return(temp);
            }
        
        }
        return temp;
    }
    char findthedifference_unique(string s,string t)
    {
     unordered_map<char,int>hash_string;
        char temp;
        for(int i=0;i<s.length();i++)
        {
            hash_string.emplace(s[i],i);
        }
        for(int i=0;i<t.length();i++)
        {
           
            if(!(hash_string.find(t[i]) != hash_string.end()))
            {
                temp = t[i];
                return(temp);
            }
        
        }
        return temp;
    
    }
    
};
