#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void removeDuplicates(Node* head) {
    Node* current = head;
    Node* runner = head;
    while (current != NULL) {
        while (runner->next != NULL) {
            if (runner->next->data == current->data) {
                Node* temp = runner->next;
                runner->next = runner->next->next;
                free(temp);
            } else {
                runner = runner->next;
            }
        }
        runner = current;
        current = current->next;
    }
}

void appendNode(Node** head_ref, int new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

// Helper function to print the list
void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    appendNode(&head, 1);
    appendNode(&head, 1);
    appendNode(&head, 1);
    appendNode(&head, 1);
    appendNode(&head, 1);
    appendNode(&head, 1);

    printf("Original list: ");
    printList(head);

    removeDuplicates(head);

    printf("List after removing duplicates: ");
    printList(head);

    // Test with another list
    head = NULL;
    printf("Testing with another list:\n");
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 2);
    appendNode(&head, 3);

    printf("Original list: ");
    printList(head);

    removeDuplicates(head);

    printf("List after removing duplicates: ");
    printList(head);

    // Free the list
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
