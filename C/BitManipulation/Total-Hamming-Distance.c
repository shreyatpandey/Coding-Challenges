#include <stdio.h>

/*
 The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given an integer array nums, return the sum of Hamming distances between all the pairs of the integers in nums.

 

Example 1:

Input: nums = [4,14,2]
Output: 6
Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case).
The answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
*/

// Function to calculate the sum of Hamming distances between all pairs in nums[]
int totalHammingDistance(int* nums, int numsSize) {
    int total = 0;
    for (int bit = 0; bit < 32; ++bit) {
        int count_ones = 0;
        for (int i = 0; i < numsSize; ++i) {
            if ((nums[i] >> bit) & 1) {
                count_ones++;
            }
        }
        total += count_ones * (numsSize - count_ones);
    }
    return total;
}

int main() {
    int nums[] = {4, 14, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = totalHammingDistance(nums, numsSize);
    printf("Sum of Hamming distances: %d\n", result); // Expected output: 6
    return 0;
}
