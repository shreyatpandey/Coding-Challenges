#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Array-based stack implementation in C
 * This demonstrates a simple fixed-size array implementation of a stack
 */

// Define the maximum size of our stack
#define MAX_STACK_SIZE 100

// Stack structure definition
typedef struct {
    int data[MAX_STACK_SIZE];  // Array to store stack elements
    int top;                   // Index of top element
} ArrayStack;

/**
 * Initialize a new stack
 * Returns a pointer to the newly created stack
 */
ArrayStack* createStack() {
    ArrayStack* stack = (ArrayStack*)malloc(sizeof(ArrayStack));
    if (stack == NULL) {
        fprintf(stderr, "Memory allocation failed for stack\n");
        return NULL;
    }
    
    stack->top = -1;  // Initialize top to -1 (empty stack)
    return stack;
}

/**
 * Check if the stack is empty
 * Returns true if empty, false otherwise
 */
bool isEmpty(ArrayStack* stack) {
    return (stack->top == -1);
}

/**
 * Check if the stack is full
 * Returns true if full, false otherwise
 */
bool isFull(ArrayStack* stack) {
    return (stack->top == MAX_STACK_SIZE - 1);
}

/**
 * Get the current size of the stack
 * Returns the number of elements in the stack
 */
int size(ArrayStack* stack) {
    return stack->top + 1;
}

/**
 * Push an item onto the stack
 * Returns true if successful, false if stack is full
 */
bool push(ArrayStack* stack, int item) {
    // Check if stack is full
    if (isFull(stack)) {
        return false;  // Stack overflow
    }
    
    // Add element to stack
    stack->data[++(stack->top)] = item;
    return true;
}

/**
 * Pop an item from the stack
 * If stack is empty, *success is set to false
 */
int pop(ArrayStack* stack, bool* success) {
    // Check if stack is empty
    if (isEmpty(stack)) {
        *success = false;
        return -1;  // Return a default value
    }
    
    // Get top element and decrement top
    *success = true;
    return stack->data[(stack->top)--];
}

/**
 * Peek at the top item without removing it
 * If stack is empty, *success is set to false
 */
int peek(ArrayStack* stack, bool* success) {
    // Check if stack is empty
    if (isEmpty(stack)) {
        *success = false;
        return -1;  // Return a default value
    }
    
    // Get top element without changing top
    *success = true;
    return stack->data[stack->top];
}

/**
 * Clear all elements from the stack
 */
void clear(ArrayStack* stack) {
    stack->top = -1;
}

/**
 * Destroy the stack and free resources
 */
void destroyStack(ArrayStack* stack) {
    free(stack);
}

/**
 * Print the contents of the stack (from top to bottom)
 */
void printStack(ArrayStack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    
    printf("Stack contents (top to bottom):\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->data[i]);
    }
}

int main() {
    // Create stack
    ArrayStack* stack = createStack();
    if (stack == NULL) {
        return 1;
    }
    
    // Demonstrate stack operations
    printf("Pushing elements: 10, 20, 30, 40, 50\n");
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);
    
    // Print stack
    printStack(stack);
    
    // Peek at top element
    bool success;
    int topElement = peek(stack, &success);
    if (success) {
        printf("\nTop element (peek): %d\n", topElement);
    }
    
    // Pop elements from stack
    printf("\nPopping elements:\n");
    while (!isEmpty(stack)) {
        int item = pop(stack, &success);
        if (success) {
            printf("Popped: %d\n", item);
        }
    }
    
    // Check if stack is empty
    printf("\nIs stack empty? %s\n", isEmpty(stack) ? "Yes" : "No");
    
    // Push more elements
    printf("\nPushing elements: 100, 200\n");
    push(stack, 100);
    push(stack, 200);
    
    // Print stack
    printStack(stack);
    
    // Clear the stack
    printf("\nClearing stack...\n");
    clear(stack);
    printf("Is stack empty? %s\n", isEmpty(stack) ? "Yes" : "No");
    
    // Clean up
    destroyStack(stack);
    
    return 0;
}
