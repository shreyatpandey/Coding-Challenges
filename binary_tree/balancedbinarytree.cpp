/*Given a binary tree, determine if it is height-balanced.
For this problem, a height-balanced binary tree is defined as:
A binary tree in which the depth of the two subtrees of every node never differ by more than 1.
Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
*/

#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
 };
struct TreeNode* insert_node(int data)
{
   struct TreeNode* new_node = new TreeNode;
   new_node->val = data;
   new_node->right = NULL;
   new_node->left =NULL;
   return new_node;
};
int height_difference(TreeNode* root)
{
  if(root == NULL)
  return 0;

  int left_ht_tree = height_difference(root->left);
  if(left_ht_tree == -1)
  return -1;  
   
int right_ht_tree = height_difference(root->right);
  if(right_ht_tree == -1)
  return -1;

if(abs(left_ht_tree - right_ht_tree)>1)
  return -1;

return (max(left_ht_tree,right_ht_tree)+1);
}


class Solution
{
   public:
    bool isBalanced(TreeNode* root)
   {
     return (height_difference(root)!=-1);    

  }
};
int main()
{
  struct TreeNode* input_node = insert_node(1);
  input_node->left = insert_node(2);
  input_node->right = insert_node(2);
  input_node->left->left = insert_node(3);
  input_node->left->right = insert_node(3);
  input_node->left->left->left = insert_node(4);
  input_node->left->left->right = insert_node(4);
  Solution s;
  bool result;
  result =s.isBalanced(input_node);
  cout<<"Result:"<<boolalpha<<result<<endl;
  return 0;
}

