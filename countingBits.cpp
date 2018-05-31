#include<bits/stdc++.h>
using namespace std;

/*Naive approach*/
int hammingweight(uint32_t n)
  {
   vector<int>result;    
   int new_number = n;
   int i=0,count = 0;
   if (n==0)
   return 0;

   else
   {
      while(new_number)
     {
       int remainder = new_number%2;
       new_number = new_number/2;
       result.push_back(remainder);
       i++;
      }
    }
   for(i=0;i<result.size();i++)
   {
     if(result[i] == 1)
      count+=1;
    }
  return count;
}

class Solution
{
  public:
   vector<int> countBits(int num)
   {
     vector<int>result;
     int k=0;
     while(k<= num)
     {
       int store_result = hammingweight(k);
       result.push_back(store_result);
       k++;
     }
    
     return result;

}
};

int main()
{
   Solution s;
   vector<int>input;
   input=s.countBits(5);
   vector<int>::iterator it;
   cout<<"[";
   for(it=input.begin();it!=input.end();++it)
    {
      cout<<(*it);
     if(it!=input.end()-1)
     {
       cout<<",";
     }
    }
  cout<<"]";
  cout<<endl;
  return 0;
}
