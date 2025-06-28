#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * Max Heap Implementation in C
 * 
 * A heap is a complete binary tree that satisfies the heap property:
 * In a max heap, for any given node C, if P is a parent node of C, 
 * then the key of P is greater than or equal to the key of C.
 */

typedef struct {
    int* array;     // Array to store heap elements
    int capacity;   // Maximum possible size of the heap
    int size;       // Current number of elements in the heap
} MaxHeap;

/**
 * Create a new max heap with the given capacity
 */
MaxHeap* createHeap(int capacity) {
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    if (!heap) return NULL;
    
    heap->capacity = capacity;
    heap->size = 0;
    heap->array = (int*)malloc(capacity * sizeof(int));
    
    if (!heap->array) {
        free(heap);
        return NULL;
    }
    
    return heap;
}

/**
 * Get the parent index of the given index
 */
int parent(int i) {
    return (i - 1) / 2;
}

/**
 * Get the left child index of the given index
 */
int leftChild(int i) {
    return (2 * i + 1);
}

/**
 * Get the right child index of the given index
 */
int rightChild(int i) {
    return (2 * i + 2);
}

/**
 * Swap two elements in the heap array
 */
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * Heapify a subtree with the root at given index
 * This is a key operation to maintain the heap property after modifications
 */
void heapify(MaxHeap* heap, int i) {
    int left = leftChild(i);
    int right = rightChild(i);
    int largest = i;
    
    // Check if left child is larger than root
    if (left < heap->size && heap->array[left] > heap->array[largest])
        largest = left;
    
    // Check if right child is larger than current largest
    if (right < heap->size && heap->array[right] > heap->array[largest])
        largest = right;
    
    // If largest is not root, swap and continue heapifying
    if (largest != i) {
        swap(&heap->array[i], &heap->array[largest]);
        heapify(heap, largest);
    }
}

/**
 * Insert a new key to the heap
 */
void insert(MaxHeap* heap, int key) {
    // Check if heap is full
    if (heap->size == heap->capacity) {
        printf("Heap overflow! Cannot insert more elements.\n");
        return;
    }
    
    // Insert the new key at the end
    int i = heap->size;
    heap->array[i] = key;
    heap->size++;
    
    // Fix the max heap property if it is violated
    // Move the new key up as needed
    while (i != 0 && heap->array[parent(i)] < heap->array[i]) {
        swap(&heap->array[i], &heap->array[parent(i)]);
        i = parent(i);
    }
}

/**
 * Extract the maximum element from the heap
 */
int extractMax(MaxHeap* heap) {
    if (heap->size <= 0)
        return INT_MIN;
    
    if (heap->size == 1) {
        heap->size--;
        return heap->array[0];
    }
    
    // Store the maximum value and remove it from heap
    int root = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    
    // Restore the heap property
    heapify(heap, 0);
    
    return root;
}

/**
 * Get the maximum element without removing it
 */
int getMax(MaxHeap* heap) {
    if (heap->size <= 0)
        return INT_MIN;
    return heap->array[0];
}

/**
 * Delete a key at the given index
 */
void deleteKey(MaxHeap* heap, int i) {
    if (i >= heap->size) {
        printf("Invalid index for deletion.\n");
        return;
    }
    
    // Increase the key to maximum possible value and extract it
    heap->array[i] = INT_MAX;
    
    // Move this key to root
    while (i != 0 && heap->array[parent(i)] < heap->array[i]) {
        swap(&heap->array[i], &heap->array[parent(i)]);
        i = parent(i);
    }
    
    // Now extract the maximum value which will be our key
    extractMax(heap);
}

/**
 * Free memory allocated for the heap
 */
void destroyHeap(MaxHeap* heap) {
    if (heap) {
        if (heap->array)
            free(heap->array);
        free(heap);
    }
}

/**
 * Print the heap array
 */
void printHeap(MaxHeap* heap) {
    printf("Heap: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->array[i]);
    }
    printf("\n");
}

/**
 * Function to test the heap implementation
 */
int main() {
    // Create a max heap of capacity 10
    MaxHeap* heap = createHeap(10);
    
    // Insert elements
    insert(heap, 3);
    insert(heap, 10);
    insert(heap, 2);
    insert(heap, 15);
    insert(heap, 5);
    insert(heap, 4);
    insert(heap, 45);
    
    printf("Created max heap:\n");
    printHeap(heap);
    
    printf("The max element is %d\n", getMax(heap));
    
    printf("Extracting max element: %d\n", extractMax(heap));
    printf("Heap after extraction:\n");
    printHeap(heap);
    
    printf("Deleting element at index 2\n");
    deleteKey(heap, 2);
    printf("Heap after deletion:\n");
    printHeap(heap);
    
    // Clean up
    destroyHeap(heap);
    printf("Heap has been destroyed.\n");
    
    return 0;
}
