#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>
#include <string.h>
#include <assert.h>


// Corrected function with overflow handling
int myAtoi_corrected(char* s) {
    if (s == NULL) return 0;
    
    char *temp = s;
    
    // Skip leading whitespaces
    while (*temp == ' ') {
        temp++;
    }
    
    // Handle empty string after skipping spaces
    if (*temp == '\0') {
        return 0;
    }
    
    // Handle sign
    bool isNegative = false;
    if (*temp == '-') {
        isNegative = true;
        temp++;
    } else if (*temp == '+') {
        temp++;
    }
    
    // Check if string becomes empty after sign
    if (*temp == '\0') {
        return 0;
    }
    
    long long result = 0;
    
    // Process digits
    while (*temp != '\0' && isdigit(*temp)) {
        int digit = *temp - '0';
        
        // Check for overflow before multiplying
        if (result > (LLONG_MAX - digit) / 10) {
            return isNegative ? INT_MIN : INT_MAX;
        }
        
        result = result * 10 + digit;
        temp++;
    }
    
    // Apply sign
    if (isNegative) {
        result = -result;
    }
    
    // Clamp to int range
    if (result > INT_MAX) return INT_MAX;
    if (result < INT_MIN) return INT_MIN;
    
    return (int)result;
}

// Test function
void test_myAtoi(char* input, int expected, const char* test_name) {
    printf("Test: %s\n", test_name);
    printf("Input: \"%s\"\n", input ? input : "NULL");
    
    int result_corrected = myAtoi_corrected(input);
    printf("Expected: %d, Got (corrected): %d", expected, result_corrected);
    
    if (result_corrected == expected) {
        printf(" ✓ PASS\n");
    } else {
        printf(" ✗ FAIL\n");
    }
    printf("---\n");
}

int main() {
    printf("=== myAtoi Function Test Cases ===\n\n");
    
    // Basic positive and negative numbers
    test_myAtoi("42", 42, "Basic positive number");
    test_myAtoi("-42", -42, "Basic negative number");
    test_myAtoi("+42", 42, "Positive sign");
    
    // Leading and trailing spaces
    test_myAtoi("   42", 42, "Leading spaces");
    test_myAtoi("42   ", 42, "Trailing spaces (should be ignored after digits)");
    test_myAtoi("   -42   ", -42, "Leading and trailing spaces with negative");
    
    // Edge cases with whitespace
    test_myAtoi("", 0, "Empty string");
    test_myAtoi("   ", 0, "Only spaces");
    test_myAtoi("   +", 0, "Only spaces and sign");
    test_myAtoi("   -", 0, "Only spaces and negative sign");
    
    // Mixed content
    test_myAtoi("4193 with words", 4193, "Number followed by words");
    test_myAtoi("words and 987", 0, "Words before number");
    test_myAtoi("-91283472332", INT_MIN, "Negative overflow");
    test_myAtoi("91283472332", INT_MAX, "Positive overflow");
    
    // Zero cases
    test_myAtoi("0", 0, "Zero");
    test_myAtoi("-0", 0, "Negative zero");
    test_myAtoi("+0", 0, "Positive zero");
    test_myAtoi("00000123", 123, "Leading zeros");
    
    // Invalid inputs
    test_myAtoi("+-12", 0, "Multiple signs");
    test_myAtoi("--12", 0, "Double negative");
    test_myAtoi("++12", 0, "Double positive");
    test_myAtoi("abc", 0, "Non-numeric string");
    test_myAtoi("12abc34", 12, "Number with letters in middle");
    
    // Boundary values
    char int_max_str[20], int_min_str[20];
    sprintf(int_max_str, "%d", INT_MAX);
    sprintf(int_min_str, "%d", INT_MIN);
    test_myAtoi(int_max_str, INT_MAX, "INT_MAX boundary");
    test_myAtoi(int_min_str, INT_MIN, "INT_MIN boundary");
    
    // Just beyond boundaries
    test_myAtoi("2147483648", INT_MAX, "INT_MAX + 1 (overflow)");
    test_myAtoi("-2147483649", INT_MIN, "INT_MIN - 1 (underflow)");
    
    // NULL pointer test
    test_myAtoi(NULL, 0, "NULL pointer");
    
    return 0;
}
