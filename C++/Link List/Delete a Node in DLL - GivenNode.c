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

/* Delete a node given node only*/
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

/* Delete a node given only value */
void DeleteNodeDLLGivenValue(Node_t **head, int deleteValue)
{
    Node_t *previous = NULL;
    Node_t* current = *head;
   /*if the head itself has to be deleted*/
   if(current!= NULL && current->Val == deleteValue)
   {
       Node_t* temp = current;
       current = temp->next;
       free(temp);
       *head = current;
   }
   else
   {
       while(current != NULL && current->Val != deleteValue)
       {
           current = current->next;
       }
       current->prev->next = current->next;
       if(current->next!= NULL)
       {
           current->next->prev = current->prev;
       }
       free(current);
   }
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

    // DeleteNodeDLLGivenValue(&head,5);
    // DeleteNodeDLLGivenValue(&head, 10);
    
    return 0;
}
