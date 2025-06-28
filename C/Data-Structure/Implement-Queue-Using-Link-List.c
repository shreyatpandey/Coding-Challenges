#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue structure with front and rear pointers
typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize a queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (!queue) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// Function to check if queue is empty
bool isEmpty(Queue* queue) {
    return queue->front == NULL;
}

// Function to get the size of the queue
int getSize(Queue* queue) {
    return queue->size;
}

// Function to enqueue (add element to rear of queue)
void enqueue(Queue* queue, int data) {
    Node* newNode = createNode(data);
    
    // If queue is empty, both front and rear point to new node
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        // Add new node to rear and update rear pointer
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    
    queue->size++;
    printf("Enqueued: %d\n", data);
}

// Function to dequeue (remove element from front of queue)
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    }
    
    Node* temp = queue->front;
    int data = temp->data;
    
    // Move front pointer to next node
    queue->front = queue->front->next;
    
    // If queue becomes empty, reset rear to NULL
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    
    free(temp);
    queue->size--;
    printf("Dequeued: %d\n", data);
    return data;
}

// Function to peek (view front element without removing)
int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! Nothing to peek.\n");
        return -1;
    }
    return queue->front->data;
}

// Function to display all elements in the queue
void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    
    printf("Queue elements (front to rear): ");
    Node* current = queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free all memory allocated for the queue
void destroyQueue(Queue* queue) {
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
    free(queue);
    printf("Queue destroyed and memory freed.\n");
}

// Main function to demonstrate queue operations
int main() {
    Queue* queue = createQueue();
    int choice, value;
    
    printf("Queue Implementation using Linked List\n");
    printf("======================================\n");
    
    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Check if empty\n");
        printf("6. Get size\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
                
            case 2:
                dequeue(queue);
                break;
                
            case 3:
                value = peek(queue);
                if (value != -1) {
                    printf("Front element: %d\n", value);
                }
                break;
                
            case 4:
                display(queue);
                break;
                
            case 5:
                if (isEmpty(queue)) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
                
            case 6:
                printf("Queue size: %d\n", getSize(queue));
                break;
                
            case 7:
                destroyQueue(queue);
                printf("Exiting program.\n");
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}