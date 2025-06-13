#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 10

// Circular buffer structure
typedef struct {
    int buffer[BUFFER_SIZE];
    int head;
    int tail;
} CircularBuffer;

CircularBuffer cb;
sem_t empty;
sem_t full;
pthread_mutex_t mutex;

void init_buffer() {
    cb.head = 0;
    cb.tail = 0;
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);
}

void write_buffer(int value) {
    sem_wait(&empty);
    pthread_mutex_lock(&mutex);

    cb.buffer[cb.tail] = value;
    cb.tail = (cb.tail + 1) % BUFFER_SIZE;

    pthread_mutex_unlock(&mutex);
    sem_post(&full);
}

int read_buffer() {
    sem_wait(&full);
    pthread_mutex_lock(&mutex);

    int value = cb.buffer[cb.head];
    cb.head = (cb.head + 1) % BUFFER_SIZE;

    pthread_mutex_unlock(&mutex);
    sem_post(&empty);

    return value;
}

void* producer(void* arg) {
    for (int i = 0; i < 20; i++) {
        printf("Producing: %d\n", i);
        write_buffer(i);
    }
    return NULL;
}

void* consumer(void* arg) {
    for (int i = 0; i < 20; i++) {
        int value = read_buffer();
        printf("Consuming: %d\n", value);
    }
    return NULL;
}

int main() {
    init_buffer();

    pthread_t prod_thread, cons_thread;

    pthread_create(&prod_thread, NULL, producer, NULL);
    pthread_create(&cons_thread, NULL, consumer, NULL);

    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}