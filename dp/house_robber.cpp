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
