#include<bits/stdc++.h>
using namespace std;

class Solution
{
  public:
   bool containDuplicates(vector<int>& nums)
    {
      int flag=0;
      for(int i=0;i<(nums.size());++i)
       {
         for(int z=0;z<i;++z)
          {
             if(nums[i] == nums[z]) 
            {flag=1;
            break;
           }

     }
   }
   if(flag == 1)
   return true;
   else
   return false;
 }
};



int main()
{
    vector<int>v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(1);
    bool result;
    Solution s;
    result = s.containDuplicates(v);
    cout<<"Result:"<<boolalpha<<result<<endl;
  return 0;
}
