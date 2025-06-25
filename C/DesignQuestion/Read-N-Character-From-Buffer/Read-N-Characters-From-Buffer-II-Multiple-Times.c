/*
 * Read N Characters Given Read4 II - Call Multiple Times - LeetCode Problem
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
 * This is a follow-up problem to "Read N Characters Given Read4".
 * 
 * The key difference is that the read method will be called multiple times.
 * 
 * When you call read(buf, n) multiple times, you need to handle the case where 
 * the previous call to read4() might have read more characters than needed, and 
 * those leftover characters should be used in subsequent calls.
 * 
 * Example:
 * File: "abcdefghij"
 * 
 * read(buf, 1) -> should return "a" (count=1)
 * read(buf, 2) -> should return "bc" (count=2) 
 * read(buf, 3) -> should return "def" (count=3)
 * read(buf, 4) -> should return "ghij" (count=4)
 * read(buf, 1) -> should return "" (count=0) - EOF reached
 * 
 * The challenge is maintaining state between multiple calls to read().
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

// Global variables to simulate file reading
static char* file_content = NULL;
static int file_pointer = 0;
static int file_length = 0;

// State variables for maintaining leftover characters between calls
static char leftover_buffer[4];  // Buffer to store leftover characters from previous read4 calls
static int leftover_count = 0;   // Number of characters in leftover buffer
static int leftover_index = 0;   // Current index in leftover buffer

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
int read_multiple_times(char *buf, int n) {
    int total_chars_read = 0;
    
    // First, use any leftover characters from previous calls
    while (leftover_index < leftover_count && total_chars_read < n) {
        buf[total_chars_read] = leftover_buffer[leftover_index];
        total_chars_read++;
        leftover_index++;
    }
    
    // If we've used all leftover characters, reset the leftover state
    if (leftover_index >= leftover_count) {
        leftover_count = 0;
        leftover_index = 0;
    }
    
    // Continue reading from file if we need more characters
    while (total_chars_read < n) {
        char temp_buffer[4];
        int chars_from_read4 = read4(temp_buffer);
        
        // If no more characters available, break
        if (chars_from_read4 == 0) {
            break;
        }
        
        // Copy characters from temp buffer to destination buffer
        int chars_to_copy = 0;
        while (chars_to_copy < chars_from_read4 && total_chars_read < n) {
            buf[total_chars_read] = temp_buffer[chars_to_copy];
            total_chars_read++;
            chars_to_copy++;
        }
        
        // If there are leftover characters from this read4 call, store them
        if (chars_to_copy < chars_from_read4) {
            leftover_count = chars_from_read4 - chars_to_copy;
            leftover_index = 0;
            for (int i = 0; i < leftover_count; i++) {
                leftover_buffer[i] = temp_buffer[chars_to_copy + i];
            }
        }
    }
    
    return total_chars_read;
}

// Helper function to initialize file simulation
void init_file(const char* content) {
    file_content = (char*)content;
    file_pointer = 0;
    file_length = strlen(content);
    
    // Reset leftover state for new file
    leftover_count = 0;
    leftover_index = 0;
}

// Helper function to reset file pointer for new test scenario
void reset_file() {
    file_pointer = 0;
    leftover_count = 0;
    leftover_index = 0;
}

// Test function for single read call
void test_single_read(const char* file_content_str, int n, const char* expected, int expected_count) {
    init_file(file_content_str);
    
    char buf[1000] = {0};  // Large enough buffer
    int result = read_multiple_times(buf, n);
    
    printf("File: \"%s\", n: %d\n", file_content_str, n);
    printf("Expected: \"%.*s\" (count: %d)\n", expected_count, expected, expected_count);
    printf("Got:      \"%.*s\" (count: %d)\n", result, buf, result);
    printf("Test %s\n\n", (result == expected_count && strncmp(buf, expected, result) == 0) ? "PASSED" : "FAILED");
}

// Test function for multiple read calls on same file
void test_multiple_reads() {
    printf("=== Testing Multiple Read Calls on Same File ===\n\n");
    
    // Test Case: Multiple reads on "abcdefghij"
    init_file("abcdefghij");
    
    char buf[100];
    int result;
    
    // Read 1 character
    memset(buf, 0, sizeof(buf));
    result = read_multiple_times(buf, 1);
    printf("Read 1: Expected \"a\" (1), Got \"%.*s\" (%d) - %s\n", 
           result, buf, result, (result == 1 && buf[0] == 'a') ? "PASS" : "FAIL");
    
    // Read 2 characters
    memset(buf, 0, sizeof(buf));
    result = read_multiple_times(buf, 2);
    printf("Read 2: Expected \"bc\" (2), Got \"%.*s\" (%d) - %s\n", 
           result, buf, result, (result == 2 && strncmp(buf, "bc", 2) == 0) ? "PASS" : "FAIL");
    
    // Read 3 characters
    memset(buf, 0, sizeof(buf));
    result = read_multiple_times(buf, 3);
    printf("Read 3: Expected \"def\" (3), Got \"%.*s\" (%d) - %s\n", 
           result, buf, result, (result == 3 && strncmp(buf, "def", 3) == 0) ? "PASS" : "FAIL");
    
    // Read 4 characters
    memset(buf, 0, sizeof(buf));
    result = read_multiple_times(buf, 4);
    printf("Read 4: Expected \"ghij\" (4), Got \"%.*s\" (%d) - %s\n", 
           result, buf, result, (result == 4 && strncmp(buf, "ghij", 4) == 0) ? "PASS" : "FAIL");
    
    // Try to read 1 more character (should be EOF)
    memset(buf, 0, sizeof(buf));
    result = read_multiple_times(buf, 1);
    printf("Read 5: Expected \"\" (0), Got \"%.*s\" (%d) - %s\n\n", 
           result, buf, result, (result == 0) ? "PASS" : "FAIL");
}

void test_edge_cases_multiple_reads() {
    printf("=== Testing Edge Cases with Multiple Reads ===\n\n");
    
    // Test Case 1: File with exactly 4 characters
    printf("Test 1: File with exactly 4 characters\n");
    init_file("abcd");
    
    char buf[100];
    int result;
    
    memset(buf, 0, sizeof(buf));
    result = read_multiple_times(buf, 2);
    printf("Read 2: Got \"%.*s\" (%d) - %s\n", 
           result, buf, result, (result == 2 && strncmp(buf, "ab", 2) == 0) ? "PASS" : "FAIL");
    
    memset(buf, 0, sizeof(buf));
    result = read_multiple_times(buf, 2);
    printf("Read 2: Got \"%.*s\" (%d) - %s\n\n", 
           result, buf, result, (result == 2 && strncmp(buf, "cd", 2) == 0) ? "PASS" : "FAIL");
    
    // Test Case 2: Single character file
    printf("Test 2: Single character file\n");
    init_file("x");
    
    memset(buf, 0, sizeof(buf));
    result = read_multiple_times(buf, 1);
    printf("Read 1: Got \"%.*s\" (%d) - %s\n", 
           result, buf, result, (result == 1 && buf[0] == 'x') ? "PASS" : "FAIL");
    
    memset(buf, 0, sizeof(buf));
    result = read_multiple_times(buf, 1);
    printf("Read 1: Got \"%.*s\" (%d) - %s\n\n", 
           result, buf, result, (result == 0) ? "PASS" : "FAIL");
    
    // Test Case 3: Large read followed by small reads
    printf("Test 3: Large read followed by small reads\n");
    init_file("abcdefghijklmnop");
    
    memset(buf, 0, sizeof(buf));
    result = read_multiple_times(buf, 10);
    printf("Read 10: Got \"%.*s\" (%d) - %s\n", 
           result, buf, result, (result == 10 && strncmp(buf, "abcdefghij", 10) == 0) ? "PASS" : "FAIL");
    
    memset(buf, 0, sizeof(buf));
    result = read_multiple_times(buf, 3);
    printf("Read 3: Got \"%.*s\" (%d) - %s\n", 
           result, buf, result, (result == 3 && strncmp(buf, "klm", 3) == 0) ? "PASS" : "FAIL");
    
    memset(buf, 0, sizeof(buf));
    result = read_multiple_times(buf, 3);
    printf("Read 3: Got \"%.*s\" (%d) - %s\n\n", 
           result, buf, result, (result == 3 && strncmp(buf, "nop", 3) == 0) ? "PASS" : "FAIL");
}

int main() {
    printf("=== Read N Characters Given Read4 II - Call Multiple Times ===\n\n");
    
    // Basic single read tests (similar to previous problem)
    printf("=== Basic Single Read Tests ===\n\n");
    test_single_read("abc", 4, "abc", 3);
    test_single_read("abcde", 5, "abcde", 5);
    test_single_read("leetcode", 5, "leetc", 5);
    test_single_read("", 1, "", 0);
    
    // Multiple reads on same file - the main focus of this problem
    test_multiple_reads();
    
    // Edge cases with multiple reads
    test_edge_cases_multiple_reads();
    
    printf("=== Algorithm Analysis ===\n");
    printf("Time Complexity: O(n) where n is the number of characters to read per call\n");
    printf("Space Complexity: O(1) - using fixed size buffers for leftover characters\n\n");
    
    printf("=== Key Differences from Read4 I ===\n");
    printf("1. Maintain state between multiple calls to read()\n");
    printf("2. Handle leftover characters from previous read4() calls\n");
    printf("3. Use static/global variables to preserve state\n");
    printf("4. Leftover buffer stores unused characters from read4()\n");
    printf("5. Each read() call first consumes leftover characters\n");
    printf("6. More complex state management for EOF detection\n\n");
    
    printf("=== Implementation Details ===\n");
    printf("1. leftover_buffer[4]: stores unused characters from read4()\n");
    printf("2. leftover_count: number of characters in leftover buffer\n");
    printf("3. leftover_index: current reading position in leftover buffer\n");
    printf("4. Always consume leftovers first, then call read4() if needed\n");
    printf("5. Store any excess characters for next read() call\n");
    
    return 0;
}

/*
 * Compilation and Execution:
 * gcc -o read_n_chars_ii Read-N-Characters-From-Buffer-II-Multiple-Times.c
 * ./read_n_chars_ii
 * 
 * Expected Output:
 * All test cases should pass, demonstrating the correctness of the algorithm
 * for multiple sequential read operations.
 * 
 * Algorithm Explanation:
 * 
 * The key challenge is maintaining state between multiple calls to read().
 * 
 * State Variables:
 * - leftover_buffer[4]: Buffer to store unused characters from previous read4() calls
 * - leftover_count: Number of valid characters in leftover_buffer
 * - leftover_index: Current reading position in leftover_buffer
 * 
 * Algorithm Steps:
 * 1. First, consume any leftover characters from previous calls
 * 2. If more characters needed, call read4() to get new characters
 * 3. Copy required characters to destination buffer
 * 4. Store any excess characters in leftover_buffer for next call
 * 5. Return actual number of characters read
 * 
 * Example Trace:
 * File: "abcdefghij"
 * 
 * Call 1: read(buf, 1)
 * - No leftovers initially
 * - Call read4() -> gets "abcd" (4 chars)
 * - Copy 1 char ('a') to buf
 * - Store "bcd" in leftover_buffer
 * - Return 1
 * 
 * Call 2: read(buf, 2) 
 * - Have leftovers: "bcd"
 * - Copy 2 chars ('b', 'c') from leftovers
 * - leftover_buffer now has "d"
 * - Return 2
 * 
 * Call 3: read(buf, 3)
 * - Have leftover: "d"
 * - Copy 1 char ('d') from leftovers
 * - Need 2 more chars, call read4() -> gets "efgh"
 * - Copy 2 more chars ('e', 'f') to buf  
 * - Store "gh" in leftover_buffer
 * - Return 3
 * 
 * And so on...
 * 
 * Edge Cases Handled:
 * - Multiple reads on same file
 * - File shorter than total requested characters across calls
 * - Reading exactly the file length across multiple calls
 * - Large reads followed by small reads
 * - Small reads followed by large reads
 * - EOF detection across multiple calls
 */
