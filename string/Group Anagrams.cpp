class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       vector< vector<string> > ans;
        map<string, vector<string> >hash_map;
        for(int i=0;i<strs.size();i++) 
        {
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            hash_map[temp].push_back(strs[i]);
        }
        for(auto &x: hash_map) ans.push_back(x.second);
        return ans;
    }
};
