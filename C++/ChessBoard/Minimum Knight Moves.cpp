//Return the minimum number of steps needed to move the knight to the square [x, y].  It is guaranteed the answer exists.
//BFS
//Constraint |x| + |y| <= 300
class Solution {
public:
    int minKnightMoves(int x, int y) {
        vector<pair<int, int>> dirs{{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
        vector<vector<int>> visit(601, vector<int>(601, 0));
        visit[300][300] = 1;  
        int NumberOfMoves = 0;
        queue<pair<int, int>>BFSQueue;
        BFSQueue.push({0, 0});
        while(BFSQueue.size() > 0){
            int size = BFSQueue.size(); 
            while(size > 0){
                --size;
                auto cur = BFSQueue.front();
                BFSQueue.pop();
                if(cur.first == x && cur.second == y){
                    return NumberOfMoves; // return answer
                }
                for(auto dir : dirs){
                    int x_dir = cur.first + dir.first;
                    int y_dir = cur.second + dir.second;
                    if(-300 <= x_dir && x_dir <= 300 && -300 <= y_dir && y_dir <=300
                       && visit[x_dir + 300][y_dir + 300] == 0){
                        BFSQueue.push({x_dir, y_dir});
                        visit[x_dir + 300][y_dir + 300] = 1;
                    }
                }
            }
            ++NumberOfMoves;  
        }
        return 0;
    }
};
