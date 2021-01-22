#include<bits/stdc++.h>
using namespace std;

using HashMap = std::map<int,string> ;

int main()
{
    HashMap Hashes;
    Hashes[1] = "One" ;
    Hashes[2] = "Two" ;
    Hashes[3] = "Three" ;
    for(auto &x:Hashes)
    {
        cout<<x.first<<" "<< x.second<<endl;
    }
    return 0;
}
