/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*Min/Max Solution */
class Solution {
     bool bstutil(TreeNode *root,TreeNode *l,TreeNode *r)
     {
        if(root==NULL)
            return true;
     if(l!=NULL && l->val>=root->val)
         return false;
    if(r!=NULL && r->val <= root->val)
        return false;
     if(   bstutil(root->left,l,root)&& bstutil(root->right,root,r))
        return true;
    return false;
}
    public:
    bool isValidBST(TreeNode* root) {
         return bstutil(root,NULL,NULL);
    }
};
