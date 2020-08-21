// TLE for this case
class Solution {
    private:
        bool CheckPalindrome ( string s ) ;
public:
    bool validPalindrome(string s) {
     int StringLength = s.size() ;
    for ( int i =0 ; i<StringLength ; i++)
    {
        char temp = s[i] ;
        s.erase(s.begin()+i) ;
        if ( CheckPalindrome (s))
            return true ;
        s.insert(s.begin()+i,temp) ;
        
    }
     return false;   
    }
};

bool Solution :: CheckPalindrome ( string input)
{
    for(int i=0;i<input.length()/2 ; i++)
    {
        if ( input[i] != input[input.length()-i-1])
            return false;
    }
    return true ;
    
}

//Works - faster than 86.33 %
class Solution {
    private:
        bool CheckPalindrome ( string s,int i, int j ) ;
public:
    bool validPalindrome(string s) {
        for (int i = 0; i < s.length() / 2; i++)
        {
            if (s.at(i) != s.at (s.length() - 1 - i) ) 
            {
                int j = s.length() - 1 - i;
                return (CheckPalindrome (s, i+1, j) ||
                        CheckPalindrome (s, i, j-1));
            }
        }
        return true;
    }
};

bool Solution::CheckPalindrome( string input, int i, int j)
{
   for (int k = i; k <= i + (j - i) / 2; k++) {
            if (input[k] != input[j - k + i]) 
                return false;
        }
        return true;
    
}
