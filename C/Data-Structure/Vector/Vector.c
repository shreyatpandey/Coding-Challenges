#include "Vector.h"
#include <stdlib.h> // For malloc, free, realloc
#include <string.h> // For memcpy

// Initialize the vector
void vector_init(Vector *vector, size_t elem_size) {
    vector->data = NULL;
    vector->size = 0;
    vector->capacity = 0;
    vector->elem_size = elem_size;
}

// Add an element to the end of the vector
void vector_push_back(Vector *vector, const void *elem) {
    if (vector->size == vector->capacity) {
        size_t new_capacity = vector->capacity == 0 ? 1 : vector->capacity * 2;
        vector->data = realloc(vector->data, new_capacity * vector->elem_size);
        vector->capacity = new_capacity;
    }
    memcpy((char *)vector->data + vector->size * vector->elem_size, elem, vector->elem_size);
    vector->size++;
}

// Remove the last element from the vector
void vector_pop_back(Vector *vector) {
    if (vector->size > 0) {
        vector->size--;
    }
}

// Get a pointer to the element at a specific index
void *vector_get(Vector *vector, size_t index) {
    if (index >= vector->size) {
        return NULL; // Out of bounds
    }
    return (char *)vector->data + index * vector->elem_size;
}

// Free the memory used by the vector
void vector_free(Vector *vector) {
    free(vector->data);
    vector->data = NULL;
    vector->size = 0;
    vector->capacity = 0;
}
