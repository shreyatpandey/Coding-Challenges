#include<bits/stdc++.h>
using namespace std;

struct Node
{
  int value;
  Node *next;
};

class Solution
{
  public:
   void reverselinklist(struct Node **head_ref)
  {
    struct Node* previous = NULL;/*refers_to_last_element*/
    struct Node* current = *head_ref;
    struct Node* temp;
    while(current != NULL)
   {
     temp = (current)->next;
     current->next = previous;
     previous = current;
     current = temp;
   }
  *head_ref = previous;
     
  }

  struct Node* insert_node(int value)
  {
     struct Node* temp = new Node;
     temp->value = value;
     temp->next = NULL;
     return temp;

   }
  int count_node(struct Node* head_ref)
  {
    int count = 0;
    while(head_ref != NULL)
   {
     count += 1;
     head_ref = head_ref->next;
     }
   return count;
  }


  void print_link_list(struct Node* head_ref,int count)
  {
    cout<<"[";
    int iterator = 0;
    while(head_ref!=NULL)
   {
     cout<<head_ref->value;
     if( iterator != count -1 )
     {	cout<<","; }
     iterator += 1;
     head_ref = head_ref->next;
    }
   cout<<"]"<<endl;
  }
    

};



int main()
{
  Solution s;
  struct Node* create_node = s.insert_node(4);
  create_node->next = s.insert_node(5);
  create_node->next->next = s.insert_node(6);
  create_node->next->next->next = s.insert_node(2); 
  int number_of_nodes = s.count_node(create_node);  
  cout<<"Original_List:"<<endl;
  s.print_link_list(create_node,number_of_nodes); 
  cout<<"Reverse_List:"<<endl;
  s.reverselinklist(&create_node);
  s.print_link_list(create_node,number_of_nodes);  

  return 0;
} 
