class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = 0;
        reverse(num1.begin(),num1.end()) ;
        reverse(num2.begin(),num2.end()) ;
        int MaxOfTwoLength = max(num1.size(),num2.size());
        string AddStringResult = "";
        int carry = 0;
        while ( i <= MaxOfTwoLength-1 )
        {
            int digit1 = 0 , digit2 = 0 ;
            if ( i <= num1.size()-1) 
            {
                digit1 = num1[i] - (int)'0' ;
            }
            if ( i<=num2.size() - 1) 
            {
                digit2 = num2[i] - (int)'0' ;
            }
            int DigitResult = digit1 + digit2 + carry ;
            int Remainder = DigitResult % 10 ;
            AddStringResult += (Remainder + (int)'0') ;
            carry = DigitResult/10 ;
            i += 1;
        }
        if ( carry ) AddStringResult +='1';
        reverse(AddStringResult.begin(),AddStringResult.end());
        return AddStringResult ; 
        
        
    }
};
