#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

#define POOL_BLOCKS_INITIAL 1

typedef struct poolFreed{
	struct poolFreed *nextFree;
} poolFreed;

typedef struct {
	uint32_t chunkSize;
	uint32_t blockSize;
	uint32_t used;
	int32_t block;
	poolFreed *freed;
	uint32_t blocksUsed;
	uint8_t **blocks;
} pool;

void poolInitialize(pool *p, const uint32_t chunkSize, const uint32_t blockSize);
void poolFreePool(pool *p);
void *poolMalloc(pool *p);
void poolFree(pool *p, void *ptr);

#define max(a,b) ((a)<(b)?(b):(a))

/*
Pool Initialization function. Pool is only able to allocate chunSize objects
*/
void poolInitialize(pool *p, const uint32_t chunkSize, const uint32_t blockSize)
{
	uint32_t i;

	// define chunk and block parammeters
	p->chunkSize = max(chunkSize, sizeof(poolFreed));
	p->blockSize = blockSize;
    
    // Clear the pool before any usage
	poolFreeAll(p);

	// assign initial number of blocks
	p->blocksUsed = POOL_BLOCKS_INITIAL; // 1
	p->blocks = malloc(sizeof(uint8_t*) * p->blocksUsed);

	for(i = 0; i < p->blocksUsed; ++i)
		p->blocks[i] = NULL;
}

void poolFreePool(pool *p)
{
	uint32_t i;
	for(i = 0; i < p->blocksUsed; ++i) {
		if(p->blocks[i] == NULL)
			break;
		else
			free(p->blocks[i]); // free this block
	}

	// free all block 
	free(p->blocks);
}

void *poolMalloc(pool *p)
{
	// if there is free chunk, reuse it
	if(p->freed != NULL) {
		void *recycle = p->freed;
		p->freed = p->freed->nextFree;
		return recycle;
	}

	// else, we proceed to the chunk in current block
	// if block is full
	if(++p->used == p->blockSize) {
		p->used = 0; // reset used chunk number to 0
		// if we also run out of blocks
		if(++p->block == (int32_t)p->blocksUsed) {
			uint32_t i;

			// assign 2 times block size
			p->blocksUsed <<= 1;
			p->blocks = realloc(p->blocks, sizeof(uint8_t*)* p->blocksUsed);

			// initialize to be NULL
			for(i = p->blocksUsed >> 1; i < p->blocksUsed; ++i)
				p->blocks[i] = NULL;
		}

		// assign memory for this free block
		if(p->blocks[p->block] == NULL)
			p->blocks[p->block] = malloc(p->chunkSize * p->blockSize);
	}
	
	// return the next free chunk address
	return p->blocks[p->block] + p->used * p->chunkSize;
}

void poolFree(pool *p, void *ptr)
{
	if(ptr == NULL)
		return;

	// add to free list
	poolFreed *freed = (poolFreed*)ptr;
	freed->nextFree = p->freed;
	p->freed = freed;
}

void poolFreeAll(pool *p)
{
	// reinitialize all 
	p->used = p->blockSize - 1;
	p->block = -1;
	p->freed = NULL;
}
