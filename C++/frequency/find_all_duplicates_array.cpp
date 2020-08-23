class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>result_vect;
        map<int,int>check_twice;
        for(size_t i=0;i<nums.size();i++)
        {
            check_twice.emplace(nums[i],0);
            auto it = check_twice.find(nums[i]);
            ++it->second;
            check_twice.emplace(nums[i],it->second);
        }
        for(auto& x:check_twice)
        {
            if(x.second == 2)
            {
                result_vect.emplace_back(x.first);
            }
        }
        return result_vect;
        
    }
};
