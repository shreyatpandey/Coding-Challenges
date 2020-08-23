/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
   */

class Solution {
    protected:
        int getInorderIndex(vector<int>&inorder,int start,int end,int data);
        TreeNode* helperfunction(vector<int>&preorder,vector<int>&inorder,int inorderstart,int inorderend);
          int preindexroot = 0;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
       if(preorder.size() == 0 && inorder.size() == 0)
           return NULL;
        return (helperfunction(preorder,inorder,0,inorder.size()-1));
    }
};

TreeNode* Solution::helperfunction(vector<int>&preorder,vector<int>&inorder,int inorderstart,int inorderend)
{
    if(inorderstart> inorderend)
    {
        return NULL;
    }
    TreeNode* root_node = new TreeNode(preorder[preindexroot]);
    preindexroot++;
    if(inorderstart == inorderend)
    {
        return root_node;
    }
    int indexininorder = getInorderIndex(inorder,inorderstart,inorderend,root_node->val);
    root_node->left = helperfunction(preorder,inorder,inorderstart,indexininorder-1);
    root_node->right = helperfunction(preorder,inorder,indexininorder+1,inorderend);
    return root_node;
}

int Solution::getInorderIndex(vector<int>&inorder,int start,int end,int data)
{
    for(int i=start;i<=end;i++)
    {
        if(inorder[i]==data)
            return i;
    }
    return -1;
}
