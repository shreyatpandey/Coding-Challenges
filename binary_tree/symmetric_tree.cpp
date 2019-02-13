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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        queue<TreeNode *>insert_node;
        insert_node.push(root);
        insert_node.push(root);
        while(!insert_node.empty())
        {
            TreeNode* hold_one = insert_node.front();
            insert_node.pop();
            TreeNode* hold_two = insert_node.front();
            insert_node.pop();
            if( hold_one == NULL && hold_two == NULL)
                continue;
            if(hold_one == NULL && hold_two != NULL || hold_one != NULL && hold_two == NULL)
                return false;
            if(hold_one->val != hold_two->val)
                return false;
            insert_node.push(hold_one->right);
            insert_node.push(hold_two->left);
            insert_node.push(hold_one->left);
            insert_node.push(hold_two->right);
            
            
         }
        return true;
    }       
};
