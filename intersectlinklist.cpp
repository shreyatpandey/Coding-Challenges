#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
  int data;
  struct ListNode *next;
 };

struct ListNode *insert(int data)
{
  struct ListNode *temp = new ListNode;
  temp->data = data;
  temp->next = NULL;
  return temp;
};
 
int numberofnodes(struct ListNode* head)
{
  int c=0;
  struct ListNode *start = head;
  while(start!=NULL)
  {
    c++;
    start = start->next;
   
   }
 return c;
}



class Solution
{
  public:
   ListNode *getIntersectionNode(ListNode *headA,ListNode *headB)
   { 
     struct ListNode* List1=headA;
     struct ListNode* List2 = headB;
     struct ListNode* current = NULL;
     int no1 = numberofnodes(headA);
     int no2= numberofnodes(headB);
     if(no1>no2)
     {
        int d = no1-no2;
        for(int i=0;i<d;i++)
         {
           if (List1 == NULL)
           return NULL;
           else
           List1 = List1->next;
         }
       while(List1!=NULL && List2!=NULL)
      {
        if(List1 == List2)
        {
           current = List1;
            return current;
           List1 = List1->next;
           List2 = List2->next;
         }
       }
     }
    if(no2>no1)
    {
         int d = no2 - no1;
         for(int i=0;i<d;i++)
         {
            if(List2 == NULL)
            return NULL;
            else
            List2 = List2->next;
          }
        while(List1!=NULL && List2!=NULL)
       {
              if(List1 == List2)
              {
                 current = List2;
                 return current;
                 List1=List1->next;
                 List2=List2->next;
               }
        }
      }
    }
};

/*
void print(struct ListNode* headA)
{
   struct ListNode* current = headA;
    while(current!=NULL)
    {
      cout<<current->data<<" ";
      current=current->next;
    }
   cout<<endl;
}


int main()
{
  struct ListNode* new_node1 = insert(10);
  new_node1->next = insert(4);
  new_node1->next->next = insert(5);
  print(new_node1);
  struct ListNode* new_node2 = insert(4);
  new_node2->next = insert(5);
  print(new_node2);

  Solution s;
  struct ListNode* result = s.getIntersectionNode(new_node1,new_node2);
  print(result);
  return 0;


}
*/
  


