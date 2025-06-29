#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h> // For size_t

// Define the vector structure
typedef struct {
    void *data;       // Pointer to the data array
    size_t size;      // Number of elements currently in the vector
    size_t capacity;  // Total capacity of the vector
    size_t elem_size; // Size of each element in bytes
} Vector;

// Function declarations
void vector_init(Vector *vector, size_t elem_size);
void vector_push_back(Vector *vector, const void *elem);
void vector_pop_back(Vector *vector);
void *vector_get(Vector *vector, size_t index);
void vector_free(Vector *vector);

#endif // VECTOR_H
