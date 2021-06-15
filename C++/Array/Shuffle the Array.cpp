/*
Input: nums = [2,5,1,3,4,7], n = 3
Output: [2,3,5,4,1,7] 
Explanation: Since x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 then the answer is [2,3,5,4,1,7].
*/
//Two-Pointer
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
     vector<int>Result(nums.size(),0);
        int i=0,j=n,k=0;
        while(i<n)
        {
            Result[k++] = nums[i++];
            Result[k++] = nums[j++];
        }
        return Result;
    }
};
