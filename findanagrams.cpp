#include<bits/stdc++.h>
using namespace std;

/* Sliding window algorithm */
class Solution
{
   public:
    vector<int>findAnagrams(string s,string p)
   {
      vector<int>main_string(s.length()),sub_string(s.length()), result;
      for(size_t i=0;i<p.length();++i)
    {
         ++main_string[s[i]-'a'];/*pattern_matching_counter*/
         ++sub_string[p[i]-'a']; /*sliding_window_counter*/
         
     }
   if(main_string == sub_string)/*these two would be equal if they have the same content in any order but vector should be of equal length */
 { result.push_back(0);}
   
   for(size_t j=p.length();j<s.length();++j)
   {
    ++main_string[s[j]-'a'];/*this will insert the value of s[j]-'a' in main_string */
   --main_string[s[j-p.length()]-'a'];/* this will insert the valueof s[j]-p.length() - 'a' in main_string */
    if(main_string == sub_string)
    result.push_back(j-p.length()+1);
   }
 return result; 


}
};

int main()
{
 Solution s;
 string word1 = "cbaebabacd";
 string word2 = "abc";
 vector<int>hold_result;
 hold_result = s.findAnagrams(word1,word2);
 cout<<"[";
 for(size_t i=0;i<hold_result.size();i++)
  {
     cout<<hold_result[i];
       if(i!=hold_result.size()-1)
        cout<<",";
   }
 cout<<"]";
  cout<<endl;
 
  return 0;
}
