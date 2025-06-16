// DeleteMiddleNode.c
// C program to delete the middle node of a singly linked list
#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to append a node at the end
void appendNode(Node** head_ref, int new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    Node* last = *head_ref;
    while (last->next != NULL) last = last->next;
    last->next = new_node;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to delete the middle node
void deleteMiddleNode(Node** head_ref) {
    if (*head_ref == NULL || (*head_ref)->next == NULL) {
        // List is empty or has only one node
        return;
    }
    Node *slow = *head_ref, *fast = *head_ref;
    Node *prev = NULL;
    while (fast && fast->next) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    // slow is at the middle node, prev is before it
    prev->next = slow->next;
    free(slow);
}

int main() {
    Node* head = NULL;
    // Example: 1->2->3->4->5
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);
    appendNode(&head, 5);
    printf("Original list: ");
    printList(head);
    deleteMiddleNode(&head);
    printf("After deleting middle node: ");
    printList(head);
    // Free the list
    while (head) {
        Node* tmp = head;
        head = head->next;
        free(tmp);
    }
    return 0;
}
