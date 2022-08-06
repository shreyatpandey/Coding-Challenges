/*
You are given an integer array nums and an integer x. 
In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. 
Note that this modifies the array for future operations.

Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.

Example 1:
Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.

*/


/*
Algorithm:-
Let us take a sliding window whose ends are defined by start_idx and end_idx.
If the sum of this sliding window (subarray) exceeds the target, keep reducing the window size (by increasing start_idx) until its sum becomes <= target.
If the sum becomes equal to the target, compare the length, and store if it exceeds the previous length.
Return -1 if the sum of the sliding window never becomes equal to target.
*/
/*
TC:- O(n) instead of O(n^2) because both startIndex and endIndex goes from 0 to N
SC:- O(1)
*/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int Sum = 0;
        for(auto x:nums) Sum += x;
        if (Sum < x) return -1;
        int Target = Sum - x;
        int maxLen = INT_MIN;
        int startIndex = 0;
        int size = nums.size();
        int currentSum = 0;
        bool found = false;
        for(int endIndex = 0;endIndex<size;endIndex++)
        {
            currentSum += nums[endIndex];
            while(startIndex <=endIndex && currentSum >Target) 
            {
                currentSum -= nums[startIndex];
                startIndex += 1;
            }
            if (currentSum == Target)
            {
                found = true;
                maxLen = max(maxLen,endIndex-startIndex+1); 
            }
        }
        return found ? (size-maxLen):-1;
    }
};
