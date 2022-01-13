class Solution {
public:
    int myAtoi(string str) {
      const int stringLength = input.length();
        int index = 0;
        while(input[index] == ' ')
        {
            index += 1;
        }
        if(index == stringLength)
        {
            return 0;
        }
        bool isNegative = false;
        if(input[index]=='-')
        {
            isNegative = true;
            index += 1;
        }
        else if(input[index]=='+')
        {
            index += 1;
        }
        int result = 0;
        while(index<stringLength && isdigit(input[index]))
        {
            int Number = input[index]-'0';
            if(result>INT_MAX/10 || (result == INT_MAX/10 && Number>7))
            {
                return isNegative ? INT_MIN : INT_MAX;
            }
            result = (result*10) + Number;
            index += 1;
        }
        

        return isNegative?(-1)*result : result ;
    }

};
