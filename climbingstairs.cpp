#include<bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    int climbstairs(int num)
   {
      if(num<0||num == 0)
        return 0;

      if(num == 1)
      return 1;
   
      if(num>1)
      return ((num-1) + (num-2));
   }
};

int main()
{
    Solution s;
    cout<<"Maximum_stair_climb:"<<s.climbstairs(3)<<endl;
   return 0;
}
