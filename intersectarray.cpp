#include<bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    vector<int> intersection(vector<int>& num1,vector<int>&num2)
    {
      vector<int>result;
      sort(num1.begin(),num1.end());
      sort(num2.begin(),num2.end());
      int i=0,j=0;
      int k=0;
      while(i<num1.size() && j<num2.size())
      {
        if(num1[i] < num2[j])
        { i++;}
       else if (num1[i] > num2[j])
       {j++;}
     else
      {
          if(result.empty())
          result.push_back(num2[k++]);

         i++;
         j++;
      }
  }
 return result;
}
};




int main()
{
   vector<int>v1; 
   vector<int>v2;
   v1.push_back(1); 
   v1.push_back(2);
   v1.push_back(2);
   v1.push_back(1);
   v2.push_back(2);
   v2.push_back(2);   
   Solution s;
   vector<int>result;
   result=s.intersection(v1,v2);
   cout<<"Size of result is:"<<result.size()<<endl;  
   cout<<"[";
   for(int i=0;i<result.size();++i)
   
{ 
  cout<<result[i]<<" ";
}
  cout<<"]"<<endl;
  cout<<endl;
  return 0;
}   


