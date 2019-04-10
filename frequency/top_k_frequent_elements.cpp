/*Given a non-empty array of integers, return the k most frequent elements.
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Input: nums = [1,2], k = 2
Output: [1,2]
*/


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>hash_map;
        vector<int>kmostfrequent_vector;
        if(nums.size() == 0)
        {
            return kmostfrequent_vector; 
        }
        //find the frequency of each element
        for(int i=0;i<nums.size();i++)
        {
            hash_map.emplace(nums[i],0);
            auto it = hash_map.find(nums[i]);
            ++it->second;
            hash_map.emplace(nums[i],it->second);
            
        }
        priority_queue<pair<int,int>>pq; 
        for(auto&x : hash_map)
        {
           pq.emplace(make_pair(x.second,x.first));
        }
       for(int i=0;i<k;i++)
       {
           auto it = pq.top();
           kmostfrequent_vector.push_back(it.second);
           pq.pop();
       }
        reverse(kmostfrequent_vector.begin(),kmostfrequent_vector.end());
        return kmostfrequent_vector;
        
    }
};
