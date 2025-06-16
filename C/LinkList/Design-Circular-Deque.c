#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *data;
    int front;
    int rear;
    int size;
    int capacity;
} MyCircularDeque;

MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* deque = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    deque->data = (int*)malloc(sizeof(int) * k);
    deque->front = -1;
    deque->rear = -1;
    deque->size = 0;
    deque->capacity = k;
    return deque;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (obj->size == obj->capacity) return false;
    if (obj->front == -1) {
        obj->front = obj->rear = 0;
    } else {
        obj->front = (obj->front - 1 + obj->capacity) % obj->capacity;
    }
    obj->data[obj->front] = value;
    obj->size++;
    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (obj->size == obj->capacity) return false;
    if (obj->rear == -1) {
        obj->front = obj->rear = 0;
    } else {
        obj->rear = (obj->rear + 1) % obj->capacity;
    }
    obj->data[obj->rear] = value;
    obj->size++;
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (obj->size == 0) return false;
    if (obj->front == obj->rear) {
        obj->front = obj->rear = -1;
    } else {
        obj->front = (obj->front + 1) % obj->capacity;
    }
    obj->size--;
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (obj->size == 0) return false;
    if (obj->front == obj->rear) {
        obj->front = obj->rear = -1;
    } else {
        obj->rear = (obj->rear - 1 + obj->capacity) % obj->capacity;
    }
    obj->size--;
    return true;
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    if (obj->size == 0) return -1;
    return obj->data[obj->front];
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    if (obj->size == 0) return -1;
    return obj->data[obj->rear];
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return obj->size == 0;
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return obj->size == obj->capacity;
}

void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj->data);
    free(obj);
}

void testCircularDeque() {
    MyCircularDeque* deque = myCircularDequeCreate(3);

    printf("Insert Last 1: %d\n", myCircularDequeInsertLast(deque, 1));
    printf("Insert Last 2: %d\n", myCircularDequeInsertLast(deque, 2));
    printf("Insert Front 3: %d\n", myCircularDequeInsertFront(deque, 3));
    printf("Insert Front 4 (should fail): %d\n", myCircularDequeInsertFront(deque, 4));

    printf("Get Rear: %d\n", myCircularDequeGetRear(deque));
    printf("Is Full: %d\n", myCircularDequeIsFull(deque));

    printf("Delete Last: %d\n", myCircularDequeDeleteLast(deque));
    printf("Insert Front 4: %d\n", myCircularDequeInsertFront(deque, 4));

    printf("Get Front: %d\n", myCircularDequeGetFront(deque));

    myCircularDequeFree(deque);
}

int main() {
    testCircularDeque();
    return 0;
}
// This code implements a circular deque (double-ended queue) in C.
// It provides functions to create the deque, insert elements at both ends, delete elements from both ends,
// get the front and rear elements, check if the deque is empty or full, and free the allocated memory.
// The test function demonstrates the usage of the circular deque with various operations.
// The code is designed to be compiled with a C compiler and can be tested by running the main function.
// The output will show the results of the operations performed on the circular deque.

