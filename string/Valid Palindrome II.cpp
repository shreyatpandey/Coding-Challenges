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
