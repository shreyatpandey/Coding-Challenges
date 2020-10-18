class Solution {
    
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });
        if(intervals.empty() || intervals.size() == 1)
            return intervals;
        vector<vector<int>>merge_interval;
        merge_interval.emplace_back(intervals[0]);
        for(int i =0;i<intervals.size();i++)
        {
            if(merge_interval[merge_interval.size()-1][1] >= intervals[i][0])
            {
                merge_interval[merge_interval.size()-1][1] = max(merge_interval[merge_interval.size()-1][1],intervals[i][1]);
            }
            else
            {
                merge_interval.emplace_back(intervals[i]);
            }
        }
        return merge_interval;
        
    }
};
