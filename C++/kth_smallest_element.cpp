#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	int kthsmallestelementmatrix_binarysearch(vector<vector<int>>&input,int k)
	{
	  uint32_t length = input.size();
	  size_t begin_element = input[0][0];
	  size_t last_element = input[length-1][length-1];
	  while(begin_element <= last_element)
	 {
	  int count_increment = 0;
	  int mid_value = begin_element + (last_element - begin_element)/2;
	  for(int search_row = 0; search_row < length; search_row += 1)
	  count_increment = count_increment + upper_bound(input[search_row].begin(),input[search_row].end(),mid_value) - input[search_row].begin();
	  (count_increment < k) ? (begin_element = mid_value + 1) : (last_element = mid_value - 1);
	
	}
	return begin_element;
	}
	int kthsmallestelementmatrix_priorityqueue(vector<vector<int>>&input,int k)
	{
	  int length = input.size();
	//  int row = 0;
	 // int cols = 0;
	  priority_queue<int,vector<int>,greater<int>>pq; //min-heap
	  for(int row=0;row<length;row +=1 )
	  {
	   for(int cols= 0;cols<length;cols +=1 )
		{
		  pq.push(input[row][cols]);
		
	}
	}
	while(--k)
	{
	// k -=1;
	  pq.pop();
	}
	return pq.top();
	}

};


int main()
{
  vector<vector<int>>input{{1,5,9},{10,11,13},{12,13,15}};
  Solution s;
  cout<<"kth_smallest_element_sorted_matrix_binarysearch:"<<s.kthsmallestelementmatrix_binarysearch(input,8)<<endl;
  cout<<"kth_smallest_element_sorted_matrix_priorityqueue:"<<s.kthsmallestelementmatrix_priorityqueue(input,8)<<endl;
	 
  return 0;
}

