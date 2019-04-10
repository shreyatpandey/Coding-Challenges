class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>result;
        unordered_map<int,int>hash_map;
        for(int i=0;i<nums.size();i++)
        {
            hash_map.emplace(nums[i],0);
            auto it = hash_map.find(nums[i]);
            ++it->second;
            if(it->second == 2)
            {
                result.push_back(it->first);
            }
            hash_map.emplace(nums[i],it->second);
        }
        for(int i=1;i<nums.size()+1;i++)
        {
            if(hash_map.count(i) == 0)
            {
                result.push_back(i);
            }
        }
        return result;
        
    }
};
