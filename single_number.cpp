class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size() == 0)
        {
            return 0;
        }
        unordered_map<int,int>hash_map;
        for(int i=0;i<nums.size();i++)
        {
            hash_map.emplace(nums[i],0);
            auto it = hash_map.find(nums[i]);
            ++it->second;
            hash_map.emplace(nums[i],it->second);
        }
        for(auto&x : hash_map)
        {
            if(x.second == 1)
            {
                return x.first;
            }
        }
        return -1;
        
    }
};
