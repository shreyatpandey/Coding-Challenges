#include<bits/stdc++.h>
using namespace std;

/* Analysis of Time Complexity:-
   TC for Heapify:- O(log(n))
   There would be n calls to heapify:- TC = O(n*log(n))
   Best-Case = Average-Case = Worst-Case = O(n*log(n))
*/
/* 
   SC:- O(1)
*/

class Solution
{
   public:
	void heapify(vector<int>&input,int size,int i)
	{
	  int largest = i;
	  int left  = (2*i + 1);
	  int right = (2*i + 2);
	
	  if(left<size && input[left]>input[largest])
		largest = left;
	  if(right<size && input[right]>input[largest])
		largest = right;

	  if(largest != i)
	  {
		swap(input[i],input[largest]);
		heapify(input,size,largest);
	 }
	}
	void heap_sort(vector<int>&input,int size)
	{
	  for(int i = size/2-1;i>=0;i--)
		heapify(input,size,i);
	
	  for(int i=size-1;i>=0;i--)
	 {
		swap(input[0],input[i]);
	       heapify(input,i,0);
	}
	}
	void print_result(vector<int>&input)
	{
	   cout<<"[";
	   for(int i=0;i<input.size();i++)
	  {
	     cout<<input[i];
	     if(i != input.size()-1)
	      cout<<",";
	  }
	 cout<<"]"<<endl;
	}
};

int main()
{
    vector<int>input = {1,12,9,5,6,10};
     Solution s;
    s.heap_sort(input,input.size());
    s.print_result(input);
    return 0;
}
