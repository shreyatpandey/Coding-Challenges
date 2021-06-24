class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int,unordered_set<int>>HashMap;
        for(auto &x: points)
        {
            HashMap[x[0]].emplace(x[1]);
        }
        const int PointSize = points.size();
        int Min_Area = INT_MAX;
        for(int i=0;i<PointSize;i++)
        {
            for(int j=i+1;j<PointSize;j++)
            {
                int x1 = points[i][0];
                int x2 = points[j][0];
                int y1 = points[i][1];
                int y2 = points[j][1];
                if ( x1==x2 || y1 == y2 )
                    continue;
                int Area = abs(x1-x2)*abs(y1-y2);
                if ( Area > Min_Area) continue;
                if ( HashMap[x1].count(y2) == 0  || HashMap[x2].count(y1) == 0) //whats the reason for this?becasue the goal is to get every points on the diagonal
                    continue;
                Min_Area = Area;
                
            }
        }
        return ( Min_Area == INT_MAX ? 0:Min_Area) ;
    }
};
