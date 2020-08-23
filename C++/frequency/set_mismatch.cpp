/*The set S originally contains numbers from 1 to n. 
But unfortunately, due to the data error, one of the numbers in the set got duplicated to another number in the set, which results in repetition of one number and loss of another number.
Given an array nums representing the data status of this set after the error. 
Your task is to firstly find the number occurs twice and then find the number that is missing. Return them in the form of an array.*/
/*Input: nums = [1,2,2,4]
Output: [2,3]*/

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

