class Solution {
public:
    bool rotateString(string A, string B) {
        if (A.length() == 0 && B.length() == 0)
            return true;
        int length_one = A.length();
        if(length_one == B.length() && length_one>0)
        {
            string concatenate = A + A;
            if ( concatenate.find(B) != string::npos)
            {
                return true;
            }
        }
        return false;
        
    }
};


/*Solution-2  kmp*/
class Solution {
private:
    int* buildLPS(string s)
    {
       // cout<<"string_s:"<<s<<endl;
        int* lps = new int[s.length()];
        lps[0] = 0;
        int i = 1, j = 0;
        while(i < s.length())
        {
            if(s[i] == s[j])
            {
                cout<<"s[i] == s[j] :"<<s[i]<<endl;
                lps[i] = j + 1;
                i++;
                j++;
            }
            else
            {
                    if(j != 0) 
                {    
                    j = lps[j-1];
                
                }
                 else
                {
                    lps[i] = 0;
                    i++;
                }
            
            }
        
        }
        return lps;
    }
    bool kmp(string a, string b)
    {
        //cout<<"string a:"<<a<<endl; //concatenate string
        int* lps = buildLPS(b);
        int i = 0, j = 0;
        while(i < a.length() and j < b.length())
        {
                if(a[i] == b[j])
            {
                cout<<"a[i] == b[i] :"<<a[i]<<endl;
                cout<<"i:"<<i<<endl;
                cout<<"j:"<<j<<endl;
                i++;
                j++;
            }
            else
            {
                if(j == 0) 
                    i++;
                else 
                    j = lps[j-1];
            }
        
        }
       // cout<<"final_i_value:"<<i<<endl;
        //cout<<"final_j_value:"<<j<<endl;
        return j == b.length();
    }
public:
    bool rotateString(string A, string B) 
    {
        return (A.length() == 0 and B.length() == 0) or (A.length() == B.length() and kmp(A+A, B));
    }
};
