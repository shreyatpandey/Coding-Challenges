/*Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 1)
            return 0;
        map<int,int>hash_map;
        for(int i=0;i<nums.size();i++)
        {
            int count = 0;
            hash_map.emplace(nums[i],0);
            auto it=hash_map.find(nums[i]);
            hash_map.emplace(nums[i],++it->second);
        }
        nums.erase(nums.begin(),nums.end());
        for(auto&x:hash_map)
        {
            nums.emplace_back(x.first);
        }
        return nums.size();
        
    }
    int removeDuplicates_2(vector<int>& nums)
    {
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
    return nums.size();
    }
};
