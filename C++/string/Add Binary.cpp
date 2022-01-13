//TC:- O(n)
//SC:- O(1)
class Solution {
public:
    string addBinary(string a, string b) {
        string Result = "";
        const int Length1 = a.size();
        const int Length2 = b.size();
        int MaxLength = max(Length1,Length2);
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int i = 0;
        int carry = 0;
        while(i<=MaxLength-1)
        {
            int Digit1=0,Digit2 = 0;
            if(i<= Length1-1)
            {
                Digit1 = a[i]-(int)'0';
            }
            if(i<=Length2-1)
            {
                Digit2 = b[i]-(int)'0';
            }
            size_t sum = Digit1 + Digit2 + carry;
            carry = sum/2;
            sum = sum % 2;
            Result += sum + (int)'0';
            i += 1;
        }
        if ( carry) Result += '1';
        reverse(Result.begin(),Result.end());
        return Result;
        
    }
};
