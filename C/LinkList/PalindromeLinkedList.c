#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Helper to reverse a linked list in-place and return new head
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    while (curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Function to check if linked list is palindrome in O(1) space
int isPalindrome(Node* head) {
    if (!head || !head->next) return 1;
    // Find middle (slow will be at mid)
    Node *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // Reverse second half
    Node* second = reverseList(slow->next);
    Node* first = head;
    Node* copy_second = second; // To restore later
    int palindrome = 1;
    while (second) {
        if (first->data != second->data) {
            palindrome = 0;
            return palindrome; // Not a palindrome
        }
        first = first->next;
        second = second->next;
    }
    return palindrome;
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
    // Example: 1->2->3->2->1 is palindrome
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 2);
    appendNode(&head, 1);
    printf("List: ");
    printList(head);
    if (isPalindrome(head))
        printf("The list is a palindrome.\n");
    else
        printf("The list is not a palindrome.\n");

    // Example: 1->2->3 is not a palindrome
    Node* head2 = NULL; 
    appendNode(&head2, 1);
    appendNode(&head2, 2);
    appendNode(&head2, 3);
    printf("List: ");
    printList(head2);
    if (isPalindrome(head2))
        printf("The list is a palindrome.\n");
    else
        printf("The list is not a palindrome.\n");

    // Free the list
    while (head) {
        Node* tmp = head;
        head = head->next;
        free(tmp);
    }
    return 0;
}
