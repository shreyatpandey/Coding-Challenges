class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() <2)
            return false;
        set<int>check_duplicates;
        for (int i=0;i<nums.size();i++)
        {
            if (check_duplicates.find(nums[i]) != check_duplicates.end())
            {
                return true;
            }
            check_duplicates.emplace(nums[i]);
        }
        return false;
    }
};
