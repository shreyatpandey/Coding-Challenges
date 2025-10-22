#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list node
struct ListNode {
    int val;
    struct ListNode* next;
};

// Helper function to create a new node
struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

// Helper function to print the linked list
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

// Helper function to free the linked list
void freeList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        struct ListNode* temp = current;
        current = current->next;
        free(temp);
    }
}

// Iterative approach to reverse a linked list
struct ListNode* reverseListIterative(struct ListNode* head) {
    struct ListNode *prev = NULL, *current = head, *next = NULL;
    
    while (current != NULL) {
        // Store next
        next = current->next;
        // Reverse current node's pointer
        current->next = prev;
        // Move pointers one position ahead
        prev = current;
        current = next;
    }
    
    return prev;
}

// Recursive approach to reverse a linked list
struct ListNode* reverseListRecursive(struct ListNode* head) {
    // Base cases: empty list or single node
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    // Recursive call to reverse rest of the list
    struct ListNode* rest = reverseListRecursive(head->next);
    
    // Set head node's next's next to point to head
    head->next->next = head;
    
    // Set head's next to NULL to avoid cycles
    head->next = NULL;
    
    return rest;
}

// Test cases
void runTests() {
    printf("Running test cases...\n\n");
    
    // Test Case 1: Empty list
    printf("Test Case 1: Empty list\n");
    struct ListNode* test1 = NULL;
    printf("Original list: ");
    printList(test1);
    test1 = reverseListIterative(test1);
    printf("After iterative reverse: ");
    printList(test1);
    
    // Test Case 2: Single node
    printf("\nTest Case 2: Single node\n");
    struct ListNode* test2 = createNode(1);
    printf("Original list: ");
    printList(test2);
    test2 = reverseListIterative(test2);
    printf("After iterative reverse: ");
    printList(test2);
    freeList(test2);
    
    // Test Case 3: Multiple nodes (Iterative)
    printf("\nTest Case 3: Multiple nodes (Iterative)\n");
    struct ListNode* test3 = createNode(1);
    test3->next = createNode(2);
    test3->next->next = createNode(3);
    test3->next->next->next = createNode(4);
    printf("Original list: ");
    printList(test3);
    test3 = reverseListIterative(test3);
    printf("After iterative reverse: ");
    printList(test3);
    freeList(test3);
    
    // Test Case 4: Multiple nodes (Recursive)
    printf("\nTest Case 4: Multiple nodes (Recursive)\n");
    struct ListNode* test4 = createNode(1);
    test4->next = createNode(2);
    test4->next->next = createNode(3);
    test4->next->next->next = createNode(4);
    printf("Original list: ");
    printList(test4);
    test4 = reverseListRecursive(test4);
    printf("After recursive reverse: ");
    printList(test4);
    freeList(test4);
}

int main() {
    runTests();
    return 0;
}
