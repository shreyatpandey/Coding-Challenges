class Solution {
public:
    string toHex(int num) {
        if  ( num == 0 )
            return "0";
        string result = "";
        long Value = num < 0 ? (1LL << 32) + num : num;
        while(Value)
        {
            int remainder = Value%16;
            Value /= 16;
            if ( remainder > 9)
            {
                result += remainder + 87; //(int)'a' - 10
            }
            else
            {
                 result +=  remainder + 48; //(int)'48'
            }
        }
        reverse(result.begin(),result.end());
        return result;
        
    }
};
