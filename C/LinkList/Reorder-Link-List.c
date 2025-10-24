#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to create a new node
struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (newNode != NULL) {
        newNode->val = value;
        newNode->next = NULL;
    }
    return newNode;
}

// Function to reverse a linked list
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL, *curr = head, *next = NULL;
    
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}

// Function to find the middle of the linked list
struct ListNode* findMiddle(struct ListNode* head) {
    struct ListNode *slow = head, *fast = head;
    struct ListNode *prev = NULL;
    
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    
    if (prev != NULL) {
        prev->next = NULL;
    }
    
    return slow;
}

// Function to merge two lists in alternating order
void mergeLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *temp1, *temp2;
    
    while (l2 != NULL) {
        temp1 = l1->next;
        temp2 = l2->next;
        
        l1->next = l2;
        l2->next = temp1;
        
        l1 = temp1;
        l2 = temp2;
    }
}

// Main function to reorder the list
void reorderList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return;
    }
    
    // Find the middle of the list
    struct ListNode* middle = findMiddle(head);
    
    // Reverse the second half
    struct ListNode* secondHalf = reverseList(middle);
    
    // Merge the two halves
    mergeLists(head, secondHalf);
}

// Utility function to print the linked list
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

// Main function to test the implementation
int main() {
    // Create a sample linked list: 1->2->3->4->5
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    
    printf("Original List: ");
    printList(head);
    
    reorderList(head);
    
    printf("Reordered List: ");
    printList(head);
    
    return 0;
}
