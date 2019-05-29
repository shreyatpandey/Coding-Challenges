class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int temp = nums.size();
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
