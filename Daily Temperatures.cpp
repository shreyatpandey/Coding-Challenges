class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int>result(T.size(),0);
        stack<int>daily_temp;
        for(int i=T.size()-1;i>=0;i--)
        {
            while(daily_temp.size()>0 && T[i]>=T[daily_temp.top()])
            {
                daily_temp.pop();
            }
            result[i] = daily_temp.size() == 0?0:daily_temp.top() - i;
            daily_temp.emplace(i);
        }
        return result;
        
    }
};
