/*
You are given two strings of the same length s1 and s2 and a string baseStr.

We say s1[i] and s2[i] are equivalent characters.

For example, if s1 = "abc" and s2 = "cde", then we have 'a' == 'c', 'b' == 'd', and 'c' == 'e'.
Equivalent characters follow the usual rules of any equivalence relation:

Reflexivity: 'a' == 'a'.
Symmetry: 'a' == 'b' implies 'b' == 'a'.
Transitivity: 'a' == 'b' and 'b' == 'c' implies 'a' == 'c'.
For example, given the equivalency information from s1 = "abc" and s2 = "cde", 
"acd" and "aab" are equivalent strings of baseStr = "eed", and "aab" is the lexicographically smallest equivalent string of baseStr.

Return the lexicographically smallest equivalent string of baseStr by using the equivalency information from s1 and s2.

Constraints:
1 <= s1.length, s2.length, baseStr <= 1000
s1.length == s2.length
s1, s2, and baseStr consist of lowercase English letters.
*/
/*
Approach:- Union-Find
TC:- O(max(len(s1),len(s2)))
SC:- O(1) for there is only 26 english characters

Q1] Will the length of s1 and s2 would always be equal
Q2] Will there be UpperCase letter  or only lower case letter
*/


#define ALPHA 26
class Solution {
    private:
        vector<int>Parent;
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        Parent.resize(ALPHA,0);
        for(int i=0;i<ALPHA;i++)
        {
            Parent[i] = i;
        }
        for (int i = 0; i < s1.size(); ++i)
        {
            int a = s1[i] - 'a', b = s2[i] - 'a';
            int pa = find(a), pb = find(b);
            if (pa < pb)
                Parent[pb] = pa;
            else
                Parent[pa] = pb;
        }
        string res = "";
        for (char a : baseStr)
        {
            char b = (char)(find(a - 'a') + 'a');
            res += b;
        }
        return res;
    }

    int find(int x) {
        if (Parent[x] != x)
            Parent[x] = find(Parent[x]);
        return Parent[x];
    }
};

