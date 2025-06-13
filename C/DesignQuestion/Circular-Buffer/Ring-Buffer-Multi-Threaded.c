#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>

typedef struct ring_buffer ring_buffer_t;
struct ring_buffer {
    size_t size;
    size_t head;
    size_t tail;
    char *buffer; // char as the data type for simplicity
    pthread_mutex_t mutex;
};

void init(ring_buffer_t *rb, size_t size) {
    rb->size = size;
    rb->head = 0;
    rb->tail = 0;
    rb->buffer= (char *)malloc(size * sizeof(char));
}

void insert(ring_buffer_t *rb, char data) {
    pthread_mutex_lock(&rb->mutex);
    if ((rb->head + 1) % rb->size == rb->tail) {
        fprintf(stderr, "Buffer overflow\n");
        pthread_mutex_unlock(&rb->mutex);
        return;
    }
    rb->buffer[rb->head] = data;
    rb->head = (rb->head + 1) % rb->size;
    pthread_mutex_unlock(&rb->mutex);
}

void delete(ring_buffer_t *rb) {
    pthread_mutex_lock(&rb->mutex);
    if (rb->head == rb->tail) {
        fprintf(stderr, "Buffer underflow\n");
        pthread_mutex_unlock(&rb->mutex);
        return;
    }
    rb->tail = (rb->tail + 1) % rb->size;
    pthread_mutex_unlock(&rb->mutex);
}
/*
    Print the contents of the ring buffer.
*/
void print(ring_buffer_t *rb) {
    printf("Ring Buffer Contents:\n");
    pthread_mutex_lock(&rb->mutex);
    printf("Head: %zu, Tail: %zu\n", rb->head, rb->tail);
    printf("Buffer: %s", rb->buffer);
    pthread_mutex_unlock(&rb->mutex);
    printf("\n");
}

int main() {
    size_t size = 10; // Example size
    struct ring_buffer *rb = (ring_buffer_t *)malloc(sizeof(ring_buffer_t));
    if (!rb) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    init(rb, size);

    // Example usage
    insert(rb, 'A');
    insert(rb, 'B');
    insert(rb, 'C');
    print(rb);
    delete(rb);
    print(rb);
    
    // free resources
    if (rb) {
        free(rb->buffer);
        pthread_mutex_destroy(&rb->mutex);
        free(rb);
    }
    return EXIT_SUCCESS;
}