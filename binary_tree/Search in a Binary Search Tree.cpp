/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL)
            return NULL;
        if(root->val == val)
            return root;
        if(root->val > val) /*search in left side of tree */
            return searchBST(root->left,val);
        if(root->val < val)  /*search in right side of tree*/
            return searchBST(root->right,val);
        return NULL;
    }
};
