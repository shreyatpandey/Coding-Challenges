/*
Given a sorted array A of unique numbers, find the K-th missing number starting from the leftmost number of the array.
Example 1:

Input: A = [4,7,9,10], K = 1
Output: 5
Explanation: 
The first missing number is 5.
*/

class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
    int LeftIndex = 0, RightIndex = nums.size();
    while(LeftIndex < RightIndex)
    {
        int MidValue = (LeftIndex + RightIndex)>>1 ;
        int Difference = (nums[MidValue] - MidValue) - nums[0] ;
        if ( Difference < k )
        {
            LeftIndex = MidValue + 1;
        }
        else
        {
            RightIndex = MidValue ;
        }
    }
        return RightIndex + nums[0] + k -1 ;
        
    }
};
