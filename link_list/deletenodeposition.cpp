/*Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
        
    }
};

/* New way approach */
#include <stdio.h> 
#include <stdlib.h> 
  
// A linked list node 
struct Node 
{ 
    int data; 
    struct Node *next; 
}; 
  
/* Given a reference (pointer to pointer) to the head of a list 
   and an int, inserts a new node on the front of the list. */
void push(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
    new_node->data  = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref)    = new_node; 
} 
  struct Node* ReturnPreviousNode(struct Node* head,int key)
{
    struct Node* temp = head;
    struct Node* previous = NULL;
    while(temp)
    {
        previous = temp;
        if(temp->next->data == key)
        {
            return previous;
        }
        temp = temp->next;
    }
    return NULL;
}
  
  
void deleteNode(struct Node* head,int key)
{
    struct Node* Result = ReturnPreviousNode(head,key);
    if ( Result == NULL)
        return NULL;
     Result->next = Result->next->next;
    
}

// This function prints contents of linked list starting from  
// the given node 
void printList(struct Node *node) 
{ 
    while (node != NULL) 
    { 
        printf(" %d ", node->data); 
        node = node->next; 
    } 
} 
  
/* Drier program to test above functions*/
int main() 
{ 
    /* Start with the empty list */
    struct Node* head = NULL; 
  
    push(&head, 7); 
    push(&head, 1); 
    push(&head, 3); 
    push(&head, 2); 
  
    puts("Created Linked List: "); 
    printList(head);
    puts("\nDelete Node Linked List with key 1: ");
    deleteNode(head,1);
    printList(head); 
    return 0; 
}
