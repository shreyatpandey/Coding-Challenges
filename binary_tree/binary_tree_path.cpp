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
    vector<string> binaryTreePaths(TreeNode* root) {
     vector<string> result;
        if(!root)
            return result;
        if(!root->left && !root->right){
            result.push_back( to_string(root->val) );
            return result;
        }
        vector<string> leftPaths = binaryTreePaths(root->left);
        vector<string> rightPaths = binaryTreePaths(root->right);
        for(auto l : leftPaths)
            result.push_back( to_string(root->val) + "->" + l );
        for(auto r : rightPaths)
            result.push_back( to_string(root->val) + "->" + r );
        return result;
        
    }
};
