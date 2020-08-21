#include<bits/stdc++.h>
using namespace std;

class Solution
{
  public:
   bool repeatedSubstringPattern(string s) 
 {
   int string_size = s.length();
   for(int i = string_size/2;i>=1;i--)
   {
     if(string_size%i == 0)
     {
      int m = string_size / i;
      string substring_first = s.substr(0,i);
      string final_substring;
      for(int j=0;j<m;j++)
	{
           final_substring.append(substring_first);
	}
     if(final_substring == s)
	return true;
   }
 }
return false;
}
};

int main()
{
  Solution s;
  cout<<"Repeadd_Substring_Pattern:"<<boolalpha<<s.repeatedSubstringPattern("abcabcabc")<<endl;
  return 0;
}
