class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        /* min - heap */
        int n = tasks.size(), k = 0;
        vector<int> ans(n);
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(),[&](auto a, auto b){
    
            return tasks[a][0] < tasks[b][0];// Sort by start time 
        });
        priority_queue<pii,vector<pii>,cmp> q;
        //  Storage  { The duration of the , Subscript }
        int t = 0;
        for(int i = 0; i < n; )
        {
    
            while(i < n && tasks[idx[i]][0] <= t)
            {
     	//  Tasks waiting to be performed , Join the queue 
                q.push({
    tasks[idx[i]][1], idx[i]});
                i++;
            }
            if(!q.empty())
            {
    	//  Do the task , The highest priority is 
                int delta = q.top().first, id = q.top().second;
                int start = tasks[id][0]; //  Mission start time 
                q.pop();
                ans[k++] = id;
                t = max(t, start);// current time 
                t += delta;// t  Time to finish the work 
            }
            else //  The queue is empty , Time moves to the next task 
            {
    
                t = tasks[idx[i]][0];
            }
        }
        while(!q.empty())
        {
    
            int id = q.top().second;
            q.pop();
            ans[k++] = id;
        }
        return ans;
    }      
    
};
