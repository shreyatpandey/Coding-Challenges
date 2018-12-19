#include<bits/stdc++.h>

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int>hash_map;
    
        for(int i=0;i<nums.size();i++)
        {
            if(hash_map.find(nums[i]) != hash_map.end())
            {
                
                return nums[i];
            }
            else
                hash_map.insert(nums[i]);
        }
        return -1;
        
    }
};

int main()
{
    std::vector<int> input = {3,1,3,4,2};
    Solution s;
    cout<<"Duplicate_Number:"<<s.findDuplicate(input)<<endl;
    return 0;
}

