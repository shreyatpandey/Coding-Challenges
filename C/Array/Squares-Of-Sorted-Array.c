#include <stdio.h>
#include <stdlib.h>

/**
 * Given an integer array nums sorted in non-decreasing order, 
 * return an array of the squares of each number sorted in non-decreasing order.
 * 
 * Example 1:
 * Input: nums = [-4,-1,0,3,10]
 * Output: [0,1,9,16,100]
 * 
 * Example 2:
 * Input: nums = [-7,-3,2,3,11]
 * Output: [4,9,9,49,121]
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    // Allocate memory for the result array
    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    
    // Two pointers approach
    int left = 0;
    int right = numsSize - 1;
    int pos = numsSize - 1; // Fill result array from the end
    
    // Process elements from both ends
    while (left <= right) {
        int leftSquare = nums[left] * nums[left];
        int rightSquare = nums[right] * nums[right];
        
        // Place the larger square at the current position
        if (leftSquare > rightSquare) {
            result[pos] = leftSquare;
            left++;
        } else {
            result[pos] = rightSquare;
            right--;
        }
        pos--;
    }
    
    return result;
}

// Helper function to print array
void printArray(int* arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(",");
        }
    }
    printf("]\n");
}

// Test function
void testSortedSquares() {
    printf("Testing Squares of Sorted Array:\n\n");
    
    // Test case 1
    int nums1[] = {-4, -1, 0, 3, 10};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    int returnSize1;
    
    printf("Test 1:\n");
    printf("Input:  ");
    printArray(nums1, size1);
    
    int* result1 = sortedSquares(nums1, size1, &returnSize1);
    printf("Output: ");
    printArray(result1, returnSize1);
    printf("Expected: [0,1,9,16,100]\n\n");
    
    free(result1);
    
    // Test case 2
    int nums2[] = {-7, -3, 2, 3, 11};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    int returnSize2;
    
    printf("Test 2:\n");
    printf("Input:  ");
    printArray(nums2, size2);
    
    int* result2 = sortedSquares(nums2, size2, &returnSize2);
    printf("Output: ");
    printArray(result2, returnSize2);
    printf("Expected: [4,9,9,49,121]\n\n");
    
    free(result2);
    
    // Test case 3: All negative numbers
    int nums3[] = {-5, -3, -2, -1};
    int size3 = sizeof(nums3) / sizeof(nums3[0]);
    int returnSize3;
    
    printf("Test 3 (All negative):\n");
    printf("Input:  ");
    printArray(nums3, size3);
    
    int* result3 = sortedSquares(nums3, size3, &returnSize3);
    printf("Output: ");
    printArray(result3, returnSize3);
    printf("Expected: [1,4,9,25]\n\n");
    
    free(result3);
    
    // Test case 4: All positive numbers
    int nums4[] = {1, 2, 3, 4, 5};
    int size4 = sizeof(nums4) / sizeof(nums4[0]);
    int returnSize4;
    
    printf("Test 4 (All positive):\n");
    printf("Input:  ");
    printArray(nums4, size4);
    
    int* result4 = sortedSquares(nums4, size4, &returnSize4);
    printf("Output: ");
    printArray(result4, returnSize4);
    printf("Expected: [1,4,9,16,25]\n\n");
    
    free(result4);
    
    // Test case 5: Single element
    int nums5[] = {-2};
    int size5 = sizeof(nums5) / sizeof(nums5[0]);
    int returnSize5;
    
    printf("Test 5 (Single element):\n");
    printf("Input:  ");
    printArray(nums5, size5);
    
    int* result5 = sortedSquares(nums5, size5, &returnSize5);
    printf("Output: ");
    printArray(result5, returnSize5);
    printf("Expected: [4]\n\n");
    
    free(result5);
}

int main() {
    testSortedSquares();
    
    printf("\nAlgorithm Explanation:\n");
    printf("1. Use two pointers: left at start, right at end\n");
    printf("2. Compare squares of elements at both pointers\n");
    printf("3. Place the larger square at the end of result array\n");
    printf("4. Move the corresponding pointer inward\n");
    printf("5. Continue until all elements are processed\n\n");
    
    printf("Time Complexity: O(n)\n");
    printf("Space Complexity: O(n) for the result array\n");
    
    return 0;
}
