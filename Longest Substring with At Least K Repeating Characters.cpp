class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.empty()) {
            return 0;
        }
        
        map<char, int> cnt;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            ++cnt[s[i]];
        }

        int res = 0;
        int prev = 0;
        for (int i = 0; i < n; ++i) {
            if (cnt[s[i]] < k) {
                if (prev != i) {
                    res = max(res, longestSubstring(s.substr(prev, i - prev), k));
                }
                prev = i + 1;
            }
        }
        res = prev == 0 ? n : max(res, longestSubstring(s.substr(prev), k));
        
        return res;
    }
};
