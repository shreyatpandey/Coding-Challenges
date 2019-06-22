class Solution {
public:
    int myAtoi(string str) {
        if(str.length() == 0)
            return 0;
        int sign = 1;
        int flag_both_positive = 0;
        int flag_both_negative = 0;
        int index_space = str.find_first_not_of(' ');
        if(str[index_space] == '-')
        {
            flag_both_negative = 1;
            sign = -1;
            index_space++;
            str.substr(index_space);
        }
        if(str[index_space] == '+')
        {
            flag_both_positive = 1;
            index_space++;
            str.substr(index_space);
        }
        if(flag_both_positive && flag_both_negative)
        {
            return 0;
        }
       
        int length_string = str.length();
        long result = 0;
        for(int i=index_space;i<length_string &&('0'<=str[i] && str[i]<='9');i++)           
        {
            int remainder = (int)str[i] - (int)'0';
            //result += remainder*pow(10,length_string-i-1);
            result = result * 10 + remainder;
            if(result*sign > INT_MAX)
                return INT_MAX;
            if(result*sign < INT_MIN)
                return INT_MIN;
            
        }
        return (result*sign);

        }
};
