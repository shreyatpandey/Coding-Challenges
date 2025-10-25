# System-Level Understanding: Memory Allocator Implementation

## 1. Thread Safety Implementation

Making the memory allocator thread-safe is critical for embedded systems with multiple threads or processors.

### Approach 1: Mutex-Based Synchronization

```c
#include <pthread.h>

typedef struct {
    pthread_mutex_t lock;
    struct block *freeList;
    char memory[MAX_CAPACITY];
} thread_safe_allocator_t;

thread_safe_allocator_t allocator;

void* MyMalloc_ThreadSafe(size_t size) {
    pthread_mutex_lock(&allocator.lock);
    
    // Critical section
    void *ptr = MyMalloc(size);
    
    pthread_mutex_unlock(&allocator.lock);
    return ptr;
}

void MyFree_ThreadSafe(void *ptr) {
    pthread_mutex_lock(&allocator.lock);
    
    // Critical section
    MyFree(ptr);
    
    pthread_mutex_unlock(&allocator.lock);
}
```

### Approach 2: Read-Write Lock

```c
#include <pthread.h>

pthread_rwlock_t alloc_lock = PTHREAD_RWLOCK_INITIALIZER;

void* MyMalloc_RWLock(size_t size) {
    pthread_rwlock_wrlock(&alloc_lock);  // Write lock for modification
    void *ptr = MyMalloc(size);
    pthread_rwlock_unlock(&alloc_lock);
    return ptr;
}

// Read operations don't modify state
void inspect_memory() {
    pthread_rwlock_rdlock(&alloc_lock);
    // Can safely read memory metadata
    pthread_rwlock_unlock(&alloc_lock);
}
```

### Approach 3: Per-Thread Allocators

```c
#define MAX_THREADS 16

typedef struct {
    pthread_t thread_id;
    char memory[THREAD_MEMORY_SIZE];
    struct block *freeList;
} thread_allocator_t;

thread_allocator_t thread_allocators[MAX_THREADS];
int num_threads = 0;

thread_allocator_t* get_thread_allocator() {
    pthread_t self = pthread_self();
    
    for (int i = 0; i < num_threads; i++) {
        if (thread_allocators[i].thread_id == self) {
            return &thread_allocators[i];
        }
    }
    
    // Create new allocator for this thread
    if (num_threads < MAX_THREADS) {
        thread_allocators[num_threads].thread_id = self;
        return &thread_allocators[num_threads++];
    }
    return NULL;
}

void* MyMalloc_PerThread(size_t size) {
    thread_allocator_t *alloc = get_thread_allocator();
    if (!alloc) return NULL;
    
    return MyMalloc_WithAllocator(alloc, size);
}
```

## 2. Memory Protection Mechanisms

### Approach 1: Memory Canaries

```c
#define CANARY_VALUE 0xDEADBEEF

typedef struct {
    uint32_t canary_top;
    size_t size;
    int free;
    struct block *next;
    uint32_t canary_bottom;
} protected_block_t;

void* MyMalloc_WithCanaries(size_t size) {
    struct block *block = allocate_block(size);
    if (!block) return NULL;
    
    // Place canaries
    uint32_t *top = (uint32_t *)block;
    *top = CANARY_VALUE;
    
    uint32_t *bottom = (uint32_t *)((char *)block + sizeof(block) + size);
    *bottom = CANARY_VALUE;
    
    return (void *)(block + 1);
}

void verify_block(void *ptr) {
    protected_block_t *block = (protected_block_t *)ptr - 1;
    
    if (block->canary_top != CANARY_VALUE || 
        block->canary_bottom != CANARY_VALUE) {
        fprintf(stderr, "Memory corruption detected!\n");
        exit(1);
    }
}
```

### Approach 2: Guard Pages

```c
#include <sys/mman.h>

void* MyMalloc_WithGuardPages(size_t size) {
    // Allocate with guard pages on both sides
    size_t page_size = getpagesize();
    size_t total_size = page_size + size + page_size;
    
    void *mem = mmap(NULL, total_size, PROT_READ | PROT_WRITE,
                     MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    
    if (mem == MAP_FAILED) return NULL;
    
    // Disable read/write on guard pages
    mprotect(mem, page_size, PROT_NONE);  // Top guard page
    mprotect((char *)mem + page_size + size, page_size, PROT_NONE);  // Bottom guard page
    
    return (char *)mem + page_size;
}
```

## 3. Hardware MMU (Memory Management Unit) Integration

### Approach 1: Virtual Address Space Management

```c
#include <sys/mman.h>

typedef struct {
    void *virtual_base;
    void *physical_base;
    size_t size;
    uint32_t permissions;
} memory_region_t;

#define NUM_REGIONS 32
memory_region_t regions[NUM_REGIONS];

void setup_mmu_region(void *virtual, void *physical, size_t size) {
    // On real hardware, this would communicate with MMU
    // For Linux, mmap handles virtual-to-physical mapping
    
    void *mapped = mmap(virtual, size, 
                        PROT_READ | PROT_WRITE,
                        MAP_FIXED | MAP_PRIVATE | MAP_ANONYMOUS,
                        -1, 0);
    
    if (mapped == MAP_FAILED) {
        perror("MMU mapping failed");
        return;
    }
}

void setup_page_tables() {
    // On embedded systems with real MMU:
    // - Set up page table entries
    // - Configure TLB (Translation Lookaside Buffer)
    // - Handle page faults
    
    // Example for ARM architecture:
    // extern void setup_arm_mmu();
    // setup_arm_mmu();
}
```

