/*
You are given a sorted array consisting of only integers where every element appears exactly twice, 
except for one element which appears exactly once. Find this single element that appears only once.
Example 1:

Input: [1,1,2,3,3,4,4,8,8]
Output: 2
*/
// Your solution should run in O(log n) time and O(1) space.
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
         int lo = 0;
        int hi = nums.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            bool halvesAreEven = ((hi - mid) & 1)== 1 ? false:true;
            if (nums[mid + 1] == nums[mid]) {
                if (halvesAreEven) {
                    lo = mid + 2;
                } else {
                    hi = mid - 1;
                }
            } else if (nums[mid - 1] == nums[mid]) {
                if (halvesAreEven) {
                    hi = mid - 2;
                } else {
                    lo = mid + 1;
                }
            } else {
                return nums[mid];
            }
        }
        return nums[lo];
    }
        
    
};
