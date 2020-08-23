#include<bits/stdc++.h>
using namespace std;

struct Interval 
{
     int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int>start_time;
        vector<int>end_time;
        for(int i=0;i<intervals.size();i++)
        {
            start_time.emplace_back(intervals[i].start);
            end_time.emplace_back(intervals[i].end);
        }  
        sort(start_time.begin(),start_time.end());
        sort(end_time.begin(),end_time.end());
        int start_pointer = 0;
        int end_pointer = 0;
        int used_rooms = 0;
        while(start_pointer < intervals.size())
        {
            if(start_time[start_pointer] >= end_time[end_pointer])
            {
                used_rooms -= 1;
                end_pointer += 1;
            }
            used_rooms += 1;
            start_pointer += 1;
            
        }
        return used_rooms;
    }
};

int main()
{
    vector<Interval>input = {{0,30},{5,10},{15,20}};
    Solution s;
    int result = s.minMeetingRooms(input);
    cout<<"minMeetingRooms:"<<result<<endl;
    return 0;
    
}
