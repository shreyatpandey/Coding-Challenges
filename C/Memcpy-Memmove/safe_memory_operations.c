#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

// Function declarations
void* safe_memcpy(void* dest, const void* src, size_t n);
void* safe_memmove(void* dest, const void* src, size_t n);

/**
 * Safe memcpy implementation that detects overlapping regions
 * and handles them appropriately by using memmove internally
 * 
 * @param dest: destination pointer
 * @param src: source pointer  
 * @param n: number of bytes to copy
 * @return: pointer to destination
 */
void* safe_memcpy(void* dest, const void* src, size_t n) {
    if (dest == NULL || src == NULL || n == 0) {
        return dest;
    }
    
    // Check for overlap
    uintptr_t dest_start = (uintptr_t)dest;
    uintptr_t dest_end = dest_start + n - 1;
    uintptr_t src_start = (uintptr_t)src;
    uintptr_t src_end = src_start + n - 1;
    
    // Overlap detection: ranges overlap if one starts before the other ends
    if ((dest_start <= src_end) && (src_start <= dest_end)) {
        printf("WARNING: Overlapping memory regions detected in memcpy!\n");
        printf("Source: %p to %p, Destination: %p to %p\n", 
               src, (char*)src + n - 1, dest, (char*)dest + n - 1);
        printf("Using memmove for safe operation...\n");
        return safe_memmove(dest, src, n);
    }
    
    // No overlap, perform standard byte-by-byte copy
    char* d = (char*)dest;
    const char* s = (const char*)src;
    
    for (size_t i = 0; i < n; i++) {
        d[i] = s[i];
    }
    
    return dest;
}

/**
 * Safe memmove implementation that handles overlapping memory regions
 * by choosing the appropriate copy direction
 * 
 * @param dest: destination pointer
 * @param src: source pointer
 * @param n: number of bytes to move
 * @return: pointer to destination
 */
void* safe_memmove(void* dest, const void* src, size_t n) {
    if (dest == NULL || src == NULL || n == 0) {
        return dest;
    }
    
    char* d = (char*)dest;
    const char* s = (const char*)src;
    
    // If dest comes after src in memory, copy backwards to avoid corruption
    if (d > s && d < s + n) {
        // Overlapping: destination is ahead of source
        // Copy from end to beginning to avoid overwriting source data
        for (size_t i = n; i > 0; i--) {
            d[i - 1] = s[i - 1];
        }
    } else {
        // No overlap or destination is before source
        // Copy from beginning to end
        for (size_t i = 0; i < n; i++) {
            d[i] = s[i];
        }
    }
    
    return dest;
}

/**
 * Utility function to print memory contents in hex format
 */
void print_memory(const void* ptr, size_t n, const char* label) {
    const unsigned char* p = (const unsigned char*)ptr;
    printf("%s: ", label);
    for (size_t i = 0; i < n; i++) {
        printf("%02X ", p[i]);
    }
    printf("\n");
}

/**
 * Test function to demonstrate overlap scenarios
 */
void test_overlap_scenarios() {
    printf("=== Testing Overlap Scenarios ===\n\n");
    
    // Test Case 1: No overlap
    printf("Test 1: No overlap\n");
    char buffer1[20] = "Hello World!";
    char buffer2[20];
    
    print_memory(buffer1, 12, "Source");
    safe_memcpy(buffer2, buffer1, 12);
    print_memory(buffer2, 12, "Destination");
    printf("Result: %s\n\n", buffer2);
    
    // Test Case 2: Forward overlap (dest > src)
    printf("Test 2: Forward overlap (destination ahead of source)\n");
    char buffer3[20] = "ABCDEFGHIJKLMNOP";
    print_memory(buffer3, 16, "Before");
    
    // Copy from position 0 to position 4 (overlap)
    safe_memmove(buffer3 + 4, buffer3, 8);
    print_memory(buffer3, 16, "After memmove");
    printf("Buffer: %s\n\n", buffer3);
    
    // Test Case 3: Backward overlap (dest < src) 
    printf("Test 3: Backward overlap (destination before source)\n");
    char buffer4[20] = "ABCDEFGHIJKLMNOP";
    print_memory(buffer4, 16, "Before");
    
    // Copy from position 4 to position 0 (overlap)
    safe_memmove(buffer4, buffer4 + 4, 8);
    print_memory(buffer4, 16, "After memmove");
    printf("Buffer: %s\n\n", buffer4);
    
    // Test Case 4: Using safe_memcpy with overlap (should warn and use memmove)
    printf("Test 4: safe_memcpy with overlap detection\n");
    char buffer5[20] = "TESTOVERLAP12345";
    print_memory(buffer5, 16, "Before");
    
    safe_memcpy(buffer5 + 3, buffer5, 8);
    print_memory(buffer5, 16, "After safe_memcpy");
    printf("Buffer: %s\n\n", buffer5);
}

/**
 * Performance comparison between implementations
 */
void performance_test() {
    printf("=== Performance Test ===\n");
    const size_t test_size = 1000000;
    char* large_buffer = malloc(test_size * 2);
    
    if (!large_buffer) {
        printf("Failed to allocate memory for performance test\n");
        return;
    }
    
    // Initialize with test data
    for (size_t i = 0; i < test_size; i++) {
        large_buffer[i] = (char)(i % 256);
    }
    
    printf("Testing with %zu bytes...\n", test_size);
    
    // Test standard memcpy (no overlap)
    clock_t start = clock();
    memcpy(large_buffer + test_size, large_buffer, test_size);
    clock_t end = clock();
    double std_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    // Test our safe_memcpy (no overlap)
    start = clock();
    safe_memcpy(large_buffer + test_size, large_buffer, test_size);
    end = clock();
    double safe_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("Standard memcpy time: %.6f seconds\n", std_time);
    printf("Safe memcpy time: %.6f seconds\n", safe_time);
    printf("Overhead: %.2f%%\n", ((safe_time - std_time) / std_time) * 100);
    
    free(large_buffer);
}

/**
 * Test edge cases
 */
void test_edge_cases() {
    printf("=== Testing Edge Cases ===\n\n");
    
    // Test with NULL pointers
    printf("Test 1: NULL pointers\n");
    char* result1 = (char*)safe_memcpy(NULL, "test", 4);
    char* result2 = (char*)safe_memmove(NULL, "test", 4);
    printf("safe_memcpy with NULL dest: %p\n", (void*)result1);
    printf("safe_memmove with NULL dest: %p\n\n", (void*)result2);
    
    // Test with zero size
    printf("Test 2: Zero size\n");
    char buffer[10] = "Hello";
    safe_memcpy(buffer + 2, buffer, 0);
    printf("Buffer after zero-size copy: %s\n\n", buffer);
    
    // Test with same source and destination
    printf("Test 3: Same source and destination\n");
    char buffer2[10] = "Same";
    safe_memmove(buffer2, buffer2, 4);
    printf("Buffer after self-copy: %s\n\n", buffer2);
}

int main() {
    printf("Safe Memory Operations Demo\n");
    printf("===========================\n\n");
    
    test_overlap_scenarios();
    test_edge_cases();
    performance_test();

    printf("\n=== Summary ===\n");

    return 0;
}
