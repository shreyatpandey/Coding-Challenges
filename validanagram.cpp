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

int main()
{
  Solution s;
  cout<<"Is_it_valid_anagram:"<<boolalpha<<s.isAnagram("anagram","nagaram")<<endl;
  return 0;
}
