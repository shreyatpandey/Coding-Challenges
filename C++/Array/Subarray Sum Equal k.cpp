/*
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.
Input:-nums = [1,1,1], k = 2
Output: 2
Input:- nums = [9, 4, 20, 3, 10, 5], k = 33
Output:- 2
*/

//Approach-1
//TC:- O(n)
//SC:- O(n)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        if(nums.size() == 0)
            return ans;
        unordered_map<int,int> dict;
        //dict.clear();
        int sum = 0;
        for(int i = 0; i < nums.size(); ++ i){
            sum += nums[i];
            if(sum == k)
                ++ ans;
            if(dict.count(sum - k))
                ans += dict[sum - k];
            ++ dict[sum];
        }
        return ans;
        
    }
};
