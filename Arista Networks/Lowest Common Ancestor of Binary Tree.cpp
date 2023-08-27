/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// TC:- O(n) where n is the total number of nodes in tree
// SC:- O(N) where n is the total number of nodes indicating the recursion stack

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if ( root == NULL )
            return NULL;
        if ( root == p || root == q)
            return root;
        root->left = lowestCommonAncestor( root->left, p, q);
        root->right = lowestCommonAncestor(root->right,p,q);
        if ( root->left != NULL && root->right != NULL)
            return root;
        else
            return ( root->left ? root->left : root->right);
        
    }
};
