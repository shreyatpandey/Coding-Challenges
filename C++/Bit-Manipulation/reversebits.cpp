#include<bits/stdc++.h>
using namespace std;

class Solution
{
 public:
  uint32_t reverseBits(uint32_t n)
  {
	uint32_t mask_bit = 1;
	uint32_t ret_value = 0;
	for(size_t i=0;i<32;i++)
	{
		ret_value<<=1;
		if(mask_bit & n)
		ret_value = ret_value | 1;
		
		mask_bit<<=1;
	}
     return ret_value;
 }
};

int main()
{
  Solution s;
  cout<<"Reversebits:"<<(s.reverseBits(43261596))<<endl;
  
   return 0;
}
