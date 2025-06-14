/*
Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. 
More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.
*/
/*
Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
*/

int removeDuplicates(int* nums, int numsSize)
{
        // Initialize the counter and the second pointer.
        int j = 1, count = 1;
  
        // Start from the second element of the array and process
        // elements one by one.
        for (int i = 1; i < numsSize; i++) 
        {
            // If the current element is a duplicate, increment the count.
            if (nums[i] == nums[i - 1]) 
            {
                count++;   
            } 
            else 
            {
                // Reset the count since we encountered a different element
                // than the previous one.
                count = 1;
            }  
            // For a count <= 2, we copy the element over thus
            // overwriting the element at index "j" in the array
            if (count <= 2) 
            {
                nums[j++] = nums[i];
            }
        }
        return j;
}
