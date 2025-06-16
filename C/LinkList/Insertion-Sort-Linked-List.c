#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

ListNode* insertionSortList(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }

    ListNode* dummy = (ListNode*)malloc(sizeof(ListNode));
    dummy->val = 0;
    dummy->next = NULL;

    ListNode* current = head;
    while (current) {
        ListNode* prev = dummy;
        ListNode* next = current->next;

        // Find the correct position to insert the current node
        while (prev->next && prev->next->val < current->val) {
            prev = prev->next;
        }

        // Insert the current node into the sorted list
        current->next = prev->next;
        prev->next = current;

        // Move to the next node
        current = next;
    }

    ListNode* sortedHead = dummy->next;
    free(dummy);
    return sortedHead;
}

// Helper functions to create and print the linked list
ListNode* createNode(int val) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void printList(ListNode* head) {
    while (head) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // Example usage
    ListNode* head = createNode(4);
    head->next = createNode(2);
    head->next->next = createNode(1);
    head->next->next->next = createNode(3);

    printf("Original list: \n");
    printList(head);

    head = insertionSortList(head);

    printf("Sorted list: \n");
    printList(head);

    return 0;
}
