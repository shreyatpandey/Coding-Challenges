#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

template<typename T>
void Print(T &Input)
{
    for(auto x: Input)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int>Input = {4,5,9};
    Print(Input);
    return 0;
}
