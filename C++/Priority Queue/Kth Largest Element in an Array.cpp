#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	int findkthlargest_sorting(vector<int>&input,int k)
	{
	
	  sort(input.begin(),input.end(),greater<int>()); //descending sorting
	  return input[k-1];
	}
	int findkthlargest_nthelement(vector<int>&input,int k)
	{
	  nth_element(input.begin(),input.begin()+k-1,input.end(),greater<int>()); return input[k-1];
	}

	int findkthlargest_minheap(vector<int>&input,int k)
	{
	  priority_queue<int,vector<int>,greater<int>>min_queue;
	  for(int i=0;i<input.size();i++)
	{
	  min_queue.push(input[i]);
	 if(min_queue.size() > k)
	{
	  min_queue.pop();
	}
	}
	return min_queue.top();
	}
	int findkthlargest_maxheap(vector<int>&input,int k)
	{
	  priority_queue<int>max_queue(input.begin(),input.end());
	  for(int i=0;i<k-1;i++)
	 {
	   max_queue.pop();
	}
	return max_queue.top();
	}	
	

};


int main()
{
	vector<int>input_vector{3,2,3,1,2,4,5,5,6};
	Solution s;
	cout<<"kthlargestelement_sorting:"<<s.findkthlargest_sorting(input_vector,4)<<endl;
	cout<<"kthlargestelement_nthelement:"<<s.findkthlargest_nthelement(input_vector,4)<<endl;
	cout<<"kthlargestelement_minheap:"<<s.findkthlargest_minheap(input_vector,4)<<endl;
	cout<<"kthlargestelement_maxheap:"<<s.findkthlargest_maxheap(input_vector,4)<<endl;
	
	return 0;
}
