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
   /* new_node->Value = Val; Dont require this as constructor of node initializes value and nullptr
    new_node->next = nullptr;
    */
     if (*Headref == NULL) 
    {
        *Headref = new_node; 
    } 
    /* made-one small mistake, used Headref == null instead of *Headref == null , this can also cause problem */
    else 
    {          
        Node* temp1 = *Headref;
        while ( temp1->next != NULL ) temp1 = temp1->next ;
        /* 
        what if temp1 != Null is written? In that case the issue would be regarding segmentation fault, 
        temp1= temp1->next would cause to access nullptr
        */
        temp1->next = new_node ;
        /* for the if condition ( temp1 != nullptr) at line 28 would cause the problem , as nullptr accessing next is not feasible*/
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
