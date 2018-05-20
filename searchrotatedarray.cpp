#include<bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    int search(vector<int>&nums,int target)
    {
      int low=0;
      int high = nums.size()-1;
      while(low<=high)
    {
       int mid = low + (high-low)/2;
       if(nums[mid] == target)
        return mid;
    else if(nums[low]<=nums[mid])
     {
       if(nums[low]<=target && nums[mid]>target)
        high = mid-1;
       else
       low = mid + 1;
     }
   else
   {
      if(nums[mid] < target && nums[high]>=target)
      low = mid +1;
      else
      high = mid-1;
   }
 }
}
};
int main()
{
   Solution s;
   vector<int>input;
   input.push_back(4);
   input.push_back(5);
   input.push_back(6);
   input.push_back(7);
   input.push_back(0);
   input.push_back(1);
   input.push_back(2);
   int index_result = s.search(input,4);
   cout<<"Found at:"<<index_result<<endl;
   return 0;
}

       
     
