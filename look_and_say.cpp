#include<bits/stdc++.h>
using namespace std;

class Solution
{
 public:
	string happy_say(int n)
  {
	if(n==1)
	return "1";
	if(n ==2 )
	return "11";

	string str = "11";

	for(int i=3; i<=n ; i++)
	{
	  str += '$';
	  int string_length = str.length();
	  int count = 1;
	  string temp = "";
	 			 
	  for(int j=1;j<string_length;j++)
	{
	  if(str[j] != str [j-1])
	  {
		temp += count + '0';
		temp += str[j-1]; 
		count = 1;
	  }
	  else
	  count +=1;
	}
	str = temp ;
	}
 	return str;
}
};


int main()
{
	Solution s;
	string result = s.happy_say(4);
	cout<<"result_number:"<<result<<endl;
	return 0;
}
	
