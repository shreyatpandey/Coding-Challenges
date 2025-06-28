#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

/**
 * Thread-safe stack implementation using mutexes
 * This implementation ensures safe concurrent access from multiple threads
 */

// Define the maximum size of our stack
#define MAX_STACK_SIZE 100

// Stack structure definition
typedef struct {
    int data[MAX_STACK_SIZE];  // Array to store stack elements
    int top;                   // Index of top element
    pthread_mutex_t mutex;     // Mutex for thread synchronization
} ThreadSafeStack;

/**
 * Initialize a new stack
 * Returns a pointer to the newly created stack
 */
ThreadSafeStack* createStack() {
    ThreadSafeStack* stack = (ThreadSafeStack*)malloc(sizeof(ThreadSafeStack));
    if (stack == NULL) {
        fprintf(stderr, "Memory allocation failed for stack\n");
        return NULL;
    }
    
    stack->top = -1;  // Initialize top to -1 (empty stack)
    
    // Initialize the mutex
    if (pthread_mutex_init(&(stack->mutex), NULL) != 0) {
        fprintf(stderr, "Mutex initialization failed\n");
        free(stack);
        return NULL;
    }
    
    return stack;
}

/**
 * Check if the stack is empty
 * Returns true if empty, false otherwise
 */
bool isEmpty(ThreadSafeStack* stack) {
    pthread_mutex_lock(&(stack->mutex));
    bool result = (stack->top == -1);
    pthread_mutex_unlock(&(stack->mutex));
    return result;
}

/**
 * Check if the stack is full
 * Returns true if full, false otherwise
 */
bool isFull(ThreadSafeStack* stack) {
    pthread_mutex_lock(&(stack->mutex));
    bool result = (stack->top == MAX_STACK_SIZE - 1);
    pthread_mutex_unlock(&(stack->mutex));
    return result;
}

/**
 * Push an item onto the stack
 * Returns true if successful, false if stack is full
 */
bool push(ThreadSafeStack* stack, int item) {
    pthread_mutex_lock(&(stack->mutex));
    
    // Check if stack is full
    if (stack->top >= MAX_STACK_SIZE - 1) {
        pthread_mutex_unlock(&(stack->mutex));
        return false;  // Stack overflow
    }
    
    // Add element to stack
    stack->data[++(stack->top)] = item;
    
    pthread_mutex_unlock(&(stack->mutex));
    return true;
}

/**
 * Pop an item from the stack
 * If stack is empty, *success is set to false
 */
int pop(ThreadSafeStack* stack, bool* success) {
    pthread_mutex_lock(&(stack->mutex));
    
    // Check if stack is empty
    if (stack->top == -1) {
        *success = false;
        pthread_mutex_unlock(&(stack->mutex));
        return -1;  // Return a default value
    }
    
    // Get top element and decrement top
    int item = stack->data[(stack->top)--];
    *success = true;
    
    pthread_mutex_unlock(&(stack->mutex));
    return item;
}

/**
 * Peek at the top item without removing it
 * If stack is empty, *success is set to false
 */
int peek(ThreadSafeStack* stack, bool* success) {
    pthread_mutex_lock(&(stack->mutex));
    
    // Check if stack is empty
    if (stack->top == -1) {
        *success = false;
        pthread_mutex_unlock(&(stack->mutex));
        return -1;  // Return a default value
    }
    
    // Get top element without changing top
    int item = stack->data[stack->top];
    *success = true;
    
    pthread_mutex_unlock(&(stack->mutex));
    return item;
}

/**
 * Destroy the stack and free resources
 */
void destroyStack(ThreadSafeStack* stack) {
    if (stack != NULL) {
        pthread_mutex_destroy(&(stack->mutex));
        free(stack);
    }
}

/**
 * Example thread function that pushes items to the stack
 */
void* producer(void* arg) {
    ThreadSafeStack* stack = (ThreadSafeStack*)arg;
    
    for (int i = 0; i < 10; i++) {
        if (push(stack, i)) {
            printf("Thread %lu: Pushed %d to stack\n", pthread_self(), i);
        } else {
            printf("Thread %lu: Stack full, couldn't push %d\n", pthread_self(), i);
        }
        
        // Sleep a bit to allow other threads to run
        usleep(rand() % 100000);
    }
    
    return NULL;
}

/**
 * Example thread function that pops items from the stack
 */
void* consumer(void* arg) {
    ThreadSafeStack* stack = (ThreadSafeStack*)arg;
    bool success;
    
    for (int i = 0; i < 10; i++) {
        int item = pop(stack, &success);
        
        if (success) {
            printf("Thread %lu: Popped %d from stack\n", pthread_self(), item);
        } else {
            printf("Thread %lu: Stack empty, couldn't pop\n", pthread_self());
        }
        
        // Sleep a bit to allow other threads to run
        usleep(rand() % 200000);
    }
    
    return NULL;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Create stack
    ThreadSafeStack* stack = createStack();
    if (stack == NULL) {
        return 1;
    }
    
    // Create producer and consumer threads
    pthread_t producer1, producer2, consumer1;
    
    pthread_create(&producer1, NULL, producer, stack);
    pthread_create(&producer2, NULL, producer, stack);
    pthread_create(&consumer1, NULL, consumer, stack);
    
    // Wait for threads to complete
    pthread_join(producer1, NULL);
    pthread_join(producer2, NULL);
    pthread_join(consumer1, NULL);
    
    // Clean up
    destroyStack(stack);
    
    return 0;
}
