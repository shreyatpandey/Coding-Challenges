#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool isAnagram(string s, string t)
   {
        if(s.length()!=t.length())
         return false;
   
       sort(s.begin(),s.end());
       sort(t.begin(),t.end());

      return (s == t);     
   
    }

};



/*single-hash map */

bool isAnagram(char * s, char * t)
{
    int frequency_count[27] = {0};
    for(int i=0;i<strlen(s);i++)
    {
        frequency_count[s[i]-'a']++;
    }
    for(int i=0;i<strlen(t);i++)
    {
        frequency_count[t[i]-'a']--;
    }
    for(int i=0;i<26;i++)
    {
        if(frequency_count[i] != 0)
            return false;
    }
    return true;

}


