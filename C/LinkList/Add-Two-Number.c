#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

// Function to create a new node
ListNode* createNode(int val) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to add two numbers represented by linked lists
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummyHead = createNode(0);
    ListNode* current = dummyHead;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        current->next = createNode(sum % 10);
        current = current->next;
    }

    return dummyHead->next;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// Example usage
int main() {
    // Create first number: 342 (stored as 2 -> 4 -> 3)
    ListNode* l1 = createNode(2);
    l1->next = createNode(4);
    l1->next->next = createNode(3);

    // Create second number: 465 (stored as 5 -> 6 -> 4)
    ListNode* l2 = createNode(5);
    l2->next = createNode(6);
    l2->next->next = createNode(4);

    // Add the two numbers
    ListNode* result = addTwoNumbers(l1, l2);

    // Print the result: 807 (stored as 7 -> 0 -> 8)
    printList(result);

    // Free allocated memory (not shown for simplicity)

    return 0;
}