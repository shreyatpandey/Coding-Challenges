using MultipliedString = vector<int> ;
class Solution {
public:
    string multiply(string num1, string num2) {
        unsigned int LenStr1 = num1.size() ;
        unsigned int LenStr2 = num2.size() ;
        if (LenStr1 == 0 || LenStr2 == 0)
            return "0";
        MultipliedString multipliedstr(LenStr1 + LenStr2,0) ;
        for(int i=LenStr1-1;i>=0;i--)
        {
            int Number1 = (int)num1[i] -(int)'0';
            int Carry = 0;
            for(int j=LenStr2-1;j>=0;j--)
            {
                int Number2 = (int)num2[j] - (int)'0';
                int Product = Number1*Number2 + multipliedstr[(LenStr1-1-i)+(LenStr2-1-j)] + Carry;
                Carry = Product/10;
                multipliedstr[(LenStr1-1-i) + (LenStr2-1-j)] = Product%10;
            }
            if ( Carry> 0)
            {
                multipliedstr[LenStr2+ (LenStr1-1-i)] += Carry ;
            }
        }
        reverse(multipliedstr.begin(),multipliedstr.end());
        int ZeroTrackAtBeginning = 0;
        while ( ZeroTrackAtBeginning != multipliedstr.size() && multipliedstr[ZeroTrackAtBeginning] == 0)
        {
            ZeroTrackAtBeginning += 1;
        }
        if ( ZeroTrackAtBeginning == multipliedstr.size() ) return "0" ;
        string Result = "";
        for(;ZeroTrackAtBeginning <=multipliedstr.size()-1 ; ZeroTrackAtBeginning++)
        {
            Result += multipliedstr[ZeroTrackAtBeginning] + (int)'0';
        }
        return Result;
        
    }
};
