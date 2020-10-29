#include<vector>
#include<iostream>
#include<string>
using namespace std;

void Subsequence(vector<string>&Input,string str, int LeftIndex,
                    int RightIndex, string curr)
{
    // base case
    if (LeftIndex == RightIndex)
        return;
 
    if (curr.length() >0) 
    {
        Input.emplace_back(curr);
    }
 
    for (int i = LeftIndex+1; i < RightIndex; i++) 
    {
 
        curr += str[i];
        Subsequence(Input,str,i,RightIndex,curr);
 
        // backtracking
        curr = curr.erase(curr.size() - 1);
    }
    return;
}
 
 
vector<string>PermuationString(string input)
{
    vector<string>Result;
    Result.emplace_back(" ");
    Subsequence(Result,input,-1,input.size(),"");
    return Result;
    
}
 

int main()
{
    auto Result = PermuationString("abc");
    cout<<"Result:"<<endl;
    for(auto &x:Result)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
