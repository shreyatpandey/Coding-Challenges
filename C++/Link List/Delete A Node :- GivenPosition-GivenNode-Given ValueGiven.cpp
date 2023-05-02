#include<iostream>
using namespace std;

class Node
{
    public:
      int Value;
       Node* next;
        Node(int val)
        {
            Value = val;
            next = nullptr;
        }
};
void AppendNode(Node** head,int Value)
{
    Node* newNode = new Node(Value);
    if ( *head == nullptr)
    {
      *head = newNode;
    }
    else
    {
       Node* current = *head;
       while(current->next != NULL)
       {
          current = current->next;
       }
       current->next = newNode;
    }
}
/* When only position is given*/
void DeleteNodeAtParticularPos(Node** head, int position)
{
    if ( position == 0)
    {
        auto helper = *head;
        *head = helper->next;
        delete(helper);
    }
    else
    {
        auto current = *head;
        for(int i=1;i<position;i++)
        {
            current = current->next;
        }
        auto helper = current->next;
        current->next = helper->next;
        delete(helper);
    }
}

/*When only value is given*/
void DeleteNodeForGivenValue(Node** head, int Value)
{
   Node* current = *head;
   Node* previous = nullptr;
   if(current != nullptr && current->Value == Value)
   {
     *head = current->next;
     delete(current);
     return;
   }
    else
    {
      while(current!=nullptr && current->Value != Value)
      { 
          previous = current;
          current = current->next;
      }
      previous->next = current->next;
      delete(current);
    }
}

/*when only node is given*/
void DeleteNodeForGivenNode(Node* deleteNode)
{
   deleteNode->next = deleteNode->next->next;
   deleteNode->Value = deleteNode->next->Value;
}
        

void PrintNode(Node* head)
{
    Node* current = head;
    while (current != nullptr)
    {
       cout<<current->Value <<endl;
       current = current->next;
    }
}
int main()
{
    Node* head = nullptr;
    AppendNode(&head,10);
    AppendNode(&head,50);
    AppendNode(&head,60);
    cout<<" Adding Node in the Link List:"<<endl;
    PrintNode(head);
    DeleteNodeAtParticularPos(&head,2);
    
    cout<<"Deleting nodes from the link list:"<<endl;
    PrintNode(head);
    return 0;
}
