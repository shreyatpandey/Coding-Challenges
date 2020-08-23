/* FInding the maximum depth of the binary tree */

#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int value;
  struct TreeNode* right;
  struct TreeNode* left;
};
struct TreeNode* insert_node(int data)
{
  struct TreeNode* temp = new TreeNode;
  temp->value = data;
  temp->right = NULL;
  temp->left = NULL;
  return temp;
};


class Solution
{
    public:
    int maximumdepth(TreeNode* root)
    {
     
       if(root == NULL)
       return 0;

    
      int left_ht_tree = maximumdepth(root->left);
        int right_ht_tree = maximumdepth(root->right);
       
        return (max(left_ht_tree+1,right_ht_tree+1));      
    }

};


int main()
{
   struct TreeNode* temp = insert_node(1);
   temp->left = insert_node(2);
   temp->right = insert_node(3);
   temp->left->left = insert_node(4);
   temp->left->right = insert_node(5);
   Solution s;
   int result_maximum_height = s.maximumdepth(temp);
   cout<<"Maximum_height:"<<result_maximum_height<<endl;

   return 0;

}
