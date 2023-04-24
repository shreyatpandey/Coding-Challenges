/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.
*/
/*
Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
*/
/* Questions to ask:-
Size of array
Each value of array
*/
/*
If the target is equal to middle element, found the index or element
If the target is less than middle elemnt, continue search on left side
If the target is greater than middle element, continue search on right side
*/
class Solution {
    private:
        int BinarySearchInsertPosition(vector<int>&nums,int startIndex,int endIndex,int target);
public:
    int searchInsert(vector<int>& nums, int target) {
        int startIndex = 0;
        int endIndex = nums.size() - 1;
        return BinarySearchInsertPosition(nums,startIndex,endIndex,target);
    }
};
int Solution:: BinarySearchInsertPosition(vector<int>&nums,int startIndex,int endIndex,int target)
{
    int midVal = 0;
     while(startIndex <= endIndex)
    {
        midVal = (startIndex + endIndex)>>1;
        
        if ( nums[midVal] == target)
        {
            return midVal;
        }
        else if ( nums[midVal]<target)
        {
            startIndex = midVal + 1;
        }
        else
        {
            endIndex = midVal - 1;
        }
    }
    
    return startIndex;
}
