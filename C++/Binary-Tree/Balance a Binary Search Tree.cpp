/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    private:
        void InOrderTraversal(TreeNode* root,vector<int>&Input);
        TreeNode* ConstructBST(int start,int end,vector<int>&nums);
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>Input;
        InOrderTraversal(root,Input);
        /*Convert a sorted array into Binary Search Tree*/
        TreeNode* BST = ConstructBST(0,Input.size()-1,Input);
        return BST;
    }
};

TreeNode* Solution::ConstructBST(int start,int end,vector<int>&nums)
{
    if ( end<start)
        return NULL;
    int mid = start +(end-start)/2;
    TreeNode* temp = new TreeNode(nums[mid]);
    if ( start<=mid-1)
        temp->left = ConstructBST(start,mid-1,nums);
    if(end>=mid+1)
        temp->right = ConstructBST(mid+1,end,nums);
    return temp;
}

void Solution::InOrderTraversal(TreeNode* root,vector<int>&Input)
{
    if (!root)
        return ;
    InOrderTraversal(root->left,Input);
    Input.emplace_back(root->val);
    InOrderTraversal(root->right,Input);
}
