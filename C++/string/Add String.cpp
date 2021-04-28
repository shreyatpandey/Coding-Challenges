/*This program is another way to implement atoi*/

//78.54% faster
//TC:- O(max(n1,n2))
class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = 0;
        reverse(num1.begin(),num1.end()) ;
        reverse(num2.begin(),num2.end()) ;
        int MaxOfTwoLength = max(num1.size(),num2.size());
        string AddStringResult = "";
        int carry = 0;
        while ( i <= MaxOfTwoLength-1 )
        {
            int digit1 = 0 , digit2 = 0 ;
            if ( i <= num1.size()-1) 
            {
                digit1 = num1[i] - (int)'0' ;
            }
            if ( i<=num2.size() - 1) 
            {
                digit2 = num2[i] - (int)'0' ;
            }
            int DigitResult = digit1 + digit2 + carry ;
            int Remainder = DigitResult % 10 ;
            AddStringResult += (Remainder + (int)'0') ;
            carry = DigitResult/10 ;
            i += 1;
        }
        if ( carry ) AddStringResult +='1';
        reverse(AddStringResult.begin(),AddStringResult.end());
        return AddStringResult ; 
    }
};







/* Will not work for INT_MAX , int overflow */
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

   
   


