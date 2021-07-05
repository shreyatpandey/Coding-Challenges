/*
Given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.

You can attend an event i at any day d where startTimei <= d <= endTimei. Notice that you can only attend one event at any time d.

Return the maximum number of events you can attend.
*/
/*
upper bound of number days = 10^5
*/
//One of the leetcode solutions
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) 
    {
        int n=events.size();
        //priority queue contains deadlines of all the events
        //that have already started but not ended
        priority_queue<int,vector<int>,greater<int>> pq;
        
        //sort by event start time
        sort(events.begin(),events.end());
        int ans=0;
        int i=0;
        for(int d=1;d<=100000;d++)
        {
          
            //remove all the events which are already over
            while(!pq.empty()&&pq.top()<d)
            {
                pq.pop();
            }
             
            //insert deadlines of all events that start today
            while(i<n && events[i][0]==d  )
            {
                pq.push(events[i][1]);
                i++;
            }
            //if there are any events we can attend today we 
            //attend the event with smallest endtime
            if(!pq.empty())
            {
                pq.pop();
                ans++;
            }
            
             //if all elements are processed then stop 
            if(pq.empty()&&i==n)
                break;
        }
        return ans;
    }
};
