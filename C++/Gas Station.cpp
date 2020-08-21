class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank_capacity = 0;
        int start_index = 0;
        int defeceit = 0;
        for(int i=0;i<gas.size();i++)
        {
            tank_capacity += gas[i] - cost[i];
            if(tank_capacity < 0)
            {
                start_index = i + 1;
                defeceit += tank_capacity;
                tank_capacity = 0;
            }
        }
        return (tank_capacity + defeceit >=0 ? start_index:-1) ;
        
    }
};
