#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &pair) const {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

/* BFS - Approach */
int MinimumFlyingTicketCost(int n,vector<vector<int>>&Input,int Src,int Dst,int K)
{
    /*Create an Adjacency Matrix*/
    vector<vector<int>>adjList(n,vector<int>(n,0));
    for(auto &x:Input)
    {
        adjList[x[0]][x[1]] = x[2];
    }
    /*
    for(auto &x:adjList)
    {
        cout<<x[0]<<","<<x[1]<<","<<x[2]<<endl;
    }
    */
   queue<int>bfsQueue;
   int noOfStops = 0;
   unordered_map<pair<int,int>,long,pair_hash>coordinateToDst;
   /*An important thing to note in this approach is that we need to keep a dictionary with the node, stops as the key. 
   Basically, we need to keep track of the shortest distance of a node from the source provided that it takes stops stops to reach it.
   */
   coordinateToDst[{Src,0}] = 0;
   bfsQueue.push(Src);
   long answer = INT_MAX;
   while(bfsQueue.size()>0 && noOfStops<K+1) /* our bfs traversal is bounded by this K*/
   {
       int length = bfsQueue.size();
       for(int i=0;i<length;i++)
       {
           int Node = bfsQueue.front();
           bfsQueue.pop();
           cout<<"Node:"<<Node<<endl;
           for(int neighbor=0;neighbor<Node;neighbor++)
           {
               if (adjList[Node][neighbor]>0)
               {
                long dU = INT_MAX, dV = INT_MAX;
                if ( coordinateToDst.find({Node,noOfStops}) != coordinateToDst.end())
                {
                    dU = coordinateToDst[{Node,noOfStops}];
                }
                if (coordinateToDst.find({neighbor,noOfStops+1}) != coordinateToDst.end())
                {
                    dV = coordinateToDst[{neighbor,noOfStops+1}];
                }
                cout<<"dU:"<<dU<<endl;
                cout<<"dV:"<<dV<<endl;
                long wUV = adjList[Node][neighbor];
                if(noOfStops == K && neighbor != Dst)
                {
                    continue;
                }
                if(dU + wUV < dV)
                {
                    coordinateToDst[{neighbor,noOfStops+1}] = dU+wUV;
                    bfsQueue.push(neighbor);
                    if(neighbor == Dst)
                    {
                        answer = min(answer,dU+wUV);
                        cout<<"answer:"<<answer<<endl;
                    }
                }

               }
           }
       }
       noOfStops += 1;
   }
    return answer == INT_MAX ? -1: (int)answer;
    
}


int main()
{
    vector<vector<int>>Input = {{0,1,100},{1,2,100},{0,2,500}};
    int n = 3;
    int Src = 0;
    int Dst = 2;
    int K = 1;
    cout<<MinimumFlyingTicketCost(n,Input,Src,Dst,K)<<endl;

    return 0;
}
