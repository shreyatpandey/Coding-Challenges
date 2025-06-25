/*
 * Read N Characters Given Read4 - LeetCode Style Problem
 * 
 * Problem Statement:
 * Given a file and assuming that you can only read the file using a given method read4 
 * which reads 4 consecutive characters from the file, then writes those characters into 
 * the buffer array buf4.
 * 
 * The return value is the number of actual characters read.
 * 
 * Note that read4() has its own file pointer, much like FILE *fp in C.
 * 
 * Definition of read4:
 *     Parameter:  char buf4[4]
 *     Returns:    int
 * 
 * Note: buf4[] is destination not source, the results from read4 will be copied to buf4[]
 * 
 * Below is a high level example of how read4 works:
 * File file("abcdefghijk"); // File is "abcdefghijk", initially file pointer (fp) points to 'a'
 * char[] buf4 = new char[4]; // Create buffer with enough space to store characters
 * read4(buf4); // read4 returns 4. Now buf = ['a','b','c','d'], fp points to 'e'
 * read4(buf4); // read4 returns 4. Now buf = ['e','f','g','h'], fp points to 'i'
 * read4(buf4); // read4 returns 3. Now buf = ['i','j','k',...], fp points to end of file
 * 
 * By using the read4 method, implement the method read that reads n characters 
 * from the file and store it in the buffer array buf. Consider that you cannot 
 * manipulate the file directly.
 * 
 * The return value is the number of actual characters read.
 * 
 * Example 1:
 * Input: file = "abc", n = 4
 * Output: 3
 * Explanation: After calling your read method, buf should contain "abc". 
 * We read a total of 3 characters from the file, so return 3.
 * 
 * Example 2:
 * Input: file = "abcde", n = 5
 * Output: 5
 * Explanation: After calling your read method, buf should contain "abcde". 
 * We read a total of 5 characters from the file, so return 5.
 * 
 * Example 3:
 * Input: file = "abcdABCD1234", n = 12
 * Output: 12
 * Explanation: After calling your read method, buf should contain "abcdABCD1234". 
 * We read a total of 12 characters from the file, so return 12.
 * 
 * Example 4:
 * Input: file = "leetcode", n = 5
 * Output: 5
 * Explanation: After calling your read method, buf should contain "leetc". 
 * We read a total of 5 characters from the file, so return 5.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

// Global variables to simulate file reading
static char* file_content = NULL;
static int file_pointer = 0;
static int file_length = 0;

/**
 * The read4 API is already defined for you.
 * @param buf4 The buffer to store read characters.
 * @return The number of actual characters read (0 to 4).
 */
int read4(char *buf4) {
    int chars_read = 0;
    
    // Read up to 4 characters from the file
    while (chars_read < 4 && file_pointer < file_length) {
        buf4[chars_read] = file_content[file_pointer];
        chars_read++;
        file_pointer++;
    }
    
    return chars_read;
}

/**
 * @param buf Destination buffer
 * @param n   Number of characters to read
 * @return    The number of actual characters read
 */
int read_n_chars(char *buf, int n) {
    char temp_buffer[4];  // Temporary buffer for read4
    int total_chars_read = 0;
    int chars_from_read4 = 4;  // Initialize to 4 to enter the loop
    
    // Continue reading while we haven't read n characters and read4 returns 4 chars
    while (total_chars_read < n && chars_from_read4 == 4) {
        chars_from_read4 = read4(temp_buffer);
        
        // Copy characters from temp buffer to destination buffer
        for (int i = 0; i < chars_from_read4; i++) {
            if (total_chars_read == n) {
                return total_chars_read;
            }
            buf[total_chars_read++] = temp_buffer[i];
        }
    }
    
    return total_chars_read;
}

// Helper function to initialize file simulation
void init_file(const char* content) {
    file_content = (char*)content;
    file_pointer = 0;
    file_length = strlen(content);
}

// Helper function to reset file pointer for multiple test cases
void reset_file() {
    file_pointer = 0;
}

// Test function
void test_read_n_chars(const char* file_content_str, int n, const char* expected, int expected_count) {
    init_file(file_content_str);
    
    char buf[1000] = {0};  // Large enough buffer
    int result = read_n_chars(buf, n);
    
    printf("File: \"%s\", n: %d\n", file_content_str, n);
    printf("Expected: \"%.*s\" (count: %d)\n", expected_count, expected, expected_count);
    printf("Got:      \"%.*s\" (count: %d)\n", result, buf, result);
    printf("Test %s\n\n", (result == expected_count && strncmp(buf, expected, result) == 0) ? "PASSED" : "FAILED");
    
    reset_file();
}

int main() {
    printf("=== Read N Characters Given Read4 - Test Cases ===\n\n");
    
    // Test Case 1: File shorter than requested
    test_read_n_chars("abc", 4, "abc", 3);
    
    // Test Case 2: Exact match
    test_read_n_chars("abcde", 5, "abcde", 5);
    
    // Test Case 3: File longer than requested
    test_read_n_chars("abcdABCD1234", 12, "abcdABCD1234", 12);
    
    // Test Case 4: Read partial
    test_read_n_chars("leetcode", 5, "leetc", 5);
    
    // Test Case 5: Empty file
    test_read_n_chars("", 1, "", 0);
    
    // Test Case 6: Read 0 characters
    test_read_n_chars("hello", 0, "", 0);
    
    // Test Case 7: Single character file
    test_read_n_chars("a", 1, "a", 1);
    
    // Test Case 8: Exactly 4 characters
    test_read_n_chars("abcd", 4, "abcd", 4);
    
    // Test Case 9: More than 4 characters, read less than available
    test_read_n_chars("abcdefgh", 6, "abcdef", 6);
    
    // Test Case 10: Large file, read small portion
    test_read_n_chars("this is a very long string for testing", 10, "this is a ", 10);
    
    printf("=== Algorithm Analysis ===\n");
    printf("Time Complexity: O(n) where n is the number of characters to read\n");
    printf("Space Complexity: O(1) - only using a fixed size temp buffer\n\n");
    
    printf("=== Key Points ===\n");
    printf("1. Use read4() API which reads up to 4 characters at a time\n");
    printf("2. Handle cases where file is shorter than requested characters\n");
    printf("3. Handle cases where we need to stop reading mid-way through a read4() call\n");
    printf("4. Efficiently copy characters from temp buffer to destination\n");
    printf("5. Return the actual number of characters read\n");
    
    return 0;
}

/*
 * Compilation and Execution:
 * gcc -o read_n_chars Read-N-Characters-Given-Read4.c
 * ./read_n_chars
 * 
 * Expected Output:
 * All test cases should pass, demonstrating the correctness of the algorithm.
 * 
 * Algorithm Explanation:
 * 1. Use a temporary buffer of size 4 to store results from read4()
 * 2. Continue calling read4() while:
 *    - We haven't read the required n characters
 *    - The last call to read4() returned exactly 4 characters (meaning more data might be available)
 * 3. For each read4() call, copy characters from temp buffer to destination buffer
 * 4. Stop copying if we've reached the required n characters
 * 5. Return the total number of characters actually read
 * 
 * Edge Cases Handled:
 * - File is shorter than requested characters
 * - File is exactly the requested length
 * - File is longer than requested characters
 * - Empty file
 * - Requesting 0 characters
 * - File length is exactly divisible by 4
 * - File length is not divisible by 4
 */
