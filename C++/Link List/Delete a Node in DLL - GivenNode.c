#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int Val;
    struct Node* next;
    struct Node* prev;
}Node_t;

void appendNode(Node_t** head_ref,int Value)
{
    Node_t *newNode = (Node_t*)malloc(sizeof(Node_t));
    newNode->Val = Value;
    newNode->next = NULL;
    newNode->prev = NULL;
    if(*head_ref == NULL)
    {
        *head_ref = newNode;
    }
    else
    {
        Node_t* current = *head_ref;
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
    return;
}

void DeleteNodeDLL(Node_t** head,Node_t* input)
{
    /* if the head node itself has to be deleted*/
    if(*head == input)
    {
        *head = input->next;
    }
    
    /*if the input is not last node*/
    if(input->next != NULL)
    {
        input->next->prev = input->prev;
    }
    /*if the input is not the first node*/
    if(input->prev != NULL)
    {
        input->prev->next = input->next;     
    }
    free(input);
    return;
}

void printNode(Node_t* head_ref)
{
    Node_t* current = head_ref;
    while(current != NULL)
    {
        printf("%d",current->Val);
        printf(" ");
        current = current->next;
    }
    printf("\n");
}

int main()
{
    Node_t *head = NULL;
    appendNode(&head,10);
    appendNode(&head,5);
    appendNode(&head,20);
    printf("|---Appending Node ---|\n");
    printNode(head);
    
    
    printf("|---Delete a Node ---|\n");
    DeleteNodeDLL(&head,head->next);
    printNode(head);
    
    printf("|---Delete Head Node ---|\n");
    DeleteNodeDLL(&head, head);
    printNode(head);
    

    return 0;
}
