/* Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. 
Find that single one.
Example 1:

Input: [2,2,3,2]
Output: 3
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size() == 0)
            return -1;
        map<int,int>frequency_store;
        for(int i: nums)
        {
            if (frequency_store.find(i) != frequency_store.end())
            {
                frequency_store[i]++;
            }
            else
            {
                frequency_store[i] = 1;
            }
        }
        for(auto&x : frequency_store)
        {
            if(x.second == 1)
            {
                return x.first;
            }
        }
        return -1;
        
    }
};
