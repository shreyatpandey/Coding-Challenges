#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// Definition for singly-linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

int getDecimalValue(struct ListNode* head) {
    int result = 0;
    struct ListNode* current = head;

    // Traverse the linked list and build decimal number
    while (current != NULL) {
        // Left shift result by 1 and add current bit
        result = (result << 1) | current->val;
        /* result = result*2 + current->val;*/
        current = current->next;
    }
    return result;
}

// Helper function to create a new node
struct ListNode* newNode(int value) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = value;
    node->next = NULL;
    return node;
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

int main() {
    // Test Case 1: Binary number 1101 (decimal 13)
    struct ListNode* head1 = newNode(1);
    head1->next = newNode(1);
    head1->next->next = newNode(0);
    head1->next->next->next = newNode(1);

    printf("Test Case 1 - Binary: 1101, Decimal: %d\n", getDecimalValue(head1));

    // Test Case 2: Binary number 0 (decimal 0)
    struct ListNode* head2 = newNode(0);
    printf("Test Case 2 - Binary: 0, Decimal: %d\n", getDecimalValue(head2));

    // Test Case 3: Binary number 1 (decimal 1)
    struct ListNode* head3 = newNode(1);
    printf("Test Case 3 - Binary: 1, Decimal: %d\n", getDecimalValue(head3));

    // Free allocated memory
    freeList(head1);
    freeList(head2);
    freeList(head3);

    return 0;
}
