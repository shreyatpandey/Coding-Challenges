/* Continous subarray = indices should be continous; 
   [1,2,3,4,5,6,7] k=9 ; [2,3,4] and [4,5] */
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int answer = 0;
        if(nums.size() == 0)
            return answer;
        unordered_map<int,int>hash_array;
        int sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            if(sum == k)
                answer++;
            if(hash_array.count(sum-k))
                answer += hash_array[sum-k];
            
            hash_array[sum]++;
        }
        return answer;
    }
};
