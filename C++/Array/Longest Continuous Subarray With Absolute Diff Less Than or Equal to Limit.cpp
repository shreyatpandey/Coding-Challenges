//Input: nums = [10,1,2,4,7,2], limit = 5
//Output: 4 
//Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> w; 
        int len = 0, n = nums.size();
        int i=0;
        for(int j=0; j<n; j++) {
            w.insert(nums[j]);
            while(*w.rbegin()-*w.begin() > limit) //keeps element in sorted order
            {
                w.erase(w.find(nums[i])) ;
                i++;
            }
            len=max(len,(int)w.size());
        }
        return len;
        
    }
};
