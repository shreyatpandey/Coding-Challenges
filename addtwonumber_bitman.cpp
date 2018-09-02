#include<bits/stdc++.h>
using namespace std;

class Solution
{
  public:
	int getsum_1(int a,int b)
	{
  		int get_sum = a;
		while(b!=0)
		{
			get_sum = a^b;
			b = (a&b)<<1;// left shift or multiplying by power of 2 
			a = get_sum;
		}
	return get_sum;
	}
	int getsum_2(int a,int b)
	{
      	 return (b == 0? a:getsum_2(a^b,(a&b)<<1));
	}
};

int main()
{
  Solution s;
  size_t result_1 = s.getsum_1(1,2);
  cout<<"result_1:"<<result_1<<endl;
  size_t result_2 = s.getsum_2(1,2);
  cout<<"reuslt_2:"<<result_2<<endl;

  size_t result_3 = s.getsum_1(-2,3);
  cout<<"result_3:"<<result_3<<endl;
  size_t result_4 = s.getsum_2(-2,3);
  cout<<"result_4:"<<result_4<<endl;

  return 0;
}
		
				
