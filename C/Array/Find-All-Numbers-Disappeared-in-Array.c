/*
Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums
*/
/*
Example 1:-
Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
         *returnSize = numsSize;
      // Iterate over each of the elements in the original array
        for (int i = 0; i < numsSize; i++) {
            
            // Treat the value as the new index
            int newIndex = abs(nums[i]) - 1;
            
            // Check the magnitude of value at this new index
            // If the magnitude is positive, make it negative 
            // thus indicating that the number nums[i] has 
            // appeared or has been visited.
            if (nums[newIndex] > 0) {
                nums[newIndex] *= -1;
                (*returnSize)--;
            }
        }
      // Iterate over the numbers from 1 to N and add all those
      // that have positive magnitude in the array
       int* result = (int*)malloc((*returnSize)*sizeof(int));
       int index = 0;
       for (int i = 1; i <= numsSize; i++) 
       {     
            if (nums[i - 1] > 0) 
            {
                result[index++] = i; 
            }
        }
    return result;
}
