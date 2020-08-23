/*Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
Example 1:

Input: [3,0,1]
Output: 2*/   

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int temp = nums.size();
        /* i= 0 and i = 1 will make a difference */
        for(int i=0;i<nums.size();i++)
        {
            temp ^= i^nums[i];
        }
        return temp;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        set<int>missing_num;
        for (int i=0;i<nums.size();i++)
        {
            missing_num.emplace(nums[i]);
        }
        for (int i =0;i<nums.size()+1;i++)
        {
            if (!(missing_num.find(i) != missing_num.end()))
            {
                return i;
            }
        }
        return 0;
    }
};
