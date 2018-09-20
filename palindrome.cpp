#include<bits/stdc++.h>
using namespace std;

class Solution
{
 public:
	bool palindrome_string_1(string s)
	{
	  size_t str_length = s.length()-1;
	  int flag=0;	
	  for(int i=0;i<s.length();i++)
	  {
		if(s[i] != s[str_length--])
		{
		  flag = 1;
		  break;
		}
	}
	return ((flag == 0)?true:false);
	}
	bool palindrome_string_2(string s)
	{
	  string hold(s);
          reverse(hold.begin(),hold.end());	
	  return ((hold == s)? true:false);
	}
	bool palindrome_number(int input)
	{
	  if(input<0)
	  {
	    return false;
	    exit(1);
	  }
	  size_t hold = input;
	  size_t hold_1 = input;
	  size_t result = 0;
	  int count = 0;
	  while(hold)
	{
	 hold /= 10;
	count += 1;
	}
	int i = count;
	 while(hold_1)
	{
	  int remainder = hold_1%10;
	  hold_1 /= 10;
	  result += (remainder*pow(10,i-1));
	  i--;
	}
	return ( (result == input) ? true: false );
      }
	  
	
};

int main()
{
  string input = "nitin";
  Solution s;
  cout<<"is_palindrome_1:"<<boolalpha<<s.palindrome_string_1(input)<<endl;
  cout<<"is_palindrome_2:"<<boolalpha<<s.palindrome_string_2(input)<<endl;
  cout<<"palindrome_number:"<<boolalpha<<s.palindrome_number(121)<<endl;	 
return 0;
}

