#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
   int value;
   struct TreeNode* left;
   struct TreeNode* right;
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
   private:
   bool check_leaf(TreeNode* root)
   {
    if(root == NULL)
     return false;
    if(root->left == NULL && root->right == NULL)
    return true;

     return false;
    }
   public:
    int sumofLeftLeaves(TreeNode* root)
     {
         int result_count = 0;
        
         if(root!=NULL)
      {
         if(check_leaf(root->left))
          {
            result_count+=root->left->value;
           }
         else
         {
           result_count+=sumofLeftLeaves(root->left);
         }
      
         result_count+=sumofLeftLeaves(root->right);
    }
    return result_count;
 }

      
};


int main()
{
  Solution s;
  struct TreeNode* temp = insert_node(3);
 temp->left = insert_node(9);
 temp->right = insert_node(20);
 temp->right->left = insert_node(15);
 temp->right->right = insert_node(7);
 cout<<"Sum_two_leaves:"<<s.sumofLeftLeaves(temp)<<endl;
 


  return 0;
}
