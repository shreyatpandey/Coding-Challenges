/*
A peak element is an element that is greater than its neighbors.
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2

*/


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int LeftIndex = 0;
        int RightIndex = nums.size()-1;
        while(LeftIndex <RightIndex)
        {
            int mid = LeftIndex + (RightIndex - LeftIndex)/2;
            if  ( nums[mid]>nums[mid+1]){
                RightIndex = mid;
            }
            else
                LeftIndex = mid + 1;
        
        }
        return LeftIndex ;
    }
};
