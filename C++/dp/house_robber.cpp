class Solution {
public:
    int rob(vector<int>& nums) {
        int money_robbed = 0;
        if (nums.size() == 0)
            return money_robbed;
        if (nums.size() == 2)
            return max(nums[0],nums[1]);
        int local_maxima = 0;
       for (int x: nums)
       {
           int temp = money_robbed;
           money_robbed = max(local_maxima + x,money_robbed);
           local_maxima = temp;
           
       }
        return money_robbed;
        
    }
};
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0],nums[1]);
        vector<int>dp;
        for(int x:nums)
        {
            dp.emplace_back(x);
        }
        int global_maxima = 0;
        for (int i=1;i<nums.size();i++)
        {
            int local_maxima = 0;
            for(int j=0;j<i;j++)
            {
                if (abs(j-i) != 1)
                {
                    local_maxima = dp[j] + dp[i];
                    global_maxima = max(local_maxima,global_maxima);
                }
            }
            if ( global_maxima < nums[i])
                global_maxima = nums[i]; 
            if (global_maxima > dp[i])
                dp[i] = global_maxima;
        }
        return global_maxima;
    
    }
};
