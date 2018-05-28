/* Number of nodes on the longest path between any leaves of the binary tree */

#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int data;
  struct TreeNode* right;
  struct TreeNode* left;
};
struct TreeNode* insert_node(int value)
{
  struct TreeNode* temp = new TreeNode;
  temp->data = value;
  temp->right = NULL;
  temp->left = NULL;
  return temp;
};

int height(TreeNode* root)
{
  if(root == NULL)
  return 0;
  
  else
  {
    return (1 + max(height(root->left),height(root->right)));
  }
}
  
  

class Solution
{
  public:
  int diameterofBinaryTree(TreeNode* root)
  {
    if (root == NULL)
    return 0;
   
     int left_ht_tree = height(root->left);
     int right_ht_tree = height(root->right);
     
     int left_diameter = diameterofBinaryTree(root->left);
     int right_diameter = diameterofBinaryTree(root->right);
    
     return (max(left_ht_tree + right_ht_tree + 1, max(left_diameter,right_diameter)));
 
   }

};



int main()
{
  struct TreeNode* temp = insert_node(1);
  temp->left = insert_node(2);
  temp->right = insert_node(3);
  temp->left->left = insert_node(4);
  temp->left->left = insert_node(5);
  Solution s;
  int result_diameter = s.diameterofBinaryTree(temp);
  cout<<"Diameter_binary_tree:"<<result_diameter<<endl;  

  return 0;
}

