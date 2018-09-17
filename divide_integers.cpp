#include<bits/stdc++.h>
using namespace std;

class Solution
{
 public:
  int divide(int dividend,int divisor)
  {
	//check for error cases
	if(!(divisor)||dividend == INT_MIN && divisor == -1)
		return INT_MAX;
	int sign = ((dividend < 0)^(divisor<0))?-1:1;
	long long dividend_input = labs(dividend);//absolute_value_handle_(-ve)
	long long divisor_input = labs(divisor);//absolute_value_handle_(-ve)
	int result = 0;
	while(dividend_input >= divisor_input)
	{
	 long long temp = divisor_input, multiple = 1;
	 while(dividend_input >=(temp<<1))
	{
	 temp<<=1;
	 multiple<<=1;
	}
	divisor_input -=temp;
	result +=multiple;
	}
	return sign == 1 ? result : -result;
 }
};

int main()
{
 Solution s;
 cout<<"Divide_result:"<<s.divide(7,-3)<<endl;
 return 0;
}
	
	
