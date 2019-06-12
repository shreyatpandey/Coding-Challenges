#include<bits/stdc++.h>
using namespace std;

bool palindrome_permutation(string s)
{
    map<char,int>frequency_count;
    int odd_char = 0;
    for(int i=0;i<s.length();i++)
    {
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
        {
            char temp = tolower(s[i]);
            if (frequency_count.find(temp) != frequency_count.end())
            {
                frequency_count[temp]++;
            }
            else
            {
                frequency_count[temp] = 1;
            }
        }
    }
    for(auto&x : frequency_count)
    {
        if(x.second % 2 != 0)
        {
            odd_char += 1;
        }
        if(odd_char > 1)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    cout<<boolalpha<<palindrome_permutation("Tact Coa")<<endl;
    return 0;
}
