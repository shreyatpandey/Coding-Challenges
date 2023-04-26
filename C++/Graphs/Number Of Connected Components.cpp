//BFS Approach
//TC:- O(V+E)
/*
1. Create an adjacent list of edges. 
    Mistake I make is that I used vector in value.
    Use set for this.
2. Create a set for marking visited vertices. [I forget this]
3. Queue to keep vertices. This queue will updated only if vertices has NOT-BEEN visited.
*/
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int noOfComponents = 0;
        unordered_map<int,unordered_set<int>>adjList;
        for(auto &x:edges)
        {
            adjList[x[0]].insert(x[1]);
            adjList[x[1]].insert(x[0]);
        }
        vector<int>visitedSet(n,0);
        queue<int>Queue;
        for(int i=0;i<n;i++)
        {
            if(visitedSet[i] == 0)
            {
                noOfComponents += 1;
                visitedSet[i] = 1;
                Queue.push(i);
                while (Queue.size() > 0)
                {
                    int current = Queue.front();
                    Queue.pop();
                    visitedSet[current] = 1;
                    for ( auto &x:adjList[current])
                    {
                        if (visitedSet[x] == 0)
                        {
                            Queue.push(x);
                        }
                        
                    } 
                }
            }
        }
        return noOfComponents;
    }
};
