//TC:- (NlogN)
//SC:- O(N)

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        /* what will my priority_queue store*/
        /* index- ith or height - heights[i] */
        /* none of these :- it will store the bricks */
        priority_queue<int>pq;
        for(int i=0;i<heights.size()-1;i++) /* O(n) */
        {
            int Diffheight = heights[i+1] - heights[i] ;
            if( Diffheight <= 0)
            {
                continue ;
            }
            pq.push(Diffheight);
            bricks -= Diffheight;
            if(bricks<0 && ladders == 0)
            {
                return i;
            }
            /* greedy on bricks and not ladders, since it is sufficient to use just one ladder to go from one building to other */
            if ( bricks <0)
            {
                    int Top = pq.top();
                    pq.pop();
                    bricks += Top; //whats the use of this line ? this is used to reclaim the lost bricks
                    ladders -=1 ;      
            }
        }
        return heights.size() - 1;
    }
};
