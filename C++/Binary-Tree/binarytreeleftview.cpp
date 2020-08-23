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
    temp->left = NULL;
    temp->right = NULL;
    return temp;
};
void left_side_view(vector<int>&nums,TreeNode* root)
     {
       if(root == NULL)
       return ;
       else if(root->left!=NULL)
       {
         nums.push_back(root->value);
         left_side_view(nums,root->left);
         }
       else
      {
         nums.push_back(root->value);
         left_side_view(nums,root->right);
       }
     }


class Solution
{
   public:
    vector<int>leftsideview(TreeNode* root)
    {
       vector<int>leftview;
       left_side_view(leftview,root);       

    return leftview;
   }
};

 
int main()
{   Solution s;
   struct TreeNode* temp = insert_node(1);
   temp->left = insert_node(2);
   temp->right = insert_node(3);
   temp->left->right = insert_node(5);
   temp->right->right = insert_node(7);
   temp->right->left = insert_node(6);
   temp->right->right->right = insert_node(8);
   
   vector<int>result = s.leftsideview(temp);
   cout<<"[";
    for(size_t i =0 ;i<result.size();i++)
   {
      cout<<result[i];
       if(!(i == result.size()-1))
       {
          cout<<",";
        }
     }
    cout<<"]";
    cout<<endl;
    return 0;
}


