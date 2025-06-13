// gc_mark_sweep.c
// Minimal mark-and-sweep garbage collector demo in C
// For educational purposes only
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define HEAP_SIZE 1024

// Object structure
typedef struct Object {
    bool marked;
    struct Object **references;
    int ref_count;
    int value; // Example payload
} Object;

// Heap
Object *heap[HEAP_SIZE];
int heap_count = 0;

// Allocate a new object
Object* gc_alloc(int value) {
    if (heap_count >= HEAP_SIZE) {
        printf("Heap full!\n");
        exit(1);
    }
    Object *obj = (Object*)malloc(sizeof(Object));
    obj->marked = false;
    obj->references = NULL;
    obj->ref_count = 0;
    obj->value = value;
    heap[heap_count++] = obj;
    return obj;
}

// Add a reference from one object to another
void gc_add_reference(Object *from, Object *to) {
    from->references = realloc(from->references, sizeof(Object*) * (from->ref_count + 1));
    from->references[from->ref_count++] = to;
}

// Mark phase
void gc_mark(Object *obj) {
    if (!obj || obj->marked) return;
    obj->marked = true;
    for (int i = 0; i < obj->ref_count; i++) {
        gc_mark(obj->references[i]);
    }
}

// Sweep phase
void gc_sweep() {
    for (int i = 0; i < heap_count; i++) {
        if (!heap[i]->marked) {
            free(heap[i]->references);
            free(heap[i]);
            // Remove from heap
            heap[i] = heap[--heap_count];
            i--; // Check the swapped-in object
        } else {
            heap[i]->marked = false; // Unmark for next GC
        }
    }
}

// Run garbage collection
void gc_collect(Object **roots, int root_count) {
    // Mark
    for (int i = 0; i < root_count; i++) {
        gc_mark(roots[i]);
    }
    // Sweep
    gc_sweep();
}

// Demo usage
int main() {
    Object *root1 = gc_alloc(10);
    Object *root2 = gc_alloc(20);
    Object *child1 = gc_alloc(30);
    Object *child2 = gc_alloc(40);
    gc_add_reference(root1, child1);
    gc_add_reference(child1, child2);
    Object *roots[] = {root1, root2};

    printf("Heap before GC: %d objects\n", heap_count);
    // Remove root2 reference
    roots[1] = NULL;
    gc_collect(roots, 2);
    printf("Heap after GC: %d objects\n", heap_count);

    // Clean up remaining objects
    roots[0] = NULL;
    gc_collect(roots, 2);
    printf("Heap after final GC: %d objects\n", heap_count);
    return 0;
}
