class Solution {
    private:
    bool dfs(string start, unordered_map<string, map<string, int>>& um, vector<string>& res, const int n);
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, map<string, int>> mm;
        for(auto & ticket : tickets) {
            mm[ticket[0]][ticket[1]]++;
        }
        string start = "JFK";
        vector<string> res;
        res.push_back(start);
        dfs(start, mm, res, tickets.size() + 1);
        return res;
    }
};
bool  Solution::dfs(string start, unordered_map<string, map<string, int>>& um, vector<string>& res, const int n) {
        if(res.size() == n) return true;
        for(auto ticket = um[start].begin(); ticket != um[start].end(); ticket++) {
            if(ticket->second != 0) {
                ticket->second--;
                res.push_back(ticket->first);
                if(dfs(ticket->first, um, res, n)) return true;
                res.pop_back();
                ticket->second++;
            }
        }
        return false;
    }
