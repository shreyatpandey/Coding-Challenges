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
void right_side_view(vector<int>&nums,TreeNode* root)
     {
       if(root == NULL)
       return ;
       else if(root->right!=NULL)
       {
         nums.push_back(root->value);
         right_side_view(nums,root->right);
         }
       else
      {
         nums.push_back(root->value);
         right_side_view(nums,root->left);
       }
     }


class Solution
{
   public:
    vector<int>rightsideview(TreeNode* root)
    {
       vector<int>rightview;
       right_side_view(rightview,root);       

    return rightview;
   }
};

 
int main()
{   Solution s;
   struct TreeNode* temp = insert_node(1);
   temp->left = insert_node(2);
   temp->right = insert_node(3);
   temp->left->right = insert_node(5);
   temp->right->right = insert_node(4);
   
   vector<int>result = s.rightsideview(temp);
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


