#include<bits/stdc++.h>
using namespace std;
class Solution
{
	public:
		void permutation_string(vector<string>&store_result,string input,string output)
		{
			if(input.size() == 0)
			{
				store_result.push_back(output);
				return;
			}
			for(int i=0;i<input.length();i++)
			{
				permutation_string(store_result,input.substr(1),output + input[0]);
				rotate(input.begin(),input.begin()+1,input.end());
			}
		}

};
int main()
{
	 Solution s;
	 vector<string>hold_result;
	 string output=" ";
	 s.permutation_string(hold_result,"abcde",output);
	 cout<<"[";
	 for(int j=0;j<hold_result.size();j++)
	 {
	 	cout<<hold_result[j];
	 	if(j != hold_result.size()-1)
	 	{
	 		cout<<",";
	 	}

	 }
	 cout<<"]"<<endl;
	 return 0;
}
