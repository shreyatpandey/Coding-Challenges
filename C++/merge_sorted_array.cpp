#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	void merge_sorted_array(vector<int>&nums1,int m,vector<int>&nums2,int n)
	{
	  nums1.erase(nums1.begin()+m,nums1.end());
	  for(int i=0;i<n;i++)
	 {
	   nums1.emplace_back(nums2[i]);
	 }
	sort(nums1.begin(),nums1.end());
	
	}

};

int main()
{
	vector<int>nums1 = {1,2,3,0,0,0};
	vector<int>nums2 = {2,5,6};
	Solution s;
	int length_vector_2 = nums2.size();
	s.merge_sorted_array(nums1,3,nums2,length_vector_2);
	cout<<"[";
  	for(int i=0;i<nums1.size();i++)
	{
	  cout<<nums1[i];
	  if(i != nums1.size()-1)
	  cout<<",";
	}
	cout<<"]"<<endl;
}	
