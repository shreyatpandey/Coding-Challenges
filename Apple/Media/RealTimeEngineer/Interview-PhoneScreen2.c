//Interviewer:- LV
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct messageNode
{
    char* timestamp;
    char* sender;
    char* content;
    struct messageNode* next;
}messageNode_t;

typedef struct message
{
    char timestamp[256];
    char sender[256];
    char content[256];
}message_t;

/* implement this API*/
void appendMessageNode(messageNode_t** head, message_t* message)
{
    messageNode_t* newNode = (messageNode_t*)malloc(sizeof(messageNode_t));
    newNode->next = NULL;
    newNode->timestamp = message->timestamp;
    newNode->sender = message->sender;
    newNode->content = message->content;
    
    if(*head == NULL)
    {
        *head = newNode;
        return;
    }
    messageNode_t* current = *head;
    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
}

/* void updateMessage
   implement this API
*/
void updateMessage(messageNode_t* head,message_t* sampleMessage, char* content)
{
    messageNode_t* current = head;
    while(current)
    {
        if(strcmp(current->sender,sampleMessage->sender) == 0)
        {
            current->sender = content;
        }
        current = current->next;
    }
}

/* void delete Node*/
// I had missed this ** pointer
void deleteNode(messageNode_t** head,message_t* sampleMessage)
{
    messageNode_t* current = * head;
    messageNode_t* previous = NULL;
    // If the head node itself has to be deleted
    if( strcmp(current->timestamp, sampleMessage->timestamp)==0 &&
        strcmp(current->sender, sampleMessage->sender)==0 &&
        strcmp(current->content, sampleMessage->content)==0
      )
    {
       *head = current->next;
       free(current);
       return;
    }
    else
    {
        while(current && !((strcmp(current->timestamp, sampleMessage->timestamp)==0 &&
                            strcmp(current->sender, sampleMessage->sender)==0 &&
                            strcmp(current->content, sampleMessage->content)==0
                            )))
        {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        free(current);
    }
}

/* print Message function*/
void printMessage(messageNode_t* head)
{
    messageNode_t* current = head;
    while(current)
    {
        if(current->content != NULL)
        {
            printf("Timestamp : %s, Sender: %s, Content: %s\n",
                   current->timestamp,
                   current->sender,
                   current->content
                   );
        }
        current = current->next;
    }
}


int main()
{
    message_t sampleMessage1 = { .timestamp = "2023-01-05", 
                                 .sender = "Shail",
                                 .content = "Hello"
                               };
    message_t sampleMessage2 = { .timestamp ="2023-01-06",
                                 .sender = "Purna",
                                 .content = "Bye"
                               };
    message_t sampleMessage3 = { 
                                 .timestamp = "2023-01-06",
                                 .sender = "Sanjeev",
                                 .content = "Received"
                               };
                               
    messageNode_t* head = NULL;
    printf("\n\n----AppendingNode----\n");
    appendMessageNode(&head,&sampleMessage1);
    appendMessageNode(&head,&sampleMessage2);
    appendMessageNode(&head,&sampleMessage3);
    printMessage(head);
    
    printf("\n\n----UpdateMessage----\n");
    updateMessage(head,&sampleMessage2,"Shrey");
    printMessage(head);
    
    printf("\n\n---Deleting head node---\n");
    deleteNode(&head,&sampleMessage1); //delete Head;
    printMessage(head);
    
    printf("\n\n --- Deleting tail node ---\n");
    deleteNode(&head,&sampleMessage3);
    printMessage(head);
    
    return 0;
}
