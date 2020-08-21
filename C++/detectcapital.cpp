#include<bits/stdc++.h>
using namespace std;

bool checkUpperCase(char ch)
{
   if((int)ch>=65 && (int)ch<=90)
   return true;
   else
   return false;
 
}


class Solution
{
   public:
   bool detectCapitalUse(string word)
   {
     int size=word.length();
     size_t i,count=0;
     for(i=0;i<size;i++)
     {
      char ch = word[i];
      bool result = checkUpperCase(ch);
      if(result)
      {
        count+=1;
      }
     }
    bool start_result = checkUpperCase(word[0]);
    cout<<"Start_result:"<<boolalpha<<start_result<<endl;
    if(start_result)
    {
      if(count==1||count == size)
      {return true;}
    
      return false;
    }
   if(!start_result)
   {
     return false;
    }

  else
  {
    if(count==0)
    {return false;}   
    
   return true;
  }
   
 }
};

int main()
{
 Solution s;
 bool final_result;
 string str = "fLaG";
 final_result = s.detectCapitalUse(str);
 cout<<"Final result:"<<boolalpha<<final_result<<endl;

 return 0;

}
