#include<bits/stdc++.h>
using namespace std;

class Solution
{
 public:
bool isMonotonic(vector<int>& A)
{
   bool check_increasing = true;
      bool check_decreasing = true;
	  for(int i=0;i<A.size()-1;i += 1)
	 {
	    if(A[i] > A[i+1])
            check_increasing = false;
         if(A[i] < A[i+1])
             check_decreasing = false;
    
     }
        return (check_increasing || check_decreasing);
  }    
};


