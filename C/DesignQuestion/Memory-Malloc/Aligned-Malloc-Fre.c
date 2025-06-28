#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<assert.h>

void *aligned_malloc(size_t bytes, size_t alignment)
{
    // If alignment is zero or not a power of two, return NULL
    if (alignment == 0 || (alignment & (alignment - 1)) != 0) {
        return NULL;
    }
    
    // Handle zero bytes request
    if (bytes == 0) {
        return NULL;
    }

    void *malloc_pointer, *aligned_memory_pointer;
    
    /* We need to allocate:
     * 1. 'bytes' for user data
     * 2. 'alignment - 1' for worst case alignment adjustment
     * 3. 'sizeof(void*)' to store original malloc pointer
     * Note: We use alignment-1 instead of alignment because in worst case
     * we only need to move forward by alignment-1 bytes to reach alignment
     */
    size_t total_size = bytes + alignment - 1 + sizeof(void*);
    
    malloc_pointer = malloc(total_size);
    if (malloc_pointer == NULL) {
        return NULL;
    }

    /* Calculate aligned address:
     * 1. Start from malloc_pointer + sizeof(void*) to reserve space for storing original pointer
     * 2. Find the next aligned address using: ((addr + alignment - 1) / alignment) * alignment
     * This is equivalent to: addr + ((alignment - (addr % alignment)) % alignment)
     */
    uintptr_t raw_addr = (uintptr_t)malloc_pointer + sizeof(void*);
    uintptr_t aligned_addr = (raw_addr + alignment - 1) & ~(alignment - 1);
    
    aligned_memory_pointer = (void*)aligned_addr;

    /* Store the original malloc pointer just before the aligned memory
     * This ensures we can retrieve it during aligned_free
     */
    *((void**)aligned_memory_pointer - 1) = malloc_pointer;

    return aligned_memory_pointer;
}

void aligned_free(void *p)
{
    if (p == NULL) {
        return; // Handle null pointer gracefully
    }
    
    /* Retrieve the original malloc pointer stored just before the aligned memory
     * and free it using normal free routine provided by C.
     */
    void *original_ptr = *((void**)p - 1);
    free(original_ptr);
}

/* Test function to verify alignment */
int is_aligned(void *ptr, size_t alignment) {
    return ((uintptr_t)ptr % alignment) == 0;
}

/* Comprehensive test cases */
void test_aligned_malloc() {
    printf("=== Testing Aligned Malloc Implementation ===\n\n");
    
    // Test 1: Basic alignment test
    printf("Test 1: Basic alignment tests\n");
    void *ptr1 = aligned_malloc(100, 16);
    printf("16-byte aligned malloc: %p, aligned: %s\n", 
           ptr1, is_aligned(ptr1, 16) ? "YES" : "NO");
    aligned_free(ptr1);
    
    void *ptr2 = aligned_malloc(100, 32);
    printf("32-byte aligned malloc: %p, aligned: %s\n", 
           ptr2, is_aligned(ptr2, 32) ? "YES" : "NO");
    aligned_free(ptr2);
    
    void *ptr3 = aligned_malloc(100, 64);
    printf("64-byte aligned malloc: %p, aligned: %s\n", 
           ptr3, is_aligned(ptr3, 64) ? "YES" : "NO");
    aligned_free(ptr3);
    
    // Test 2: Edge cases
    printf("\nTest 2: Edge cases\n");
    
    // Zero bytes
    void *ptr_zero = aligned_malloc(0, 16);
    printf("Zero bytes allocation: %p (should be NULL)\n", ptr_zero);
    
    // Invalid alignment (not power of 2)
    void *ptr_invalid = aligned_malloc(100, 15);
    printf("Invalid alignment (15): %p (should be NULL)\n", ptr_invalid);
    
    // Zero alignment
    void *ptr_zero_align = aligned_malloc(100, 0);
    printf("Zero alignment: %p (should be NULL)\n", ptr_zero_align);
    
    // Test 3: Memory usage and data integrity
    printf("\nTest 3: Data integrity test\n");
    int *int_ptr = (int*)aligned_malloc(sizeof(int) * 10, 16);
    if (int_ptr && is_aligned(int_ptr, 16)) {
        // Write data
        for (int i = 0; i < 10; i++) {
            int_ptr[i] = i * i;
        }
        
        // Read and verify data
        int data_ok = 1;
        for (int i = 0; i < 10; i++) {
            if (int_ptr[i] != i * i) {
                data_ok = 0;
                break;
            }
        }
        printf("Data integrity: %s\n", data_ok ? "PASS" : "FAIL");
        aligned_free(int_ptr);
    }
    
    // Test 4: Multiple allocations
    printf("\nTest 4: Multiple allocations\n");
    void *ptrs[5];
    size_t alignments[] = {8, 16, 32, 64, 128};
    
    for (int i = 0; i < 5; i++) {
        ptrs[i] = aligned_malloc(100, alignments[i]);
        printf("Allocation %d (%zu-byte aligned): %p, aligned: %s\n", 
               i+1, alignments[i], ptrs[i], 
               is_aligned(ptrs[i], alignments[i]) ? "YES" : "NO");
    }
    
    // Free all allocations
    for (int i = 0; i < 5; i++) {
        aligned_free(ptrs[i]);
    }
    
    // Test 5: Large alignment
    printf("\nTest 5: Large alignment test\n");
    void *large_align = aligned_malloc(1000, 4096);
    printf("4096-byte aligned malloc: %p, aligned: %s\n", 
           large_align, is_aligned(large_align, 4096) ? "YES" : "NO");
    aligned_free(large_align);
    
    // Test 6: Null pointer free (should not crash)
    printf("\nTest 6: Null pointer free test\n");
    aligned_free(NULL);
    printf("aligned_free(NULL): PASS (no crash)\n");
    
    printf("\n=== All tests completed ===\n");
}

int main() {
    test_aligned_malloc();
    return 0;
}
