#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        void print_character_frequency(string s)
        {
            unordered_map<char,int>hash;
            for(int i=0;i<s.size();i++)
            {
                hash.insert(pair<char,int>(s[i],0));
                auto it = hash.find(s[i]);
                ++it->second;
                hash.insert(pair<char,int>(s[i],it->second));
            }
            for(auto const &p:hash)
                cout<<p.first<<" "<<p.second<<endl;    
        }

};
