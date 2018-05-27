#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
  int value;
  struct ListNode* right;
  struct ListNode* left;
};
struct ListNode* insert_node(int data)
{
  struct ListNode* temp = new ListNode;
  temp->value = data;
  temp->right = NULL;
  temp->left = NULL;
  return temp;
};
int height(struct ListNode* root)
{
   if(root == NULL)
   return 0;
  
   int left_ht_tree = height(root->left);
   int right_ht_tree = height(root->right);
   
   if(left_ht_tree > right_ht_tree)
    return(left_ht_tree + 1);
  else
   return(right_ht_tree + 1);
}
void printgivenlevel(struct ListNode* root,int height,int root_level)
{
  if(root == NULL)
  return ;
  if(height == root_level)
  cout<<root->value<<endl;
  if(height>1)
  {
    printgivenlevel(root->left,height,root_level + 1);
    printgivenlevel(root->right,height,root_level + 1);
  }
}
void printlevelOrder(struct ListNode* root)
{
  int height_hold = height(root);
  size_t i=1;
  while(i <=height_hold)
  {
    printgivenlevel(root,i,1);
   i+=1;
  }
}




int main()
{
  struct ListNode* temp=insert_node(1);
  temp->right = insert_node(2);
  temp->left = insert_node(3);
  temp->right->left = insert_node(4);
  temp->right->right = insert_node(5);
  printlevelOrder(temp);

 return 0;
}
