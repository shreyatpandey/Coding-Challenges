# Slab Allocation vs Traditional Malloc: Fragmentation Comparison

## How Slab Allocation Minimizes Fragmentation

### Problems with the Original Implementation

The original malloc implementation suffers from several fragmentation issues:

1. **External Fragmentation**: When objects of different sizes are allocated and freed, it creates gaps that may be too small for future allocations.

2. **Poor Locality**: Objects of the same type/size aren't grouped together, leading to poor cache performance.

3. **Split Overhead**: Every allocation requires metadata (struct block), creating significant overhead for small objects.

4. **Coalescing Complexity**: Merging free blocks is complex and may not always be effective.

### Slab Allocation Advantages

The slab allocator addresses these issues through:

## 1. **Pre-defined Size Classes**
```c
slab_class_t slab_classes[NUM_SLAB_CLASSES] = {
    {16, OBJECTS_PER_SLAB, 0, NULL},    // Small objects
    {32, OBJECTS_PER_SLAB, 0, NULL},    
    {64, OBJECTS_PER_SLAB, 0, NULL},    
    {128, OBJECTS_PER_SLAB, 0, NULL},   
    {256, OBJECTS_PER_SLAB, 0, NULL},   // Medium objects
    {512, OBJECTS_PER_SLAB/2, 0, NULL}, 
    {1024, OBJECTS_PER_SLAB/4, 0, NULL}, // Large objects
    {2048, OBJECTS_PER_SLAB/8, 0, NULL}  // Very large objects
};
```

**Benefits:**
- Requests for 10 bytes and 15 bytes both use 16-byte objects
- Reduces external fragmentation by standardizing sizes
- Objects of similar sizes are grouped together

## 2. **Slab-based Organization**
```c
typedef struct slab {
    struct slab_class *class;  // Pointer to slab class
    struct slab *next;         // Next slab in the same class
    void *free_objects;        // Linked list of free objects in this slab
    int free_count;            // Number of free objects
    int total_count;           // Total objects in this slab
    char data[];               // Actual object storage
} slab_t;
```

**Benefits:**
- Objects of the same size are allocated from the same slab
- Better memory locality and cache performance
- Easier to manage and less fragmentation

## 3. **Object Reuse Strategy**
```c
void* allocate_from_slab(slab_t *slab) {
    if (slab->free_count == 0) {
        return NULL; // No free objects in this slab
    }
    
    // Get the first free object
    free_object_t *free_obj = (free_object_t*)slab->free_objects;
    slab->free_objects = free_obj->next;
    slab->free_count--;
    
    return (void*)free_obj;
}
```

**Benefits:**
- Freed objects are immediately available for reuse
- No complex coalescing needed
- Fast allocation/deallocation

## 4. **Reduced Metadata Overhead**
- Original: Each allocation needs a `struct block` (24 bytes on 64-bit systems)
- Slab: One slab header manages multiple objects (32 objects share one header)
- For small allocations, this dramatically reduces overhead

## Fragmentation Comparison Examples

### Scenario 1: Many Small Allocations

**Original Malloc:**
```
Request: 10 bytes → Allocates 34 bytes (10 + 24 header) = 140% overhead
Request: 15 bytes → Allocates 39 bytes (15 + 24 header) = 160% overhead
Request: 8 bytes  → Allocates 32 bytes (8 + 24 header)  = 300% overhead
```

**Slab Allocator:**
```
Request: 10 bytes → Uses 16-byte object = 60% overhead
Request: 15 bytes → Uses 16-byte object = 6.7% overhead  
Request: 8 bytes  → Uses 16-byte object = 100% overhead
+ One 24-byte slab header manages 32 objects = 0.75 bytes overhead per object
```

### Scenario 2: Allocation Patterns

**Original Malloc Fragmentation:**
```
Initial: [-------- 20000 bytes free --------]
Alloc 400: [USED-400][FREE-19576]
Alloc 250: [USED-400][USED-250][FREE-19326]
Alloc 4000: [USED-400][USED-250][USED-4000][FREE-15326]
Free first: [FREE-400][USED-250][USED-4000][FREE-15326]
Alloc 700: Can't fit in 400-byte gap → uses end space
Result: [FREE-400][USED-250][USED-4000][USED-700][FREE-14626]
```
**Problem**: 400-byte gap is wasted (external fragmentation)

**Slab Allocator Organization:**
```
16-byte slab: [obj1][obj2][obj3]...[obj32] - all same size
32-byte slab: [obj1][obj2][obj3]...[obj32] - all same size  
64-byte slab: [obj1][obj2][obj3]...[obj32] - all same size
```
**Benefit**: No external fragmentation within slab classes

## 5. **Memory Utilization Statistics**

The slab allocator provides detailed statistics:
```c
void print_slab_stats() {
    printf("Class %d (%zu bytes): %d slabs, %d/%d objects used (%.1f%% utilization)\n",
           i, class->object_size, slab_count, 
           total_objects - free_objects, total_objects,
           utilization_percentage);
}
```

This helps identify:
- Which size classes are most used
- Overall memory utilization
- Potential for optimization

## Key Improvements Summary

| Aspect | Original Malloc | Slab Allocator |
|--------|----------------|----------------|
| **External Fragmentation** | High - many small gaps | Low - objects grouped by size |
| **Internal Fragmentation** | Variable | Controlled by size classes |
| **Metadata Overhead** | 24 bytes per allocation | ~0.75 bytes per object |
| **Allocation Speed** | O(n) list traversal | O(1) for existing slabs |
| **Cache Performance** | Poor - scattered objects | Good - objects grouped |
| **Deallocation** | Complex merging needed | Simple - add to free list |
| **Predictability** | Unpredictable fragmentation | Predictable memory usage |

## When to Use Slab Allocation

**Best for:**
- Applications with predictable allocation patterns
- Many allocations of similar sizes  
- Performance-critical applications
- Long-running applications where fragmentation accumulates

**Consider alternatives for:**
- Applications with highly variable allocation sizes
- Short-running programs
- When memory usage is more important than performance

The slab allocator trades some internal fragmentation (objects slightly larger than requested) for dramatically reduced external fragmentation and better performance characteristics.