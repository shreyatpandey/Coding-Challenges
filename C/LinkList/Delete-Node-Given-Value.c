#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void deleteNode(Node** head, int value) {
    Node* temp = *head;
    Node* prev = NULL;

    if (*head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == value) {
        *head = temp->next; // Changed head
        free(temp);         // free old head
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL ) {
        if (temp->data == value) {
            if (prev) prev->next = temp->next;
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void printList(Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

void append(Node** head_ref, int new_data) {
    Node* new_node = createNode(new_data);
    Node* last = *head_ref;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

int main() 
{
    Node* head = NULL;

    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);

    printf("Original List: ");
    printList(head);

    deleteNode(&head, 3);
    printf("After Deleting 3: ");
    printList(head);

    deleteNode(&head, 1);
    printf("After Deleting 1: ");
    printList(head);

    deleteNode(&head, 5);
    printf("After Deleting 5: ");
    printList(head);

    deleteNode(&head, 10);
    printf("After Deleting 10: ");
    printList(head);

    return 0;
}