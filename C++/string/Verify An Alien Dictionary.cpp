class Solution {
    private:
        bool CheckWordsAreSame(string One, string Two);
        unordered_map<char,int>AlphaToIndex;
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0;i<order.length();i++)
        {
            AlphaToIndex[order[i]] = i;
        }
        for(int i=0;i<words.size()-1;i++)
        {
            if ( CheckWordsAreSame(words[i],words[i+1]) == false)
                return false;
        }
        return true;
        
    }
};
bool Solution::CheckWordsAreSame(string One,string Two)
{
    
    for(int j=0;j<min(One.length(),Two.length());j++)
    {
        if ( AlphaToIndex[One[j]] > AlphaToIndex[Two[j]] )
            return false;
        else if ( AlphaToIndex[One[j]] < AlphaToIndex[Two[j]])
            return true;
    }
    if ( One.length() > Two.length()) /* Edge Case:- [apple,app] */
        return false;
    return true;
}
