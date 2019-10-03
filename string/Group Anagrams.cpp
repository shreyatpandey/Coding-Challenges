//Complexity :- O(NKlogK)
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

//Complexity: O(NK)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>answer;
        vector<vector<string>>result;
        vector<int>count(26);
        for(int i=0;i<strs.size();i++)
        {
            //memset(count,0,27); //this did not work
            fill(count.begin(),count.end(),0);
            string temp = strs[i];
            for(int j=0;j<temp.length();j++)
            {   count[temp[j]-'a']++; }
            string sb = "";
            for(int k=0;k<26;k++)
            {
                sb.append(":");
                sb.append(to_string(count[k]));
            }
            
                answer[sb].push_back(strs[i]);
           
        }
        for(auto &x: answer)
        {
            result.push_back(x.second);
        }
        return result;
        
    }
};
