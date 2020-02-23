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
    private:
        vector<int>storevalues ;
        void InorderTraversal(TreeNode* root) ;
public:
    int kthSmallest(TreeNode* root, int k) { 
        InorderTraversal (root ) ;
        return storevalues [k-1] ;
        
    }
};
void Solution :: InorderTraversal(TreeNode* root)
{
    if ( root == NULL )
        return ;
    if ( root->left != NULL)
        InorderTraversal ( root->left) ;
    storevalues.emplace_back( root->val ) ;
    if ( root->right != NULL )
        InorderTraversal (  root->right) ;
    
}
