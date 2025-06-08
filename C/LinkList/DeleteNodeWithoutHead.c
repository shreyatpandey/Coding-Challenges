// Delete a node in a singly linked list without access to the head node
// Only possible if the node to be deleted is not the last node
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Deletes the given node (except the last node)
void deleteNodeWithoutHead(Node* node) {
    if (node == NULL || node->next == NULL) {
        // Cannot delete the last node or a null node
        return;
    }
    Node* temp = node->next;
    node->data = temp->data;
    node->next = temp->next;
    free(temp);
}

// Helper to append node at end
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

// Helper to print the list
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
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);
    appendNode(&head, 5);
    printf("Original list: ");
    printList(head);

    // Let's delete the node with value 3 (without head)
    Node* node = head->next->next; // 3rd node
    deleteNodeWithoutHead(node);
    printf("After deleting node with value 3 (without head): ");
    printList(head);

    // Free the list
    while (head) {
        Node* tmp = head;
        head = head->next;
        free(tmp);
    }
    return 0;
}
