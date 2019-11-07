/*Given a non-empty array of integers, every element appears twice except for one. Find that single one.
Unsorted Array 
Input: [2,2,1]
Output: 1
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) /* faster than only 5.19 % of C++ implementation */
    {
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
    int singleNumber_2(vector<int>& nums) /*faster than 97.18% of C++ submission = bitwise operation is faster */
    {
      if((nums.size()) == 0)
      {
          return 0;
      }
        int store_element = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            store_element ^= nums[i];
        }
        return store_element;
    }
};
