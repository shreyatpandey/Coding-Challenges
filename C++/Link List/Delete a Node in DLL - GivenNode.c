#include <stdio.h>

typedef struct Node
{
    int Val;
    struct Node* next;
    struct Node* prev;
}Node_t;

void DeleteNodeDLL(Node** head,Node* input)
{
    /* if the head node itself has to be deleted*/
    if(*head == input)
    {
        *head = *input->next;
        return;
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
