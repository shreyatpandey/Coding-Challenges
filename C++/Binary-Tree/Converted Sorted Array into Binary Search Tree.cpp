/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//TC:- O(N) where N is the number of nodes in the tree
//SC:- O(H) for recursion stack where H is the height of the tree

class Solution {
    private:
    TreeNode* construct_BST(vector<int>&nums,int left,int right)
    {
        int mid_value = left + (right-left)/2;
        TreeNode* root = new TreeNode(nums[mid_value]);
        
        if( left <= mid_value-1) //if this is not there, time limit exceeded
            root->left = construct_BST(nums,left,mid_value-1);
        
        if(mid_value + 1 <=right)
            root->right = construct_BST(nums,mid_value+1,right);
        
        cout<<"root->val:"<<root->val<<endl;
        return root; //return root- error which I made
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0)
            return NULL;
        TreeNode* root = construct_BST(nums,0,nums.size()-1);
        return root;
        
    }
};
