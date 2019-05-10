#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
  int value;
  ListNode* next;
};
struct ListNode* insert_node(int data)
{
   struct ListNode* temp = new ListNode;
   temp->value = data;
   temp->next=NULL;
   return temp;
};

class Solution
{
   public:
   void deleteNode(ListNode* Node)
    {
      struct ListNode* temp = Node->next;
      Node->value = temp->value;
      Node->next = temp->next;
      delete(temp);
   }
};
void printlinklist(struct ListNode* head_ref)
{
   struct ListNode* temp=head_ref;
   cout<<"["<<" ";
   while(temp!=NULL)
   {
     cout<<temp->value<<" ";
     temp=temp->next;
   }
  cout<<"]";
  cout<<endl;
}


int main()
{
   struct ListNode* temp = insert_node(1);
   temp->next = insert_node(2);
   temp->next->next = insert_node(3);
   temp->next->next->next = insert_node(4);
   Solution s;
   s.deleteNode(temp->next->next);
   printlinklist(temp);

   return 0;
}