### Approach 2: Memory Protection Attributes

```c
#define PROT_EXEC_NEVER    0x01  // XN bit
#define PROT_PRIVILEGED    0x02  // Privileged access only
#define PROT_SHAREABILITY  0x04  // Shareable between processors

typedef struct {
    size_t size;
    uint32_t attributes;
    struct block *next;
} mmu_protected_block_t;

void set_memory_attributes(void *ptr, uint32_t attributes) {
    // On real ARM hardware:
    // 1. Get the page table entry
    // 2. Set AP bits (access permissions)
    // 3. Set XN bit (execute never)
    // 4. Flush TLB
    
    // Example stub for embedded systems
    mmu_protected_block_t *block = (mmu_protected_block_t *)ptr - 1;
    block->attributes = attributes;
}
```

## 4. Architecture-Specific Alignment (32-bit vs 64-bit)

### Approach 1: Platform Detection and Alignment

```c
#include <stdint.h>
#include <limits.h>

#if defined(__LP64__) || defined(_WIN64)
    #define ARCH_64BIT 1
    #define POINTER_SIZE 8
    #define DEFAULT_ALIGNMENT 16
#else
    #define ARCH_32BIT 1
    #define POINTER_SIZE 4
    #define DEFAULT_ALIGNMENT 8
#endif

#define ALIGN(x, align) (((x) + (align) - 1) & ~((align) - 1))

typedef struct {
    size_t size;
    int free;
    struct block *next;
    
    // Padding to ensure alignment
    #if POINTER_SIZE == 4
        uint32_t padding;
    #endif
} aligned_block_t;

void* MyMalloc_Aligned(size_t size) {
    size_t aligned_size = ALIGN(size, DEFAULT_ALIGNMENT);
    
    struct block *block = find_free_block(aligned_size);
    if (!block) return NULL;
    
    // Ensure returned pointer is aligned
    void *ptr = (void *)(block + 1);
    assert(((uintptr_t)ptr % DEFAULT_ALIGNMENT) == 0);
    
    return ptr;
}
```

### Approach 2: Cache Line Alignment

```c
#define CACHE_LINE_SIZE 64  // Common on modern processors

void* MyMalloc_CacheAligned(size_t size) {
    // Align allocations to cache line boundaries
    size_t aligned_size = ALIGN(size, CACHE_LINE_SIZE);
    
    struct block *block = find_free_block(aligned_size);
    if (!block) return NULL;
    
    // Verify cache line alignment
    void *ptr = (void *)(block + 1);
    assert(((uintptr_t)ptr % CACHE_LINE_SIZE) == 0);
    
    return ptr;
}
```

### Approach 3: NUMA-Aware Allocation

```c
#ifdef __NUMA__
#include <numa.h>

void* MyMalloc_NUMA(size_t size, int numa_node) {
    // Allocate memory on specific NUMA node
    struct bitmask *mask = numa_allocate_nodemask();
    numa_bitmask_setbit(mask, numa_node);
    
    void *ptr = numa_alloc_onnode(size, numa_node);
    numa_free_nodemask(mask);
    
    return ptr;
}
#endif
```

## 5. Page Size and Hardware Considerations

```c
#include <unistd.h>

size_t get_system_page_size() {
    return sysconf(_SC_PAGESIZE);
}

void* MyMalloc_PageAligned(size_t size) {
    size_t page_size = get_system_page_size();
    size_t aligned_size = ALIGN(size, page_size);
    
    void *ptr = mmap(NULL, aligned_size,
                     PROT_READ | PROT_WRITE,
                     MAP_PRIVATE | MAP_ANONYMOUS,
                     -1, 0);
    
    return (ptr == MAP_FAILED) ? NULL : ptr;
}
```

## 6. Memory Barriers and Ordering

For systems with multiple cores/processors:

```c
#include <stdatomic.h>

typedef struct {
    size_t size;
    int free;
    struct block *next;
    atomic_int version;  // For coherency checking
} coherent_block_t;

void* MyMalloc_Coherent(size_t size) {
    coherent_block_t *block = find_free_block(size);
    if (!block) return NULL;
    
    // Ensure all writes are visible to other cores
    atomic_thread_fence(memory_order_release);
    
    block->free = 0;
    
    // Memory barrier to ensure consistency
    atomic_thread_fence(memory_order_release);
    
    return (void *)(block + 1);
}
```

## Summary of System-Level Considerations

| Aspect | Implementation | Priority |
|--------|---|----------|
| Thread Safety | Mutex/RW-lock/Per-thread | Critical |
| Memory Protection | Canaries/Guard Pages/MMU | High |
| Architecture Support | Alignment/NUMA/Page size | High |
| Performance | Cache alignment/Memory barriers | Medium |
| Debugging | Address Sanitizer/Valgrind | Medium |

These implementations would make the allocator suitable for production embedded systems with multiple processors, memory protection requirements, and architectural constraints.