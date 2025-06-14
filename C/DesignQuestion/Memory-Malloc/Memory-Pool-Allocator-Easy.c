#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Memory Pool structure
typedef struct MemoryPool {
    void *pool;          // Pointer to the memory pool
    size_t blockSize;    // Size of each block
    size_t poolSize;     // Total size of the pool
    void **freeList;     // List of free blocks
    size_t freeCount;    // Number of free blocks
} MemoryPool;

// Initialize the memory pool
MemoryPool *createMemoryPool(size_t blockSize, size_t blockCount) {
    MemoryPool *mp = (MemoryPool *)malloc(sizeof(MemoryPool));
    if (!mp) {
        perror("Failed to allocate memory for MemoryPool");
        return NULL;
    }

    mp->blockSize = blockSize;
    mp->poolSize = blockSize * blockCount;
    mp->pool = malloc(mp->poolSize);
    if (!mp->pool) {
        perror("Failed to allocate memory for pool");
        free(mp);
        return NULL;
    }

    mp->freeList = (void **)malloc(blockCount * sizeof(void *));
    if (!mp->freeList) {
        perror("Failed to allocate memory for free list");
        free(mp->pool);
        free(mp);
        return NULL;
    }

    mp->freeCount = blockCount;
    for (size_t i = 0; i < blockCount; i++) {
        mp->freeList[i] = (char *)mp->pool + i * blockSize;
    }

    return mp;
}

// Allocate a block from the memory pool
void *allocateBlock(MemoryPool *mp) {
    if (mp->freeCount == 0) {
        fprintf(stderr, "Memory pool exhausted\n");
        return NULL;
    }

    void *block = mp->freeList[--mp->freeCount];
    return block;
}

// Free a block back to the memory pool
void freeBlock(MemoryPool *mp, void *block) {
    if (mp->freeCount >= mp->poolSize / mp->blockSize) {
        fprintf(stderr, "Memory pool overflow\n");
        return;
    }

    mp->freeList[mp->freeCount++] = block;
}

// Destroy the memory pool
void destroyMemoryPool(MemoryPool *mp) {
    free(mp->pool);
    free(mp->freeList);
    free(mp);
}

int main() {
    size_t blockSize = 32;  // Size of each block
    size_t blockCount = 10; // Number of blocks

    // Create memory pool
    MemoryPool *mp = createMemoryPool(blockSize, blockCount);
    if (!mp) {
        return EXIT_FAILURE;
    }

    // Allocate blocks
    void *block1 = allocateBlock(mp);
    void *block2 = allocateBlock(mp);

    printf("Allocated blocks: %p, %p\n", block1, block2);

    // Free blocks
    freeBlock(mp, block1);
    freeBlock(mp, block2);

    printf("Blocks freed\n");

    // Destroy memory pool
    destroyMemoryPool(mp);

    return EXIT_SUCCESS;
}
