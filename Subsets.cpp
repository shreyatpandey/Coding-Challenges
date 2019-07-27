class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>>result;
        unsigned int power_set = pow(2, nums.size());
        int loop_counter;
        for(loop_counter = 0;loop_counter<power_set;loop_counter += 1)
        {
            vector<int>loop;
            for(int i=0;i<nums.size();i++)
            {
                if(loop_counter & (1<<i))
                    loop.emplace_back(nums[i]);
                    
            }
            result.emplace_back(loop);
        }
        return result;
        
    }
};
