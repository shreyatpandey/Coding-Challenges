#include <stdio.h>
#include <string.h>

/*
 * LeetCode Problem: Count Binary Substrings
 * 
 * Given a binary string s, return the number of non-empty substrings 
 * that have the same number of 0's and 1's, and all the 0's and all 
 * the 1's in these substrings are grouped consecutively.
 * 
 * Example 1:
 * Input: s = "00110011"
 * Output: 6
 * Explanation: There are 6 substrings that have equal number of 
 * consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
 * 
 * Algorithm:
 * 1. Count consecutive groups of same characters
 * 2. For each adjacent pair of groups, add min(group1_length, group2_length) to result
 */

int countBinarySubstrings(char* s) {
    if (s == NULL || strlen(s) == 0) {
        return 0;
    }
    
    int n = strlen(s);
    int prevGroupLength = 0;
    int currGroupLength = 1;
    int result = 0;
    
    // Traverse the string starting from index 1
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i-1]) {
            // Same character as previous, extend current group
            currGroupLength++;
        } else {
            // Different character, we found a new group
            // Add valid substrings between previous and current group
            result += (prevGroupLength < currGroupLength) ? prevGroupLength : currGroupLength;
            
            // Update for next iteration
            prevGroupLength = currGroupLength;
            currGroupLength = 1;
        }
    }
    
    // Handle the last group
    result += (prevGroupLength < currGroupLength) ? prevGroupLength : currGroupLength;
    
    return result;
}

// Test cases to validate the solution
void testCases() {
    printf("=== Test Cases ===\n");
    
    char test1[] = "00110011";
    printf("Input: \"%s\"\n", test1);
    printf("Output: %d\n", countBinarySubstrings(test1));
    printf("Expected: 6\n\n");
    
    char test2[] = "10101";
    printf("Input: \"%s\"\n", test2);
    printf("Output: %d\n", countBinarySubstrings(test2));
    printf("Expected: 4\n\n");
    
    char test3[] = "00110";
    printf("Input: \"%s\"\n", test3);
    printf("Output: %d\n", countBinarySubstrings(test3));
    printf("Expected: 3\n\n");
    
    char test4[] = "000111";
    printf("Input: \"%s\"\n", test4);
    printf("Output: %d\n", countBinarySubstrings(test4));
    printf("Expected: 3\n\n");
}

int main() {
    printf("LeetCode: Count Binary Substrings\n");
    printf("==================================\n\n");
    
    // Run test cases
    testCases();

    return 0;
}
