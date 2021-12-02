#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
#include<deque>
#include<memory>

using namespace std;

class Solution
{
    private:
        vector<string>SplitString(string Input);
    public:
        string SimplifyPath(string path)
        {
            vector<string>SplitResult = SplitString(path);
            deque<string>Stack ;
            for (auto x:SplitResult)
            {
                if ( x.empty() || x == ".") 
                    continue;
                else if( x== "..")
                {
                    if (!Stack.empty())
                        {
                           Stack.pop_back();     
                        } 
                }
                else
                {
                    Stack.push_back(x);
                }
            }
            for(auto str: Stack)
            {
                cout<<str<<endl;
            }
            string Result = "/";
            while ( Stack.size() > 0) 
            {
                string Last = Stack.front();
                Stack.pop_front();
                if ( Stack.size() == 0)
                {
                    Result += Last ;
                }
                else
                {
                   Result += Last + "/";  
                   cout<<"Result:"<<Result<<endl;   
                }
            }

            return Result;
        }
};
vector<string>Solution :: SplitString(string Input)
{
    vector<string>Result;
    stringstream ss(Input);
    string Token = "";
    char delimiter = '/';
    while(getline(ss,Token,delimiter))
    {
        Result.emplace_back(Token);
    }
    return Result;
}

int main()
{
    unique_ptr<Solution>s(new Solution);
    string Input = "/home/food";
    auto Result = s->SimplifyPath(Input);
    cout<<Result<<endl;
    Input = "/../";
    Result = s->SimplifyPath(Input);
    cout<<Result<<endl;

    return 0;
}
