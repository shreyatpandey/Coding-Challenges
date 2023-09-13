//Best Solution
//TC:- O(n) where n is the length of string
//SC:- (n) where n is the length of input string
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string Result ;
        int Seen = 0;
        int Balance = 0;
        for(int i=0;i<s.length();i++)
        {
            char temp = s[i];
            if ( temp == '(')
            {
                Seen += 1;
                Balance += 1;
            }
            if ( temp == ')')
            {
                if ( Balance == 0 )
                    continue;
                Balance -= 1;
            }
            Result.push_back(temp);
        }
        string FinalResult ;
        int Diff = Seen - Balance ;
        for(int i=0;i<Result.length();i++)
        {
            char temp = Result[i];
            if ( temp == '(')
            {
                Diff -= 1;
                if ( Diff < 0 ) continue;
                
            }
            FinalResult.push_back(temp);
        }
        return FinalResult;
    }
};
