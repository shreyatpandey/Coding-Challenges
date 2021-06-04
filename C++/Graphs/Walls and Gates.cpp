//Only BFS Traversal
/*
You are given an m x n grid rooms initialized with these three possible values.

-1 A wall or an obstacle.
0 A gate.
INF Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.
*/

using Queue = queue<pair<int,int>> ;
using vector2D = vector<pair<int,int>>;
// it is possible that walls, gate and empty can be given from any order
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if ( rooms.size() == 0) return ;
        Queue qp;
        vector2D TwoDir = {{0,-1},{0,1},{-1,0},{1,0}}; /*reason for not including {-1,-1} or {1,1} is that diagonal traversal is not allowed*/ 
        for(int i=0;i<rooms.size();i++)
        {
            for(int j=0;j<rooms[0].size();j++)
            {
                if ( rooms[i][j] == 0) //reason for starting with Gate
                {
                    //BFS Traversal
                    qp.push({i,j});
                }
            }
        }
        while (qp.size())
        {
            auto Iter = qp.front();
            qp.pop();
            int step = 0;
            for(auto x:TwoDir) 
            {
                int XDirection = Iter.first + x.first;
               //  cout<<"XDirection:"<<XDirection<<endl;
                int YDirection = Iter.second + x.second;
              //   cout<<"YDirection:"<<YDirection<<endl;
                if ( XDirection < 0 || XDirection >= rooms.size() || YDirection < 0 || YDirection>=rooms[0].size() || rooms[XDirection][YDirection] != INT_MAX )
                {
               //    cout<<"|-------Not a Valid Entry | Either a Wall or a Gate -------|"<<endl;
                    continue;
                }
                rooms[XDirection][YDirection] = rooms[Iter.first][Iter.second] + 1;
                qp.push({XDirection,YDirection});
            }
        }
        
        
    }
};
