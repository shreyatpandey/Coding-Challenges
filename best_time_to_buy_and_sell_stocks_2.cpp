#include<bits/stdc++.h>
using namespace std;

class Solution
{
 public:
	int maxProfit(vector<int>&input)
	{
	  size_t profit = 0;
	  if (!input.size())
	 {  return 0;}
	  for(int i=0;i<input.size();i++)
	  {
		if(input[i+1]>input[i])
		{
	
		 profit += input[i+1] - input[i];
		}
            }
 	return profit;
 	}
};

int main()
{
	int input[] = {7,1,5,3,6,4};
	int input_length = sizeof(input)/sizeof(input[0]);
	vector<int>input_value(input_length);
	input_value.insert(input_value.begin(),input,input+input_length);
	
	Solution s;
	cout<<"Max_Profit:"<<s.maxProfit(input_value)<<endl;
	return 0;
}

	
