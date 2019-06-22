#include<bits/stdc++.h>
using namespace std;

class Solution
{
  public:
	vector<string> token_list(string input)
	{
	  string delimiter = "_";
	  size_t position = 0;
	  string token;
	  vector<string> store_split_string;
	  vector<string> final_token_list;
	  while((position = input.find(delimiter))!= string::npos)
	  {
	    token = input.substr(0,position);
	    store_split_string.emplace_back(token);
	    input.erase(0,position + delimiter.length());
	
          }
	uint32_t l=0;
	for(uint32_t j=0;j<store_split_string.size();j +=1)
	{
	   final_token_list.emplace_back(store_split_string[j]);
	  for (uint32_t k=j+1;k<store_split_string.size(); k +=1)
	  {
	   string concat_token = final_token_list[l] + '_' + store_split_string[k];
	   final_token_list.emplace_back(concat_token);
	   l +=1;
	  }
	 l = final_token_list.size();
	 }
	    	
	 return final_token_list;
	}


};

int main()
{
	string input = "1a_2a_3a_4a_5a";
	Solution s;
	vector<string>output;
	output = s.token_list(input);
	int i=0;
	cout<<"[";
	for(;i<output.size();i +=1)
	{
          cout<<output[i];
	  if(i != output.size() -1 )
	    cout<<",";
	}
	cout<<"]"<<endl;
	   		
	
return 0;
}
