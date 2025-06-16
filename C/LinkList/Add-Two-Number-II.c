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

// Helper function to find the length of a linked list
int getLength(ListNode* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

// Helper function to add two numbers recursively
ListNode* addHelper(ListNode* l1, ListNode* l2, int* carry) {
    if (l1 == NULL && l2 == NULL) {
        return NULL;
    }

    ListNode* nextNode = addHelper(l1->next, l2->next, carry);

    int sum = l1->val + l2->val + *carry;
    *carry = sum / 10;

    ListNode* newNode = createNode(sum % 10);
    newNode->next = nextNode;

    return newNode;
}

// Function to add two numbers represented by linked lists without reversing
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int len1 = getLength(l1);
    int len2 = getLength(l2);

    // Pad the shorter list with zeros
    while (len1 < len2) {
        ListNode* newNode = createNode(0);
        newNode->next = l1;
        l1 = newNode;
        len1++;
    }
    while (len2 < len1) {
        ListNode* newNode = createNode(0);
        newNode->next = l2;
        l2 = newNode;
        len2++;
    }

    // Add the numbers recursively
    ListNode* result = NULL;
    int carry = 0;

    result = addHelper(l1, l2, &carry);

    // If there's a carry left, add a new node at the front
    if (carry > 0) {
        ListNode* newNode = createNode(carry);
        newNode->next = result;
        result = newNode;
    }

    return result;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}
