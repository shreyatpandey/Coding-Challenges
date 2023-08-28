#include<bits/stdc++.h>
using namespace std;

/*
   TC:- 
   Best-Case:- O(nlog(n))
   Average-Case:- O(nlog(n))
   Worst - Case:- O(n^2)
*/
// SC:- O(log(n))

class Solution
{
   public:
   void quicksort(vector<int>&nums,int start,int end)
   {
     size_t left = start;
     size_t right = end;
     size_t mid_value = left + (right-left)/2;
     size_t pivot = nums[mid_value];
     while(left<=right)
     {
       while(left<=right && nums[left]<pivot)
       {
           left+=1;
       }
      while(left<=right && nums[right]>pivot)
     {
        right-=1;
      }
     if(left<=right)
     {
       swap(nums[left],nums[right]);
       left+=1;
       right-=1;
     }
}
    if(right>start)
    quicksort(nums,start,right);
   if(left<end)
   quicksort(nums,left,end);    

}
};

int main()
{
   Solution s;
   vector<int>input = {10,7,8,9,1,5};
   s.quicksort(input,0,input.size()-1);
   cout<<"[";
   for(size_t j=0;j<input.size();j++)
  {
    cout<<input[j];
    if(j!=input.size()-1)
     cout<<",";
   }
  cout<<"]"<<endl;
   
   return 0;
}

      
