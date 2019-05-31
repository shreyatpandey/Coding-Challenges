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

/*Solution- Time Limit Exceeded */
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
     vector<int>result;
    if (s.length() < p.length())
        return result; 
      map<char,int>anagram_string;
        for (int c = 0;c<p.length();c++)
        {
            if (anagram_string.find(p[c]) != anagram_string.end())
            {
                anagram_string[p[c]]++;
            }
            else
            { anagram_string[p[c]] = 1;}
        }
        for(int i=p.length()-1;i<s.length();i++)
        {
            string input = s.substr(i-(p.length()-1),p.length());
            map<char,int>match_string;
            for(int i=0;i<input.length();i++)
            {
                if (match_string.find(input[i]) != match_string.end())
            {
                    ++match_string[input[i]];
            }
                else
                {match_string[input[i]] = 1;}
            }
            int flag = 1;
            for(auto&x : match_string)
            {
                if( !(anagram_string.find(x.first) != anagram_string.end()))
                {
                    flag = 0;
                    break;
                } 
                else if(anagram_string.find(x.first) != anagram_string.end())
                {
                    if(anagram_string[x.first] != x.second)
                    {
                        flag = 0;
                        break;
                    }
                }
            }
            if (flag)
            {
                result.emplace_back(i-(p.length()-1));
                
            }
                
        }
       
       return result;
    }
};
