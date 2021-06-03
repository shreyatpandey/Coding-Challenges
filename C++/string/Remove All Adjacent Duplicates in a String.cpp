//TC:- O(n)
//SC:- O(n)

//Input:- "abbaca"
//Ouptut:- "ca"
class Solution {
public:
    string removeDuplicates(string s) {
        if ( s == "")
            return "";
    string RemoveString = "";
    for(auto c:s)
    {
        if ( RemoveString.empty() || c != RemoveString.back())
            RemoveString.push_back(c);
        else
            RemoveString.pop_back();
    }
    return RemoveString;
 }
};
