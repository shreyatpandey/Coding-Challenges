/*Given a binary tree, determine if it is height-balanced.
For this problem, a height-balanced binary tree is defined as:
A binary tree in which the depth of the two subtrees of every node never differ by more than 1.
Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
*/

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
    bool isBalanced(TreeNode* root) {
        return (height_difference(root)!=-1);
        
    }
    private:
        int height_difference(TreeNode* root)
        {
            if(root == NULL)
                return 0;
            int left_tree_height = height_difference(root->left);
            if(left_tree_height == -1)
                return -1;
            
            int right_tree_height = height_difference(root->right);
            if(right_tree_height == -1)
                return -1;
            
            if(abs(left_tree_height - right_tree_height)>1)
                return -1;
            
            return(max(left_tree_height,right_tree_height)+1);
            
        }
};
