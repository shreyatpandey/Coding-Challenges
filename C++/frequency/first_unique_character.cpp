#include<bits/stdc++.h>
using namespace std;

class Solution
{
  public:
	int firstuniquechar(string s)
	{
	  vector<int>input_hold(26);
	  int flag_value = 0;
	  for(uint32_t i=0;i<s.length();i++)
	 {
	    input_hold[s[i]-'a']++;
	  }
	 for(uint32_t i=0;i<s.length();i++)
	{
	  if(input_hold[s[i]-'a'] == 1)
	  {
	    flag_value = 1;
	    return i;
	    break;
	  }
	}
if(flag_value == 0)
return -1;  
}
	int firstuniquechar_2(string s)
	{
		map<char,int>hash_map ;
	    for(int i=0;i<s.length();i++)
	    {
		hash_map.emplace(s[i],0);
		auto it = hash_map.find(s[i]);
		++it->second;
		hash_map.emplace(s[i],it->second);
	    }
		for(auto& x:hash_map)
	    {
		if(x.second == 1)
		{
		    size_t index_found = s.find(x.first);
		    cout<<"index_found_at:"<<index_found<<endl;
		    cout<<"first_non_repeating_character:"<<x.first<<endl;
		    return index_found;
		}
	    }
		return -1;	
	}

};
int main()
{
 Solution s;
 uint32_t hold_result;
  string input = "loveleetcode";
 hold_result = s.firstuniquechar(input);
 hold_result == -1 ? (cout<<"no_unique_character"<<endl):(cout<<"first_unique_character:"<<hold_result<<endl);
return 0;
}
