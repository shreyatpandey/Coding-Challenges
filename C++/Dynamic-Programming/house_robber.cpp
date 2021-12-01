//Top-Down + Memoization
//TC:- O(n)
//SC:- O(n)
class Solution {
    int RobMoney(vector<int>&nums,vector<int>&Memoize,int startIndex);
public:
    int rob(vector<int>& nums) {
        vector<int>Memoize(100,-1); //why 100 , the length of nums is 100 and why -1 , because nums[i] >=0
        return RobMoney(nums,Memoize,0);
    }
};

int Solution::RobMoney(vector<int>&nums,vector<int>&Memoize,int startIndex)
{
    if ( startIndex >= nums.size())
        return 0;
    
    if (Memoize[startIndex] > -1)
        return Memoize[startIndex];
    
    int answer = max(RobMoney(nums,Memoize,startIndex+1),RobMoney(nums,Memoize,startIndex+2)+ nums[startIndex]);
    Memoize[startIndex] = answer;
    return answer;
}


//Bottom-Up
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
