//Top-Down + Recursion With Memoization
//TC:- O(n)
//SC:- O(n) stack frame

class Solution {
    int RobMoney(vector<int>&nums,vector<int>&Memoize,int startIndex,int finalIndex);
public:
    int rob(vector<int>& nums) {
        if ( nums.size() ==1)
            return nums[0];
        vector<int>Memoize(100,-1);
        int Sol1 = RobMoney(nums,Memoize,0,nums.size()-1);
        fill(Memoize.begin(),Memoize.end(),-1);
        int Sol2 = RobMoney(nums,Memoize,1,nums.size());
        return max(Sol1,Sol2);
    }
};

int Solution::RobMoney(vector<int>&nums,vector<int>&Memoize,int startIndex,int finalIndex)
{
    if ( startIndex >= finalIndex)
        return 0;
    
    if (Memoize[startIndex] > -1)
        return Memoize[startIndex];
    
    int answer = max(RobMoney(nums,Memoize,startIndex+1,finalIndex),RobMoney(nums,Memoize,startIndex+2,finalIndex)+ nums[startIndex]);
    Memoize[startIndex] = answer;
    return answer;
}
