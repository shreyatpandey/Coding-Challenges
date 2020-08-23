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
        bool has_sum(TreeNode* root, int sum)
        {
           if (root == NULL)
               return false;
             sum -= root->val;
            if ((root->left==NULL) && (root->right == NULL))
            {
                return (sum == 0);
            }
            return (has_sum(root->left,sum) || has_sum(root->right,sum));
            
        }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return false;
        return (has_sum(root,sum));
        
    }
};
