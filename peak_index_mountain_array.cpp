#include<bits/stdc++.h>
using namespace std;

class Solution
{
  public:
	int peakindexmountainarray_1(vector<int>&v) /* O(n)-solution */
       {
         int i;
   	 for(i=1;i<v.size();i += 1)
	 {
	    if( (v[i-1] < v[i]) && (v[i]> v[i+1]))
	     return i;
	} 
       }
       int peakindexmountainarray_2(vector<int>&v)  /*O(log n)- solution */
       {
    	  int low = 0;
	  int high = v.size() - 1;
	 while(low < high) 
	 {
	   int mid_value = low + (high - low)/2 ;
	   if(v[mid_value] < v[mid_value + 1])
	     low = mid_value + 1;
	  else
	    high = mid_value ;
    	}
	return low;
      }
};

int main()
{
  Solution s;
  vector<int>input = {0,1,2,3,2,1};
  cout<<"Peak_Index_Mountain_Array_1:"<<s.peakindexmountainarray_1(input)<<endl;
  cout<<"Peak_Index_Mountain_Array_2:"<<s.peakindexmountainarray_2(input)<<endl;

   return 0;
}
