/*This program is another way to implement atoi*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    string addStrings(string num1,string num2)
  {
     string result;
     int sum1=0,sum2=0;
     int size1 = num1.length();
    int size2 = num2.length();
    
    for(size_t i=0;i<size1;++i)
     {
       int result1=(int)num1[i] - (int)'0';
       sum1+= result1*pow(10,size1-i-1);
       
      }
   for(size_t j=0;j<size2;++j)
   {
     int result2 = (int)num2[j]-(int)'0';
     sum2+=result2*pow(10,size2-j-1);
    }
   int integer_result = sum1 + sum2;  
   int remainder=0;
  int string_value = integer_result;
  while( string_value!=0)
  {
     remainder = string_value%10;
     string_value = string_value/10;
     result.insert(result.begin(),(char)(0x30 + remainder));
  }
 return result;
 }
};
int main()
{
   string s1="105";
   string s2="420";
    
   Solution s;
   string final_result = s.addStrings(s1,s2);
   cout<<"Final_result_string:"<<final_result<<endl;
   return 0;

}
   
   


