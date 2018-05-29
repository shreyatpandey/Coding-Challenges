#include<bits/stdc++.h>
using namespace std;


class Solution
{
  public:
  bool hasAlternatingBits(int n)
  {
    size_t new_number = n;
    size_t remainder = 0;
    int flag=0;
    vector<int>result;
    while(new_number)
    {
      remainder = new_number%2;
      new_number = new_number/2;
      result.push_back(remainder) ;
     }
   for(size_t i=0;i<result.size();i++)
   {
     if(!((result[i]==0 && result[i+1] == 1)||(result[i] == 1 && result[i+1] == 0)))
       { 
           flag =1;
           break;
        }
     }
   if(flag == 0)
    return true;
   else
   return false;
}
};

int main()
{
   Solution s;
   cout<<"Is_Alternating_Bits:"<<boolalpha<<s.hasAlternatingBits(10)<<endl;
   return 0;
}

       
