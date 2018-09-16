#include<bits/stdc++.h>
using namespace std;

class Solution
{
  public:
	int maxArea(vector<int>&height)
	{
	  size_t max_area = 0;
	  for(int i=0;i<height.size();i++)
	  {
		for(int j=i+1;j<height.size();j++)
	   {
		int min_height = min(height[i],height[j]);
		if(min_height*(j-i)>max_area)
		max_area = min_height*(j-i);
	    }
	}
	return max_area;
 }
};

int main()
{
 Solution s;
 int input[] = {1,8,6,2,5,4,8,3,7};
 int input_length = sizeof(input)/sizeof(input[0]);
 vector<int>input_vector(input_length);
 input_vector.insert(input_vector.begin(),input,input+input_length);
 cout<<"Max_Area:"<<s.maxArea(input_vector)<<endl;
return 0;
}
