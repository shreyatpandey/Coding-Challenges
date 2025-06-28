#include <stdio.h>
#include <stdlib.h>

// Node structure for circular linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Main function to insert into sorted circular linked list
Node* insertSorted(Node* head, int data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) return head;
    
    // Case 1: Empty list
    if (head == NULL) {
        newNode->next = newNode; // Point to itself
        return newNode;
    }
    
    // Case 2: Single node
    if (head->next == head) {
        newNode->next = head;
        head->next = newNode;
        // Return smaller value as head
        return (data < head->data) ? newNode : head;
    }
    
    // Case 3: Multiple nodes - find insertion point
    Node* current = head;
    Node* next_node = head->next;
    
    // Traverse the list to find insertion point
    do {
        // Normal case: insert between current and next
        if (current->data <= data && data <= next_node->data) {
            current->next = newNode;
            newNode->next = next_node;
            return head;
        }
        
        // Wraparound case: current > next (end of sorted sequence)
        if (current->data > next_node->data) {
            // Insert if data >= max value OR data <= min value
            if (data >= current->data || data <= next_node->data) {
                current->next = newNode;
                newNode->next = next_node;
                return head;
            }
        }
        
        current = next_node;
        next_node = next_node->next;
    } while (current != head);
    
    // If we reach here, all nodes have same value
    // Insert after head
    newNode->next = head->next;
    head->next = newNode;
    return head;
}

// Function to print the circular list
void printList(Node* head) {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }
    
    Node* temp = head;
    printf("List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to %d)\n", head->data);
}

// Test function
void testInsertion() {
    Node* head = NULL;
    
    printf("=== Testing Sorted Circular Linked List Insertion ===\n\n");
    
    // Test insertions
    int values[] = {3, 1, 4, 1, 5, 9, 2, 6};
    int size = sizeof(values) / sizeof(values[0]);
    
    for (int i = 0; i < size; i++) {
        printf("Inserting %d:\n", values[i]);
        head = insertSorted(head, values[i]);
        printList(head);
        printf("\n");
    }
    
    // Clean up memory
    if (head != NULL) {
        Node* current = head->next;
        while (current != head) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
        free(head);
    }
}

int main() {
    testInsertion();
    return 0;
}
