/*
Given a list of daily temperatures T, return a list such that, for each day in the input, 
tells you how many days you would have to wait until a warmer temperature. 
If there is no future day for which this is possible, put 0 instead.

given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].
*/

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
