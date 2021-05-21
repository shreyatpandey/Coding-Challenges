#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int Value;
    Node* next;
    Node(int Val):Value(Val),next(nullptr){};
};
void AddNode(Node**Headref,int Val)
{
    Node* new_node = new Node(Val);
    new_node->Value = Val;
    new_node->next = nullptr;
     if (*Headref == NULL) 
    {
        *Headref = new_node; 
    } 
    else 
    {          
        Node* temp1 = *Headref;
        while ( temp1->next != NULL ) temp1 = temp1->next ;
        temp1->next = new_node ;
    } 
}
void PrintNode(Node* head)
{
    while ( head != nullptr)
    {
        cout<<"Node->Val:"<<head->Value<<endl;
        head = head->next;
    }
}

int main()
{
    Node* head = nullptr;
    AddNode(&head,10);
    AddNode(&head,20);
    AddNode(&head,30);
    PrintNode(head);

    return 0;
}
