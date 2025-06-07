#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
    struct node *triplenext;
};

// Helper to update all triplenext pointers in the list
void update_triplenext(struct node *head) {
    struct node *curr = head;
    while (curr) {
        struct node *temp = curr;
        for (int i = 0; i < 3 && temp; ++i) {
            temp = temp->next;
        }
        curr->triplenext = temp;
        curr = curr->next;
    }
}

// Append node at end
void append(struct node **head, int value) {
    struct node *new_node = (struct  node *)malloc(sizeof(struct node));
    new_node->value = value;
    new_node->next = NULL;
    new_node->triplenext = NULL;
    if (!*head) {
        *head = new_node;
    } else {
        struct node *curr = *head;
        while (curr->next) curr = curr->next;
        curr->next = new_node;
    }
    update_triplenext(*head);
}

// Delete first node with given value
void delete(struct node **head, int value) {
    struct node *curr = *head, *prev = NULL;
    while (curr) {
        if (curr->value == value) {
            if (prev) prev->next = curr->next;
            else *head = curr->next;
            free(curr);
            update_triplenext(*head);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

void print_list(struct node *head) {
    struct node *curr = head;
    int idx = 0;
    while (curr) {
        printf("Node %d: value=%d, next=%p, triplenext=%p", idx, curr->value, (void*)curr->next, (void*)curr->triplenext);
        if (curr->triplenext)
            printf(" (triplenext value=%d)", curr->triplenext->value);
        printf("\n");
        curr = curr->next;
        idx++;
    }
}
int main () {
    struct node *head = NULL;
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    print_list(head);

    delete(&head, 2);
    printf("\nAfter deleting 2:\n");
    print_list(head);

    delete(&head, 10);
    printf("\nAfter trying to delete 10 (not found):\n");
    print_list(head);
    
    return 0;
}