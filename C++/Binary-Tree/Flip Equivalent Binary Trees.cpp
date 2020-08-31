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
 //Approach-1: Simple Recursion
 //TC: O(min(N1,N2))
 //SC: O(min(H1,H2))
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if( root1 == NULL  &&  root2 == NULL )
            return true;
        if( root1 == NULL  ||  root2 == NULL  ||  root1->val != root2->val )
            return false;
        if( flipEquiv( root1->left, root2->left ) && flipEquiv( root1->right, root2->right ) )
            return true;
        swap( root1->left, root1->right );
        return flipEquiv( root1->left, root2->left ) && flipEquiv( root1->right, root2->right );
        
    }
};
