#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <assert.h>

/* Memory block metadata structure */
typedef struct block_meta {
    size_t size;
    struct block_meta *next;
    int free;
    int magic;    // For debugging - helps identify if a block is valid
} block_meta;

#define META_SIZE sizeof(struct block_meta)

// Start of our managed memory linked list
static block_meta *global_base = NULL;

// Find a free block with at least 'size' bytes
block_meta *find_free_block(block_meta **last, size_t size) {
    block_meta *current = global_base;
    while (current && !(current->free && current->size >= size)) {
        *last = current;
        current = current->next;
    }
    return current;
}

// Request memory from the OS
block_meta *request_space(block_meta *last, size_t size) {
    block_meta *block;
    block = sbrk(0);
    void *request = sbrk(size + META_SIZE);
    assert((void*)block == request); // Not thread safe
    
    if (request == (void*) -1) {
        return NULL; // sbrk failed
    }
    
    if (last) { // NULL on first request
        last->next = block;
    }
    
    block->size = size;
    block->next = NULL;
    block->free = 0;
    block->magic = 0x12345678; // Debug marker
    
    return block;
}

// Merge adjacent free blocks - basic coalescing
void coalesce_free_blocks() {
    block_meta *current = global_base;
    while (current && current->next) {
        if (current->free && current->next->free) {
            // Merge the two blocks
            current->size += META_SIZE + current->next->size;
            current->next = current->next->next;
            // Continue checking from this block
        } else {
            current = current->next;
        }
    }
}

// Custom malloc implementation
void *custom_malloc(size_t size) {
    if (size <= 0) {
        return NULL;
    }
    
    // Align size to multiple of 8 bytes (for most architectures)
    size = (size + 7) & ~7;
    
    block_meta *block;
    
    // First call - initialize
    if (global_base == NULL) {
        block = request_space(NULL, size);
        if (!block) {
            return NULL;
        }
        global_base = block;
    } else {
        block_meta *last = global_base;
        block = find_free_block(&last, size);
        if (!block) { // Failed to find free block
            block = request_space(last, size);
            if (!block) {
                return NULL;
            }
        } else {      // Found free block
            // Split block if it's significantly larger than what we need
            if (block->size > size + META_SIZE + 8) {
                block_meta *new_block = (block_meta*)((char*)block + META_SIZE + size);
                new_block->size = block->size - size - META_SIZE;
                new_block->next = block->next;
                new_block->free = 1;
                new_block->magic = 0x12345678;
                
                block->size = size;
                block->next = new_block;
            }
            block->free = 0;
        }
    }
    
    return (block + 1); // Return pointer to the memory after the metadata
}

// Custom free implementation
void custom_free(void *ptr) {
    if (!ptr) {
        return;
    }
    
    // Get the block metadata
    block_meta *block_ptr = (block_meta*)ptr - 1;
    
    // Validate that this is a valid block
    assert(block_ptr->magic == 0x12345678);
    
    // Mark the block as free
    block_ptr->free = 1;
    
    // Try to merge adjacent free blocks
    coalesce_free_blocks();
}

// Utility function to get block size
size_t custom_malloc_size(void *ptr) {
    if (!ptr) {
        return 0;
    }
    block_meta *block_ptr = (block_meta*)ptr - 1;
    assert(block_ptr->magic == 0x12345678);
    return block_ptr->size;
}

// Utility function to print memory layout for debugging
void print_memory_layout() {
    block_meta *current = global_base;
    printf("\nMEMORY LAYOUT:\n");
    while (current) {
        printf("[%p] Size: %zu, Free: %d\n", 
               (void*)current, current->size, current->free);
        current = current->next;
    }
    printf("\n");
}

int main() {
    printf("Custom Memory Allocator Demo\n");
    
    // Allocate memory
    char *str1 = (char*)custom_malloc(20);
    strcpy(str1, "Hello World!");
    printf("Allocated 20 bytes at %p: %s\n", (void*)str1, str1);
    
    print_memory_layout();
    
    // Allocate more memory
    int *array = (int*)custom_malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) {
        array[i] = i * 10;
    }
    printf("Allocated array at %p: [%d, %d, %d, %d, %d]\n", 
           (void*)array, array[0], array[1], array[2], array[3], array[4]);
    
    print_memory_layout();
    
    // Free first allocation
    printf("Freeing str1...\n");
    custom_free(str1);
    print_memory_layout();
    
    // Allocate again - should reuse the freed memory
    char *str2 = (char*)custom_malloc(10);
    strcpy(str2, "Recycled!");
    printf("Allocated 10 bytes at %p: %s\n", (void*)str2, str2);
    
    print_memory_layout();
    
    // Free all allocations
    printf("Freeing all allocations...\n");
    custom_free(str2);
    custom_free(array);
    print_memory_layout();
    
    return 0;
}
