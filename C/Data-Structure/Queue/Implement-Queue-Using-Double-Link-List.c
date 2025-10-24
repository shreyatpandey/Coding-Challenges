#include <stdio.h>
#include <stdlib.h>

// Structure for a node in doubly linked list
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Structure for Queue
typedef struct Queue {
    Node* front;    // For dequeue operation
    Node* rear;     // For enqueue operation
    int size;       // Track size of queue
} Queue;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to create an empty queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// Function to check if queue is empty
int isEmpty(Queue* queue) {
    return (queue->front == NULL);
}

// Function to enqueue (insert) element
void enqueue(Queue* queue, int data) {
    Node* newNode = createNode(data);
    
    // If queue is empty
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        // Add node at the rear
        newNode->prev = queue->rear;
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->size++;
    printf("Enqueued: %d\n", data);
}

// Function to dequeue (remove) element
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    
    Node* temp = queue->front;
    int data = temp->data;
    
    // If only one node
    if (queue->front == queue->rear) {
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        queue->front = queue->front->next;
        queue->front->prev = NULL;
    }
    
    free(temp);
    queue->size--;
    return data;
}

// Function to get front element without removing it
int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->front->data;
}

// Function to get queue size
int getSize(Queue* queue) {
    return queue->size;
}

// Function to free queue memory
void freeQueue(Queue* queue) {
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
    free(queue);
}

// Main function to test the implementation
int main() {
    Queue* queue = createQueue();
    
    // Test enqueue operations
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    
    printf("Queue size: %d\n", getSize(queue));
    printf("Front element: %d\n", peek(queue));
    
    // Test dequeue operations
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));
    
    printf("Queue size after dequeue: %d\n", getSize(queue));
    printf("Front element after dequeue: %d\n", peek(queue));
    
    // Free queue memory
    freeQueue(queue);
    return 0;
}
