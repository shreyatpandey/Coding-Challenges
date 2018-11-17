#include<bits/stdc++.h>
using namespace std;

class Solution
{
 public:
  bool is_monotonic_array(vector<int>&input)
	{
	  int i ;
	  for(i=0;i<input.size();i += 1)
	 {
	  if( i != input.size()-1)
	{
	   if(((input[i]<=input[i+1] && input[i]>=input[i-1])) || ((input[i]>=input[i+1] && input[i]<=input[i-1])))
	      continue; 
	   else
		break;
	}
	 }
	return(i == input.size() ? true:false);
	}

};

int main()
{
 Solution s;
 vector<int>input = {1,2,4,5};
 cout<<"Is_Monotonic_Array:"<<boolalpha<<s.is_monotonic_array(input)<<endl;
 return 0;
}
