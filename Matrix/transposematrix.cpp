#include<bits/stdc++.h>
using namespace std;

class Solution
{
   public:
	vector<vector<int>>transpose(vector<vector<int>>&A)
	{
	  vector<vector<int>>result(A.size());
	  size_t rows,cols;
	  if(A.size() == 0)
	  return vector<vector<int>>();
	  for(rows=0;rows<A.size();rows++)
 		for(cols = 0;cols<A[rows].size();cols++)
		{
                  result[cols].emplace_back(A[rows][cols]);
		}
     return result;
     }
};

int main()
{
   Solution s;
   vector<vector<int>>input{{1,2,3},{4,5,6},{7,8,9}};
   vector<vector<int>>result(input.size());
   result = s.transpose(input);
   size_t rows,cols;
   cout<<"[";
   for(rows=0;rows<input.size();rows++)
   {
    cout<<"[";
     for(cols=0;cols<input[rows].size();cols++)
      {
        cout<<result[rows][cols];       
        if(cols!= input.size()-1)
	cout<<",";
        }
     cout<<"]";
      
   if(rows!=input.size()-1)
   cout<<",";
    }
   cout<<"]"<<endl;

return 0;
}  	
